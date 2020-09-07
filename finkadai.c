#include <stdio.h>
#include <drawlib.h>
#include <stdlib.h>
#include <time.h>
/*キーボード*/
char card1 = 'q',card2 = 'w', card3 = 'e', card4 = 'a', card5 = 's', card6 = 'd';

 int count = 0;/*正解のカウント*/
 /*色定義*/
#define dl_blue dl_color_from_name("blue")
#define dl_red dl_color_from_name("red")
#define dl_green dl_color_from_name("green")
#define dl_white dl_color_from_name("white")
#define dl_black dl_color_from_name("black")
#define dl_cyan dl_color_from_name("cyan")
/*各カードの位置*/
int wd = 60, hgt = 80;
int bx1 = 160, bx2 = 320, bx3 = 480;
int by1 = 160, by2 = 320;

char *q;/*表題のポインタ*/
int  r = 10, t, s, k, k1, cx1, cy1;

int w;/*色判定*/

char tex[] = "ClEAR!";
char tex1[] = "THANKS!!";
char tred[] = "red";
char tblue[] = "blue";
char tgreen[] ="green";

/*文字ポインタ*/
char *bp, *rp, *gp;
char *sel;

/*せつめい表示*/
char sek1[] ="push! q";
char sek2[] ="push! w";
char sek3[] ="push! e";
char sek4[] ="push! a";
char sek5[] ="push! s";
char sek6[] ="push! d";

char star[] ="Memory game!!";

void setumei(char *,char sek[],int x1,int y2);/*文字の関数定義*/
void judge2(int fp, int x,int y, char *col);/*２回目の関数定義*/
void shuffle(int card[], int size);/*シャッフル関数定義*/

/*２回目の関数*/
void judge2(int fg, int x, int y, char *col){
  if(w == fg){
    dl_circle(x,y,r,dl_color_from_name(col),2,1);
    count++;
  }else{
         dl_circle(bx1,by1,r,dl_white,2,1);
         dl_circle(bx2,by1,r,dl_white,2,1);
         dl_circle(bx3,by1,r,dl_white,2,1);
         dl_circle(bx1,by2,r,dl_white,2,1);
         dl_circle(bx2,by2,r,dl_white,2,1);
         dl_circle(bx3,by2,r,dl_white,2,1);
         count = 0;
  }
} 

/*シャッフル関数*/
void shuffle(int card[], int size) {
    for(int i = 0; i < size; i++) {
        int j = rand()%size;
        int t = card[i];
        card[i] = card[j];
        card[j] = t;
    }
}
/*文字の関数*/
void setumei(char *era,char sek[],int x1,int y2){
 era = sek;
 dl_text(era, x1 - 45, y2 +60 , 0.8, dl_black, 1);
}

