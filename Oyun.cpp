#include <stdio.h>
#include <graphics.h>
#include <math.h>

struct TTop
{
       int mx,my;
       int xhiz,yhiz;
};
struct TTop top[7];

struct TIsteka
{
       int basx,basy,bitx,bity;
};
struct TIsteka isteka;

int sayfano=0,GirenTop=0;

void GirisEkraniCiz(void)
{
     cleardevice();
     setbkcolor(BLACK);
     setcolor(CYAN);
     
     settextstyle(6,0,7);
     outtextxy(190,120,"BİLARDO");
     
     setlinestyle(0,0,2);
     rectangle(180,120,600,180);
     
     //----GİRİŞ-EKRANINDAKİ-SEKMELER----//
     settextstyle(6,0,3);
     outtextxy(235,270,">>OYUNA BAŞLA<<");
     outtextxy(245,310,">>TALİMATLAR<<");
     outtextxy(225,350,">>OYUNDAN ÇIK!!!<<");
}

void OyunEkraniCiz(void)
{
     setbkcolor(BLACK);
     cleardevice();
  
     //-----------MASA-----------//
     setcolor(RED);
     setlinestyle(0,0,1);
     setfillstyle(SOLID_FILL,RED);
     rectangle(20,50,780,510);
     floodfill(100,60,RED);
    
     setcolor(GREEN);
     setfillstyle(SOLID_FILL,GREEN);
     rectangle(50,80,750,480);
     floodfill(100,200,GREEN);
     
     //---------DELİKLER---------//        
     setcolor(BLACK);
     setfillstyle(SOLID_FILL,BLACK);
     circle(60,90,20);
     floodfill(50,80,BLACK);
     circle(740,90,20);
     floodfill(750,80,BLACK);
     circle(60,470,20);
     floodfill(50,480,BLACK);
     circle(740,470,20);
     floodfill(750,480,BLACK);
     circle(400,80,20);
     floodfill(400,80,BLACK);
     circle(400,480,20);
     floodfill(400,480,BLACK);
    
     //---------TOPLAR-----------//    
     setcolor(WHITE);
     setfillstyle(SOLID_FILL,WHITE);
     circle(top[0].mx,top[0].my,15);
     fillellipse(top[0].mx,top[0].my,15,15);
        
     setcolor(YELLOW);
     setfillstyle(SOLID_FILL,YELLOW);
     circle(top[1].mx,top[1].my,15);
     fillellipse(top[1].mx,top[1].my,15,15);
     circle(top[2].mx,top[2].my,15);
     fillellipse(top[2].mx,top[2].my,15,15);
     circle(top[3].mx,top[3].my,15);
     fillellipse(top[3].mx,top[3].my,15,15);
     circle(top[4].mx,top[4].my,15);
     fillellipse(top[4].mx,top[4].my,15,15);
     circle(top[5].mx,top[5].my,15);
     fillellipse(top[5].mx,top[5].my,15,15);
     circle(top[6].mx,top[6].my,15);
     fillellipse(top[6].mx,top[6].my,15,15);
    
     //---------GÖSTERGELER---------//
     setbkcolor(BLACK);
     setcolor(RED);
     setlinestyle(0,0,4);
     rectangle(25,530,275,580);
     
     setlinestyle(0,0,3);
     rectangle(515,545,775,565);
    
     settextstyle(6,0,4);
     outtextxy(120,15,"BİLARDO");
     
     settextstyle(6,0,2);
     outtextxy(425,545,"HIZ=>");
      
     setfillstyle(SOLID_FILL,RED);
     bar(670,10,775,40);
     setbkcolor(RED);
     setcolor(BLACK);
     settextstyle(6,0,3);
     outtextxy(678,15,"ÇIKIŞ");
       
     swapbuffers();
}

void Carpisma(struct TTop *top1,struct TTop *top2)
{
     float uzaklik,cosu,sinu,momentum,fark,deger1,deger2,deger3,deger4;
     
     uzaklik=sqrt(pow((top1->mx)-(top2->mx),2.0)+pow((top1->my)-(top2->my),2.0));
     cosu=((top2->mx)-(top1->mx))/uzaklik;	
     sinu=((top2->my)-(top1->my))/uzaklik;
     deger1=(top1->xhiz)*cosu+(top1->yhiz)*sinu;
     deger2=(top2->xhiz)*cosu+(top2->yhiz)*sinu;
     deger3=(top1->xhiz)*sinu-(top1->yhiz)*cosu;
     deger4=(top2->xhiz)*sinu-(top2->yhiz)*cosu;
     momentum=deger1+deger2;
     fark=deger2-deger1;
     deger1=(momentum+fark)/2;
     deger2=(momentum-fark)/2;
     top1->xhiz=deger1*cosu+deger3*sinu;
     top2->xhiz=deger2*cosu+deger4*sinu;
     top1->yhiz=deger1*sinu-deger3*cosu;
     top2->yhiz=deger2*sinu-deger4*cosu;
}

