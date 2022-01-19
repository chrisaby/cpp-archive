//snake
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>
#include<dos.h>
class snake
{
   public:
   int x,y;
   static int length;
   snake*link;
}*p,*h,*q,*r,*b;
int snake :: length=1;
int fx,fy;
void getfood()
{
  randomize();
  fx=11+random(39);
  fy=11+random(9);
  q=h;
  do
  {
    if((q->x==fx)&&(q->y==fy))
    {
      q=h;
      fx=11+random(39);
      fy=11+random(9);
      continue;
    }
    q=q->link;
  }while(q!=NULL);
}
void life()
{
  q=h;
  if((p->x<11)||(p->x>49)||(p->y<11)||(p->y>19))
  {
      gotoxy(15,5);
      cout<<"GAME OVER";
      fflush(stdin);
      getch();
      exit(0);
  }
  while(q->link!=NULL)
  {
    if((q->x==p->x)&&(q->y==p->y))
    {
      gotoxy(15,5);
      cout<<"GAME OVER";
      fflush(stdin);
      getch();
      exit(0);
    }
    q=q->link;
  }
}
void stage()
{
	int i;
	clrscr();
	gotoxy(12,8);
	cout<<"SCORE : "<<snake::length;
	gotoxy(fx,fy);
	cout<<"*";
	gotoxy(10,10);
	putch(201);
	gotoxy(10,20);
	putch(200);
	gotoxy(50,10);
	putch(187);
	gotoxy(50,20);
	putch(188);
	for(i=0;i<39;i++)
	{
		gotoxy(11+i,10);
		putch(205);
		gotoxy(11+i,20);
		putch(205);
	}
	for(i=0;i<9;i++)
	{
		gotoxy(10,11+i);
		putch(186);
		gotoxy(50,11+i);
		putch(186);
	}
}
void train()
{
    q=h;
    while(q!=NULL)
    {
      gotoxy(q->x,q->y);
      cout<<"o";
      q=q->link;
    }
}
void play()
{
  char a,c='d';
  getfood();
  fflush(stdin);
  while(c!='x')
  {
    do
    {
       delay(300);
       *b=*h;
       r=h;
       while(r->link!=NULL)
       {
	 r->x=(r->link)->x;
	 r->y=(r->link)->y;
	 r=r->link;
       }
       switch(c)
       {
	 case 'd' : p->x++;
		    a=c;
		    break;
	 case 'a' : p->x--;
		    a=c;
		    break;
	 case 'w' : p->y--;
		    a=c;
		    break;
	 case 's' : p->y++;
		    a=c;
		    break;
	 default  : c=a;
       }
       life();
       if((p->x==fx)&&(p->y==fy))
       {
	 snake::length++;
	 r=(snake *)malloc(sizeof(snake));
	 *r=*b;
	 r->link=h;
	 h=r;
	 getfood();
       }
       stage();
       train();
    }while(!kbhit());
    c=getch();
    fflush(stdin);
  }
}
void main()
{
	clrscr();
	cout<<"press any key to begin.....";
	h=(snake *)malloc(sizeof(snake));
	p=(snake *)malloc(sizeof(snake));
	q=(snake *)malloc(sizeof(snake));
	r=(snake *)malloc(sizeof(snake));
	b=(snake *)malloc(sizeof(snake));
	h->x=30;
	h->y=15;
	h->link=NULL;
	p=h;
	play();
	getch();
}