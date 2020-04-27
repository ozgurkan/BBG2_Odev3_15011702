#include <stdio.h>
#include <stdlib.h>

int AlanUygunmu(int OyunAlani[][50],int en,int boy,int x,int y,int gemiboyu,int gemiyonu){
    int i;
    int kontrol=1;
    int say1=y;
    int say2=x;

    if(gemiyonu==0){    //Geminin y�n� yatay yani 0 ise yaplacak i�lemler
            if(gemiboyu<0){//geminin boyunun 0 dan k���k girilmesi durumunda -1 d�ner.
                kontrol=-1;
            }
            else if(gemiboyu>en){//geminin boyu oyun alan�n�n eninden b�y�kse alan uygun de�il kontrol 0 d�ner.
                kontrol=0;
            }else{//geminin boyu oyun alan�n�n eninden k���k veya e�itse
                for(i=0;i<gemiboyu;i++){//for ile 0 dan geminin boyu kadar d�neriz.
                    if(OyunAlani[x][i+y]==0){//oyun alan�n�n x sat�r ve i+y s�tununu 0 m� diye kontorol ederiz.
                        kontrol=1;//s�f�r ise kontrol 1 dir
                        say1++;//geminin boyu i�in uygun alan var m� kontrol� yap�l�r.
                        if(say1>en){//say1 en den b�y�kse uygun yer yoktur
                            kontrol=0;
                            break;
                        }
                    }else{// e�er oyun alan�na daha �nceden gemi yerle�tiyse 0 d�ner.
                        kontrol=0;
                        break;
                        }
                    }
                }
            }

    else if(gemiyonu==1){//Geminin y�n� d��ey yani 1 ise yaplacak i�lemler
         if(gemiboyu<0){
                kontrol=-1;
            }
            else if(gemiboyu>boy){
                kontrol=0;
            }else{
                for(i=0;i<gemiboyu;i++){
                    if(OyunAlani[i+x][y]==0){
                        kontrol=1;
                        say2++;
                        if(say2>boy){
                            kontrol=0;
                            break;
                        }
                    }else{
                        kontrol=0;
                        break;
                        }
                    }
                }
    }

    //geminin y�n� 0 ve 1 de�ilse yanl�� bilgi uyar�s� i�in -1 d�ner.
    else{
        kontrol=-1;
    }

return kontrol;
}

void GemiYerlestir(int OyunAlani[][50],int x,int y,int gemiboyu,int gemiyonu){
    int i;
    if(gemiyonu==0){//gemi y�n� yatay ise yap�lacak i�lemler
        for(i=0;i<gemiboyu;i++){//gemi boyu kadar d�neriz
            OyunAlani[x][i+y]=gemiboyu;//oyun alan�na geminin boyutunu yazar�z
        }
    }else if(gemiyonu==1){//gemi y�n� d��ey ise yap�lacak i�lemler
        for(i=0;i<gemiboyu;i++){
            OyunAlani[i+x][y]=gemiboyu;
        }
    }
}

int AtisYap(int OyunAlani[][50],int en,int boy,int Atisx,int Atisy){
        if(Atisx>=boy || Atisx<0 || Atisy>=en || Atisy<0){//atisi kontrol edip oyun alan�n�n i�inde at�� yapmas� sa�lan�r.
            printf("Oyun alaninin disinda atis yaptiniz.");
            return -1;//oyun alan�n�n d���ndaysa -1 geri d�nd�r�r.
        }else{
            return OyunAlani[Atisx][Atisy];//oyun alan�n�n i�indeyse o h�credeki de�eri geri d�nd�r�r.
        }
}



int main()
{
    int AlanKontrol;
    int en,boy,i,j;
    int x,y,GemiBoyu,GemiPozisyonu;
    static int OyunAlani[50][50];
    char karakter;
    int AtisYapilanX,AtisYapilanY,Sonuc;

    printf("Oyun alaninin enini girini:");
    scanf("%d",&en);

    printf("Oyun alaninin boyunu girini:");
    scanf("%d",&boy);


    for(i=0;i<boy;i++){
        for(j=0;j<en;j++){
            printf("%2d",OyunAlani[i][j]);
        }
        printf("\n");
    }

    do{
        printf("x,y,boy,yatay(0)/dusey(1)?");
        scanf("%d %d %d %d",&x,&y,&GemiBoyu,&GemiPozisyonu);
        if(x>=boy || x<0 || y>=en || y<0){
            printf("Oyun alaninizin boyutunu gecemezsiniz.\n");
            printf("devam etmek istiyor musunuz: E/H ");
            karakter=getch();
            printf("\n");
        }else{
            AlanKontrol=AlanUygunmu(OyunAlani,en,boy,x,y,GemiBoyu,GemiPozisyonu);
            if(AlanKontrol==1){
                GemiYerlestir(OyunAlani,x,y,GemiBoyu,GemiPozisyonu);
                printf("istenen yere yerlestirildi.\n");
            }else if(AlanKontrol==0){
            printf("Alan uygun degil yerlestirme gerceklesmedi.\n");
            }else{
            printf("Yanlis bir deger girdiniz:\n");
            }

            printf("devam etmek istiyor musunuz: E/H ");
            karakter=getch();
            printf("\n");
        }
    }while(karakter=='E' || karakter=='e');//e girildi�i m�ddet�e gemi yerle�tirme i�mleri yap�l�r.




//At�� yapma i�lemleri ger�ekle�tirilir.

    if(karakter=='h' || karakter=='H'){
            do{
               printf("\n atis koordinatlarini veriniz:");
               scanf("%d %d",&AtisYapilanX,&AtisYapilanY);

                Sonuc=AtisYap(OyunAlani,en,boy,AtisYapilanX,AtisYapilanY);
                if(Sonuc!=-1){
                   printf("\n puaniniz:%d",Sonuc);
                  }
               }while(Sonuc==-1);


            printf("\n Oyun alaninin son hali\n");
             for(i=0;i<boy;i++){
                for(j=0;j<en;j++){
                    printf("%3d",OyunAlani[i][j]);
                    }
                printf("\n");
                }
        }
    return 0;
}