void Isteka(int *hiz)
{
     int x,y,u,gos;
     float uzaklik,sinu,cosu;
     
     //-----OYUN-EKRANINI-ÇİZME----//
     cleardevice();
     OyunEkraniCiz();
      
     //-----ISTEKANIN-HAREKETİ-----//      
     x=mousex();
     y=mousey();
     uzaklik=sqrt(pow(x-top[0].mx,2.0)+pow(y-top[0].my,2.0));
     cosu=(x-top[0].mx)/uzaklik;
     sinu=(y-top[0].my)/uzaklik;
        
     isteka.basx=(top[0].mx)+20*cosu;
     isteka.basy=(top[0].my)+20*sinu;
     isteka.bitx=(isteka.basx)+180*cosu;
     isteka.bity=(isteka.basy)+180*sinu;
         
     //------ISTEKANIN-ÇİZİMİ------//
     setcolor(BROWN);
     setlinestyle(0,0,8);
     line(isteka.basx,isteka.basy,isteka.bitx,isteka.bity);
      
     //--HIZ-GÖSTERGESİNİN-HAREKETİ--//
     gos=*hiz-10;
     u=gos/2;
     bar(520,550,(u*25)+520,560);
      
     swapbuffers();
           
}
     
void ToplarinHareketi(void)
{
     //-----TOPLARIN-İLK-HIZLARINI-ATAMA----//
     top[0].xhiz=0; top[0].yhiz=0;
     top[1].xhiz=0; top[1].yhiz=0;
     top[2].xhiz=0; top[2].yhiz=0;
     top[3].xhiz=0; top[3].yhiz=0;
     top[4].xhiz=0; top[4].yhiz=0;
     top[5].xhiz=0; top[5].yhiz=0;
     top[6].xhiz=0; top[6].yhiz=0;
     
     int i,sayac=0;
     int hiz=10;
     float uzaklik;
     
     //--------ISTEKANIN-BEYAZ-TOPA-VURMASI----------//    
     while(1)
     {
      //-----HIZI-ARTIRMAK-İÇİN-SOL-TUŞ-----//      
      if(ismouseclick(WM_LBUTTONDOWN))
        {
         if(hiz==30) 
         break;           
         
         hiz++;
       //---HIZI-DURDURMAK-İÇİN-SAĞ-TUŞ---//
         if(ismouseclick(WM_RBUTTONDOWN))
         break;
        
        }
      
       uzaklik=sqrt(pow(isteka.bitx-top[0].mx,2.0)+pow(isteka.bity-top[0].my,2.0));
      
       //------HIZIN-BEYAZ-TOPA-AKTARILMASI------//
       top[0].xhiz=-(((isteka.bitx-top[0].mx)/uzaklik)*hiz);
       top[0].yhiz=-(((isteka.bity-top[0].my)/uzaklik)*hiz);
        
       //-----ISTEKA-VE-OYUN-EKRANINI-ÇİZME------//
       OyunEkraniCiz();
       Isteka(&hiz);
      
       setvisualpage(sayfano);
       setactivepage(1-sayfano);
       ++sayfano%=2;
       delay(70);
      }
     
       //-----MOUSE-TIKLAMALARINI-TEMİZLEME------//
       clearmouseclick(WM_LBUTTONDOWN);
       clearmouseclick(WM_RBUTTONDOWN);
     
     //-----------------TOPLARIN-HAREKETİ----------------//
     while(top[0].xhiz!=0||top[0].yhiz!=0||top[1].xhiz!=0||top[1].yhiz!=0||
           top[2].xhiz!=0||top[2].yhiz!=0||top[3].xhiz!=0||top[3].yhiz!=0||
           top[4].xhiz!=0||top[4].yhiz!=0||top[5].xhiz!=0||top[5].yhiz!=0||
           top[6].xhiz!=0||top[6].yhiz!=0)
     {
          
           //------BANT-KONTROL-------//
           for(i=0;i<7;i++)
              {
               if(top[i].mx<65||top[i].mx>735) top[i].xhiz=-top[i].xhiz;
               if(top[i].my<95||top[i].my>465) top[i].yhiz=-top[i].yhiz;
              }
           
           //----MERKEZ-KOORDİNATLARINA-HIZLARI-EKLEME---//
           for(i=0;i<7;i++)
              {
               top[i].mx+=top[i].xhiz;
               top[i].my+=top[i].yhiz;
              }
           
           //-----HIZIN-ZAMANLA-ARTMASI-VEYA-AZALMASI----//
           if(sayac==0)
           {
            for(i=0;i<7;i++)
               {
                if(top[i].xhiz>0) top[i].xhiz--; if(top[i].xhiz<0) top[i].xhiz++;
                if(top[i].yhiz>0) top[i].yhiz--; if(top[i].yhiz<0) top[i].yhiz++;
               }
           }
           ++sayac%=10;
           
           //-------TOPLARIN-ÇARPIŞMASINI-KONTROL--------//
           //--BEYAZ-TOPUN--//
           for(i=1;i<7;i++)
              {
               if(sqrt(pow(top[0].mx-top[i].mx,2.0)+pow(top[0].my-top[i].my,2.0))<30)
                  Carpisma(&top[0],&top[i]);
              }
           //---1.TOPUN----//
           for(i=2;i<7;i++)
              {
               if(sqrt(pow(top[1].mx-top[i].mx,2.0)+pow(top[1].my-top[i].my,2.0))<30)
                  Carpisma(&top[1],&top[i]);
              }
           //---2.TOPUN----//
           for(i=3;i<7;i++)
              {
               if(sqrt(pow(top[2].mx-top[i].mx,2.0)+pow(top[2].my-top[i].my,2.0))<30)
                  Carpisma(&top[2],&top[i]);
              }
           //---3.TOPUN----//
           for(i=4;i<7;i++)
              {
               if(sqrt(pow(top[3].mx-top[i].mx,2.0)+pow(top[3].my-top[i].my,2.0))<30)
                  Carpisma(&top[3],&top[i]);
              }
           //---4.TOPUN----//
           for(i=5;i<7;i++)
              {
               if(sqrt(pow(top[4].mx-top[i].mx,2.0)+pow(top[4].my-top[i].my,2.0))<30)
                  Carpisma(&top[4],&top[i]);
              }
           //---5.TOPUN----//
           if(sqrt(pow(top[5].mx-top[6].mx,2.0)+pow(top[5].my-top[6].my,2.0))<30)
              Carpisma(&top[5],&top[6]);
              
           //------TOPLARIN-DELİĞE-DÜŞMESİNİ-KONTROL-----//
           //---1.DELİĞE---//
           if(sqrt(pow(60-top[0].mx,2.0)+pow(90-top[0].my,2.0))<15)  
                 {top[0].mx=170; top[0].my=280; top[0].xhiz=0; top[0].yhiz=0;}
           for(i=1;i<7;i++)
              {
               if(sqrt(pow(60-top[i].mx,2.0)+pow(90-top[i].my,2.0))<15)  
                 {top[i].mx=(40*i)+10; top[i].my=555;
                  top[i].xhiz=0;       top[i].yhiz=0;
                  GirenTop++;}
              }
              
           //---2.DELİĞE---//
           if(sqrt(pow(400-top[0].mx,2.0)+pow(80-top[0].my,2.0))<15)  
                 {top[0].mx=170; top[0].my=280; top[0].xhiz=0; top[0].yhiz=0;}
           for(i=1;i<7;i++)
              {
               if(sqrt(pow(400-top[i].mx,2.0)+pow(80-top[i].my,2.0))<15)  
                 {top[i].mx=(40*i)+10; top[i].my=555;
                  top[i].xhiz=0;       top[i].yhiz=0;
                  GirenTop++;}
              }
              
           //---3.DELİĞE---//
           if(sqrt(pow(740-top[0].mx,2.0)+pow(90-top[0].my,2.0))<15)  
                 {top[0].mx=170; top[0].my=280; top[0].xhiz=0; top[0].yhiz=0;}
           for(i=1;i<7;i++)
              {
               if(sqrt(pow(740-top[i].mx,2.0)+pow(90-top[i].my,2.0))<15)  
                 {top[i].mx=(40*i)+10; top[i].my=555; 
                  top[i].xhiz=0;       top[i].yhiz=0;
                  GirenTop++;}
              }
              
           //---4.DELİĞE---//
           if(sqrt(pow(60-top[0].mx,2.0)+pow(470-top[0].my,2.0))<15)  
                 {top[0].mx=170; top[0].my=280; top[0].xhiz=0; top[0].yhiz=0;}
           for(i=1;i<7;i++)
              {
               if(sqrt(pow(60-top[i].mx,2.0)+pow(470-top[i].my,2.0))<15)  
                 {top[i].mx=(40*i)+10; top[i].my=555;
                  top[i].xhiz=0; top[i].yhiz=0;
                  GirenTop++;}
              }
              
           //---5.DELİĞE---//
           if(sqrt(pow(400-top[0].mx,2.0)+pow(480-top[0].my,2.0))<15)  
                 {top[0].mx=170; top[0].my=280; top[0].xhiz=0; top[0].yhiz=0;}
           for(i=1;i<7;i++)
              {
               if(sqrt(pow(400-top[i].mx,2.0)+pow(480-top[i].my,2.0))<15)  
                 {top[i].mx=(40*i)+10; top[i].my=555;
                  top[i].xhiz=0; top[i].yhiz=0;
                  GirenTop++;}
              }
              
           //---6.DELİĞE---//
           if(sqrt(pow(740-top[0].mx,2.0)+pow(470-top[0].my,2.0))<15)  
                 {top[0].mx=170; top[0].my=280; top[0].xhiz=0; top[0].yhiz=0;}
           for(i=1;i<7;i++)
              {
               if(sqrt(pow(740-top[i].mx,2.0)+pow(470-top[i].my,2.0))<15)  
                 {top[i].mx=(40*i)+10; top[i].my=555;
                  top[i].xhiz=0; top[i].yhiz=0;
                  GirenTop++;}
              }
           
           //-----OYUN-EKRANINI-ÇİZME-----//
           OyunEkraniCiz();
           
           setvisualpage(sayfano);
           setactivepage(1-sayfano);
           ++sayfano%=2;
           delay(30);     
     } 
}


