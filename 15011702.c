#include <stdio.h>
#include <stdlib.h>

int AlanUygunmu(int OyunAlani[][50],int en,int boy,int x,int y,int gemiboyu,int gemiyonu){
    int i;
    int kontrol=1;
    int say1=y;
    int say2=x;

    if(gemiyonu==0){    //Geminin yönü yatay yani 0 ise yaplacak iþlemler
            if(gemiboyu<0){//geminin boyunun 0 dan küçük girilmesi durumunda -1 döner.
                kontrol=-1;
            }
            else if(gemiboyu>en){//geminin boyu oyun alanýnýn eninden büyükse alan uygun deðil kontrol 0 döner.
                kontrol=0;
            }else{//geminin boyu oyun alanýnýn eninden küçük veya eþitse
                for(i=0;i<gemiboyu;i++){//for ile 0 dan geminin boyu kadar döneriz.
                    if(OyunAlani[x][i+y]==0){//oyun alanýnýn x satýr ve i+y sütununu 0 mý diye kontorol ederiz.
                        kontrol=1;//sýfýr ise kontrol 1 dir
                        say1++;//geminin boyu için uygun alan var mý kontrolü yapýlýr.
                        if(say1>en){//say1 en den büyükse uygun yer yoktur
                            kontrol=0;
                            break;
                        }
                    }else{// eðer oyun alanýna daha önceden gemi yerleþtiyse 0 döner.
                        kontrol=0;
                        break;
                        }
                    }
                }
            }

    else if(gemiyonu==1){//Geminin yönü düþey yani 1 ise yaplacak iþlemler
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

    //geminin yönü 0 ve 1 deðilse yanlýþ bilgi uyarýsý için -1 döner.
    else{
        kontrol=-1;
    }

return kontrol;
}

void GemiYerlestir(int OyunAlani[][50],int x,int y,int gemiboyu,int gemiyonu){
    int i;
    if(gemiyonu==0){//gemi yönü yatay ise yapýlacak iþlemler
        for(i=0;i<gemiboyu;i++){//gemi boyu kadar döneriz
            OyunAlani[x][i+y]=gemiboyu;//oyun alanýna geminin boyutunu yazarýz
        }
    }else if(gemiyonu==1){//gemi yönü düþey ise yapýlacak iþlemler
        for(i=0;i<gemiboyu;i++){
            OyunAlani[i+x][y]=gemiboyu;
        }
    }
}

int AtisYap(int OyunAlani[][50],int en,int boy,int Atisx,int Atisy){
        if(Atisx>=boy || Atisx<0 || Atisy>=en || Atisy<0){//atisi kontrol edip oyun alanýnýn içinde atýþ yapmasý saðlanýr.
            printf("Oyun alaninin disinda atis yaptiniz.");
            return -1;//oyun alanýnýn dýþýndaysa -1 geri döndürür.
        }else{
            return OyunAlani[Atisx][Atisy];//oyun alanýnýn içindeyse o hücredeki deðeri geri döndürür.
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
    }while(karakter=='E' || karakter=='e');//e girildiði müddetçe gemi yerleþtirme iþmleri yapýlýr.




//Atýþ yapma iþlemleri gerçekleþtirilir.

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