int main (void) {
  srand((unsigned int)time(NULL));/*ランダム*/
  dl_initialize(1.0);

/*ポインタ指定*/
  bp = tblue;
  rp = tred;
  gp = tgreen;

 /*シャッフル*/
int card[] = {1,2,3,1,2,3};
  shuffle(card, 6);
  shuffle(card, 6);
  for (int i = 0; i < 6; i++) {
    printf("%d,", card[i]);
  }
    printf("==%d", card[5]);
    
  dl_clear(dl_color_from_rgb(51,153,102));
  dl_rectangle(50, 30, 590, 450, dl_white, 1, 0);
  
  
  /*カード基盤*/
  
  dl_rectangle(bx1-wd/2, by1-hgt/2, bx1+wd/2, by1+hgt/2, dl_white, 1, 1);
  dl_rectangle(bx2-wd/2, by1-hgt/2, bx2+wd/2, by1+hgt/2, dl_white, 1, 1);
  dl_rectangle(bx3-wd/2, by1-hgt/2, bx3+wd/2, by1+hgt/2, dl_white, 1, 1);
  dl_rectangle(bx1-wd/2, by2-hgt/2, bx1+wd/2, by2+hgt/2, dl_white, 1, 1);
  dl_rectangle(bx2-wd/2, by2-hgt/2, bx2+wd/2, by2+hgt/2, dl_white, 1, 1);
  dl_rectangle(bx3-wd/2, by2-hgt/2, bx3+wd/2, by2+hgt/2, dl_white, 1, 1);
  
  dl_rectangle(bx1-wd/2, by1-hgt/2, bx1+wd/2, by1+hgt/2, dl_black, 1, 0);
  dl_rectangle(bx2-wd/2, by1-hgt/2, bx2+wd/2, by1+hgt/2, dl_black, 1, 0);
  dl_rectangle(bx3-wd/2, by1-hgt/2, bx3+wd/2, by1+hgt/2, dl_black, 1, 0);
  dl_rectangle(bx1-wd/2, by2-hgt/2, bx1+wd/2, by2+hgt/2, dl_black, 1, 0);
  dl_rectangle(bx2-wd/2, by2-hgt/2, bx2+wd/2, by2+hgt/2, dl_black, 1, 0);
  dl_rectangle(bx3-wd/2, by2-hgt/2, bx3+wd/2, by2+hgt/2, dl_black, 1, 0);
  
  q=star;
   dl_text(q, 200, 80, 1, dl_white, 1);
  
  /*操作せつめい*/
  setumei(sel,sek1,bx1,by1);
  setumei(sel,sek2,bx2,by1);
  setumei(sel,sek3,bx3,by1);
  setumei(sel,sek4,bx1,by2);
  setumei(sel,sek5,bx2,by2);
  setumei(sel,sek6,bx3,by2);
  
  
  while(count < 3){
    w=0;
    /*一回目*/
    while (1) {
      if (dl_get_event(&t, &k , &cx1, &cx1)) {
        if(k == card1){
          if(card[0] == 1){
            dl_circle(bx1,by1,r,dl_blue,2,1);
            w = 1;
          }else if(card[0] == 2){
            dl_circle(bx1,by1,r,dl_red,2,1);
            w =2;
          }else if(card[0] == 3){
            dl_circle(bx1,by1,r,dl_green,2,1);
            w =3;
          }
          break;
        }else if(k == card2){
          if(card[1] == 1){
            dl_circle(bx2,by1,r,dl_blue,2,1);
            w =1;
          }else if(card[1] == 2){
            dl_circle(bx2,by1,r,dl_red,2,1);
            w= 2;
          }else if(card[1] == 3){
            dl_circle(bx2,by1,r,dl_green,2,1);
            w =3;
          }
          break;
        }else if(k == card3){
          if(card[2] == 1){
            dl_circle(bx3,by1,r,dl_blue,2,1);
            w =1;
          }else if(card[2] == 2){
            dl_circle(bx3,by1,r,dl_red,2,1);
            w =2;
          }else if(card[2] == 3){
            dl_circle(bx3,by1,r,dl_green,2,1);
            w =3;
          }
          break;
        }else if(k == card4){
          if(card[3] == 1){
            w = 1;
            dl_circle(bx1,by2,r,dl_blue,2,1);
          }else if(card[3] == 2){
            dl_circle(bx1,by2,r,dl_red,2,1);
            w =2;
          }else if(card[3] == 3){
            dl_circle(bx1,by2,r,dl_green,2,1);
            w = 3;
          }
          break;
        }else if(k == card5){
          if(card[4] == 1){
            dl_circle(bx2,by2,r,dl_blue,2,1);
            w=1;
          }else if(card[4] == 2){
            dl_circle(bx2,by2,r,dl_red,2,1);
            w=2;
          }else if(card[4] == 3){
            dl_circle(bx2,by2,r,dl_green,2,1);
            w=3;
          }
          break;
        }else if(k == card6){
          if(card[5] == 1){
            dl_circle(bx3,by2,r,dl_blue,2,1);
            w=1;
          }else if(card[5] == 2){
            dl_circle(bx3,by2,r,dl_red,2,1);
            w =2;
          }else if(card[5] == 3){
           dl_circle(bx3,by2,r,dl_green,2,1);
           w =3;
          } 
          break;
        }
      }
    dl_wait(0.01);
    }
    /*二回目*/     
    while (1) {
      if (dl_get_event(&s, &k1 , &cx1, &cx1)) {
        if(k1 == card1){
          if(card[0] == 1){
            judge2(1, bx1, by1, bp);
            break; 
          }else if(card[0] == 2){
            judge2(2 ,bx1,by1, rp);
            break;
          }else if(card[0] == 3){
            judge2(3, bx1, by1, gp);
            break;
          }
        }else if(k1 == card2){
          if(card[1] == 1){
            judge2(1, bx2, by1, bp);
            break;
          }else if(card[1] == 2){
            judge2(2, bx2, by1, rp);
            break;
          }else if(card[1] == 3){
            judge2(3, bx2, by1, gp);
            break;
          }
        }else if(k1 == card3){
          if(card[2] == 1){
            judge2(1, bx3, by1, bp);
            break;
          }else if(card[2] == 2){
            judge2(2, bx3, by1, rp);
            break;
          }else if(card[2] == 3){
            judge2(3, bx3, by1, gp);
            break;
          }
        }else if(k1 == card4){
          if(card[3] == 1){
            judge2(1, bx1, by2, bp);
            break;
          }else if(card[3] == 2){
            judge2(2, bx1, by2, rp);
            break;
          }else if(card[3] == 3){
            judge2(3, bx1, by2, gp);
            break;
          }
        }else if(k1 == card5){
          if(card[4] == 1){
            judge2(1, bx2, by2, bp);
            break;
          }else if(card[4] == 2){
            judge2(2, bx2, by2, rp);
            break;
          }else if(card[4] == 3){
            judge2(3, bx2, by2, gp);
            break;
          }
        }else if(k1 == card6){
          if(card[5] == 1){
            judge2(1, bx3, by2, bp);
            break;
          }else if(card[5] == 2){
            judge2(2, bx3, by2, rp);
            break;
          }else if(card[5] == 3){
            judge2(3, bx3, by2, gp);
            break;
          }
        }
      }
      dl_wait(0.01);
    }
  }

  while (1) {
    dl_wait(1.0);
    /*clear*/
    q=tex;
    dl_text(q, 150, 240, 3, dl_blue, 5);
    dl_wait(2.0);
    /*Thanks*/
    q=tex1;
    dl_text(q, 150, 330, 3, dl_cyan, 4);
    dl_wait(2.0);
    break;
  }
    
   return 0;
}
