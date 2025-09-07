#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bilgi_sistemi //verilecek ve istenilecek bilgilerde kullanılmak üzere bilgi_sistemi tabanında veriler
{
    char calisan_adi[30];
    int calisan_ID;
    char calisan_meslek[30];
    int calisan_tecrube;
    int calisan_yas;

};


int main()
{

    struct bilgi_sistemi bs[30];
    int g = 0; //girdi alımı yapılacak
    int s,j,k = 0;//döngüde kullanılacak (s ise girilecek kullanıcı sayısını alacak)
    int toplam = 0; //toplam kullanıcı sayısını verecek
    int silinecekID; //çalışan silinmesi için istenen ıd de kullanılacak
    int found = 0; //girilen ıd nin var olup olmadığıının kontrolünde kullanılacak





    printf("***************************Calisan Bilgi Sistemi**************************\n");
    printf("\n");

    while(g!=5) //girdi 5 olduğunda while den çık
    {
        //kullanıcının yönlendirilmesi için ekrana bilgi aktarımı
        printf("\nCalisan tablosu olusturmak icin (1)\n");
        printf("Yeni calisan eklemek icin (2)\n");
        printf("Calisan silmek icin (3)\n");
        printf("Calisan bilgilerini gormek icin (4)\n");
        printf("Cikis icin (5)\n");
        printf("Lutfen bir tuslama yapiniz:\n");
        scanf("%d",&g);


        switch(g) //girilen g değerine göre case yönlenidirlecek
        {
      case 1:
           if (toplam >= 20) //kullanıcı sayısını 20 yi aşma ihtimali kontrolü
            {
                printf("Maksimum calisan sayisina ulastiniz!\n");
                  break;
            }
        printf("'Maksimum calisan sayisi:20'\n");
        printf("Eklenecek calisan sayisini girin\n");
        scanf("%d",&s);

        if (toplam + s > 20) //eklenecek çalışan sayısı 20 yi geçip geçmediğinin kontrolü. Geçerse çalışacak
            {
              printf("Eklenecek sayi maximum calisan sayisini asiyor! Maksimum ekleyebilirsiniz: %d\n", 20 - toplam);
              s = 20 - toplam;
            }

        for(j=0;j<s;j++) //çalışan bilgilerinin alınması

        {
             printf("\nAd:");
             scanf("%s",bs[k].calisan_adi);
             printf("\nCalisan ID:");
             scanf("%d",&bs[k].calisan_ID);
             printf("\nMeslek:");
             scanf("%s",bs[k].calisan_meslek);
             printf("\nTecrube(yil):");
             scanf("%d",&bs[k].calisan_tecrube);
             printf("\nCalisan Yas:");
             scanf("%d",&bs[k].calisan_yas);
          k++;
          toplam++;
        }


        break;

      case 2: //yeni çalışanın eklenmesi
          if (toplam >= 20) //kullanıcı sayısını 20 yi aşma ihtimali kontrolü
            {
           printf("Maksimum calisan sayisina ulastiniz!\n");
            break;
            }
        printf("\nCalisanin adini giriniz:");
        scanf("%s",bs[k].calisan_adi);
        printf("\nCalisan ID:");
        scanf("%d",&bs[k].calisan_ID);
        printf("\nMeslek:");
        scanf("%s",bs[k].calisan_meslek);
        printf("\nTecrube(yil):");
        scanf("%d",&bs[k].calisan_tecrube);
        printf("\nCalisan Yas:");
        scanf("%d",&bs[k].calisan_yas);

        k++;
        toplam++;
        break;

      case 3: //silinmesi istenen çalışanı kaydırma işlemi ile silme

        printf("\nSilinecek calisanin ID bilgisini giriniz:");
        scanf("%d",&silinecekID);

        found = 0; //Girilen ID nin var olup olmadığının kontrolü

        for(j=0;j<toplam;j++)
        {
            if (bs[j].calisan_ID == silinecekID)
             {
                found =1;//Girilen ID nin var olup olmadığının kontrolü
                  for(int x=j;x<toplam-1;x++)
                {
                    bs[x]=bs[x+1];
                }
                toplam--;
            printf("\nCalisan silindi\n");
            break;
             }


            }



        if (!found)//Girilen ID yoksa çalışır
           {
            printf("Bu ID'ye sahip calisan bulunamadi!\n");
           }

       break;

       case 4: //çalışan bilgilerini erkana listeler
           for(j=0;j<toplam;j++)
          {
           printf("\nCalisan adi: %s\n",bs[j].calisan_adi);
           printf("Calisan ID bilgisi: %d\n",bs[j].calisan_ID);
           printf("Calisan Meslek Bilgisi: %s\n",bs[j].calisan_meslek);
           printf("Calisan Tecrube Bilgisi: %d\n",bs[j].calisan_tecrube);
           printf("Calisan Yas Bilgisi: %d\n",bs[j].calisan_yas);

          }
          break;

        case 5: //çıkış
          exit(0);

        }



   }







    return 0;
}