int main()
{
    //---TOPLARI-TANIMLAMA-----//
    top[0].mx=170; top[0].my=280;
    top[1].mx=520; top[1].my=280;
    top[2].mx=550; top[2].my=260;
    top[3].mx=550; top[3].my=300;
    top[4].mx=580; top[4].my=280;
    top[5].mx=580; top[5].my=240;
    top[6].mx=580; top[6].my=320;
    
    int x,y;
    initwindow(800,600,"BİLARDO");
    
    //--------G�R��-EKRANI-��ZME--------//
    GirisEkraniCiz();
    //----G�R��-EKRANINDAK�-SEKMELER----//
    while(1)
    {
       while (!ismouseclick(WM_LBUTTONDOWN));						
               getmouseclick(WM_LBUTTONDOWN, x, y);
       if((y>270&&y<290)&&(x>235&&x<550)) break;
       if((y>350&&y<370)&&(x>225&&x<570)) return 0;
       if((y>310&&y<330)&&(x>245&&x<540))
       {
          cleardevice();
          setbkcolor(BLACK);
          setcolor(CYAN);
          settextstyle(6,0,2);
          outtextxy(110,40,"-TALİMATLAR-");
          outtextxy(30,80,"1)Istekanın hareketi Mouse'nin hareketi ile sağlanmaktad�r.");
          outtextxy(30,120,"2)Hız, Mouse'nin SAĞ ve SOL tuşlar ile değişmektedir.");
          outtextxy(30,160,"3)SOL tuşa tıklandığında hızın değeri, SAĞ tuşa");
          outtextxy(60,190,"tıklanana kadar artmaya başlar.");
          outtextxy(30,230,"4)SAĞ tuşa tıkladığında hız artmayı durdurur ve top bu");
          outtextxy(60,260,"hızla harekete başlar.");
          outtextxy(30,300,"5)Eğer SAĞ tuşa tıklanmazsa hız otomatik olarak ");
          outtextxy(60,330,"maksimum hıza ulaşır ve top bu hızla harekete başlar.");
          outtextxy(30,370,"5)Toplar deliğe girdiğinde sol alttaki kutuda sıralanır.");
          outtextxy(30,410,"6)Tüm toplar deliğe girdiğinde oyun kazanılır.");
          outtextxy(450,500,"OYUNA BAŞLA>>>");
       }
       if((x>450&&x<720)&&(y>500&&y<520)) break;       
    }   
    
    //---------OYUN-DONGUSU-------------//
    while(1)
    {       
       //------OYUN-EKRANINI-ÇİZME-----//
       OyunEkraniCiz();
       //----TOPLARIN-HAREKET-ETMESİ---//
       ToplarinHareketi();
       //--GİREN-TOP-SAYISINI-KONTROL--//
       if(GirenTop==6)
          break;
       //-----ÇIKIŞ-TUŞUNU-KONTROL-----//
       if(!ismouseclick(WM_LBUTTONDOWN));
          {getmouseclick(WM_LBUTTONDOWN,x,y);
           if((x>670&&x<770)&&(y>10&&y<40))
              return 0;
          }
       delay(10);
    }
    
    //---------SON-EKRANI-ÇİZME--------//    
    cleardevice();
    setbkcolor(BLACK);
    setcolor(RED);
    
    settextstyle(6,0,7);
    outtextxy(140,180,"TEBR�KLER");
    outtextxy(100,280,"KAZANDINIZ:)");
 
    getch();
    closegraph();
}
