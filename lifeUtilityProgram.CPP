//Life Utility Program
#include<fstream.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
class contact
{
 public:
 char Name[20],No[20],Category[20],Email[20];
 void Add()
 {
  clrscr();
  gotoxy(5,5);
  cprintf("Enter Name      :");
  gets(Name);
  gotoxy(5,7);
  cprintf("Enter No        :");
  gets(No);
  gotoxy(5,9);
  cprintf("Enter Email     :");
  gets(Email);
  gotoxy(5,11);
  cprintf("Enter Category  :");
  gets(Category);
  getch();
 }
 void Show()
 {
  clrscr();
  gotoxy(5,5);
  cprintf("Name            :");
  cprintf(Name);
  gotoxy(5,7);
  cprintf("No              :");
  cprintf(No);
  gotoxy(5,9);
  cprintf("Enter Email     :");
  cprintf(Email);
  gotoxy(5,11);
  cprintf("Enter Category  :");
  cprintf(Category);
  getch();
 }
}a,b;
class top
{
 public:
 float tspeed;
 char Name[30];
}t;
class tops
{
 public:
 float stime,Moves;
 char Name[30];
}x;
class HScore
{
 public:
 int Won,Lost,Tied;
 char Name[30];
};
class player
{
 public:
 char board[9];
 void disp()
 {
  char x=178,y=176;
  int i,j=0;
  clrscr();
  for(i=1;i<4;i++) //Game Area
  {
   ++j;
   for(;j<4;++j)
   {
   gotoxy(10,10*i);
   cout<<board[3*j-3];
   gotoxy(20,10*i);
   cout<<board[3*j-2];
   gotoxy(30,10*i);
   cout<<board[3*j-1];
   break;
   }
  }
  textcolor(random(15)+1);
  for(i=0;i<2;++i) //Vertical Lines
   for(j=5;j<35;++j)
   {
    gotoxy(15+10*i,j);
    cout<<x;
   }
  for(i=0;i<2;++i) //Horizontal Lines
   for(j=0;j<21;++j)
   {
    gotoxy(10+j,15+10*i);
    cout<<y;
   }
 }
 int win(int b)//To Check If Player Has Won
 {
  char p;
  if(b==1)
   p=3;
  else
   p=4;
  if((board[0]==p)&&(board[1]==p)&&(board[2]==p));
  else if((board[3]==p)&&(board[4]==p)&&(board[5]==p));
  else if((board[6]==p)&&(board[7]==p)&&(board[8]==p));
  else if((board[0]==p)&&(board[3]==p)&&(board[6]==p));
  else if((board[1]==p)&&(board[4]==p)&&(board[7]==p));
  else if((board[2]==p)&&(board[5]==p)&&(board[8]==p));
  else if((board[0]==p)&&(board[4]==p)&&(board[8]==p));
  else if((board[2]==p)&&(board[4]==p)&&(board[6]==p));
  else
  return(0);
  return(1);
 }
 int draw()
 { int i;
   for(i=0;board[i]!='*'&&i<9;++i);
   if(i==9)
   { disp();
     clrscr();
     for(i=0;i<10;++i)
     {
     gotoxy(15,10+i);
     delay(300);
     textcolor(i);
     cprintf("*Game Drawn*");
     }
    return(1);
   }
   return(0);
 }
 int manip(int x,int y,int b)//To Find Choice
 {
  int k;
  char p;
  if(b==1)
   p=3;
  else
   p=4;
  if(x==10&&y==10)
   k=0;
  else if(x==20&&y==10)
   k=1;
  else if(x==30&&y==10)
   k=2;
  else if(x==10&&y==20)
   k=3;
  else if(x==20&&y==20)
   k=4;
  else if(x==30&&y==20)
   k=5;
  else if(x==10&&y==30)
   k=6;
  else if(x==20&&y==30)
   k=7;
  else if(x==30&&y==30)
   k=8;
  if(board[k]!='*')
   return(0);
  board[k]=p;
  return(1);
 }
 void play2(int b)//To Play
 {
  char ch=0;
  int x=20,y=20;
 Enter:
  do
  {
   disp();
   gotoxy(x,y);
   ch=getch();
   if(ch==72&&y!=10)
   y-=10;
   else if(ch==75&&x!=10)
   x-=10;
   else if(ch==77&&x!=30)
   x+=10;
   else if(ch==80&&y!=30)
   y+=10;
  }while(ch!=13);
  if(!manip(x,y,b))
  goto Enter;
 }
 int play1(int p)
 {
  int i,w;
  textcolor(3);
  gotoxy(10,35);
  if(p==1)
   cprintf("******Player One******");
  else
   cprintf("******Player Two******");
  gotoxy(10,20);
  play2(p);
  disp();
  w = win(p);
  if(w)
  {
   clrscr();
   for(i=0;i<10;++i)
   {
    gotoxy(15,5+i);
    delay(300);
    textcolor(i);
    if(p==1)
     cprintf("*Player One Wins*");
    else
     cprintf("*Player Two Wins*");
   }
  }
  return(w);
 }
 void Prepare()
 {
  strcpy(board,"*********");
 }
};
class Cricket
{
 int score[2],out[2];
 public:
 int wickets,done,W,L,T;
 void getwick()
 {
  W=0,L=0,T=0,wickets=0;
  while(!((wickets<11)&&(wickets>0)))
  {
  clrscr();
  gotoxy(5,5);
  cout<<"\nEnter No.of wickets (max.10)";
  cin>>wickets;
  }
 }
 void toss()
 {
  out[1]=0,out[0]=0,score[1]=0,score[0]=0;
  done=0;
  char ch;
  int x,t,toss;
  clrscr();
  gotoxy(10,10);
  cout<<"Heads Or Tails";
  gotoxy(5,15);
  cout<<"***********************";
  gotoxy(10,20);
  cprintf("Head");
  gotoxy(20,20);
  cprintf("Tail");
  x=20;
  do
  {
  gotoxy(x,20);
  ch=getch();
  if(ch==75&&x!=10)
  x-=10;
  else if(ch==77&&x!=20)
  x+=10;
  }while(ch!=13);
  t=10*(random(10)%2+1);
  clrscr();
  textcolor(9);
  gotoxy(15,15);
  if(t==x)
  {
  toss=1;
  cprintf("Player Wins The Toss");
  }
  else
  {
  toss=0;
  cprintf("Cpu Wins The Toss");
  }
  getch();
  clrscr();
  gotoxy(15,15);
  if(toss==0)
  {
   if(random(10)%2==0)
   {
    cprintf("Cpu Chose To Bat");
    getch();
    pbowl(1);
   }
   else
   {
    cprintf("Cpu Chose To Bowl");
    getch();
    pbat(1);
   }
  }
  else
   {
    clrscr();
    gotoxy(10,10);
    cout<<"Bat Or Bowl";
    gotoxy(5,15);
    cout<<"******************";
    gotoxy(10,20);
    cprintf("Bat");
    gotoxy(20,20);
    cprintf("Bowl");
    x=20;
    do
    {
     gotoxy(x,20);
     ch=getch();
     if(ch==75&&x!=10)
     x-=10;
     else if(ch==77&&x!=20)
     x+=10;
     }while(ch!=13);
    clrscr();
    gotoxy(15,15);
    if(x==10)
    {
     cprintf("Player Chose To Bat");
     pbat(1);
    }
    else
    {
     cprintf("Player Chose To Bowl");
     pbowl(1);
    }
    getch();
   }
 }
 void pbat(int p)
 {
  while(done==0)
  {
   int i,x,y;
   y=random(6)+1;
   scrb(0);
   gotoxy(5,17);
   cprintf("Player Batting");
   if(p==2)
   {
    gotoxy(5,11);
    cout<<"Target     :"<<score[1]+1;
   }
   gotoxy(5,13);
   cout<<"Player :-   ";
   cin>>x;
   gotoxy(5,15);
   cout<<"Cpu    :-   "<<y;
   Comments(x,y);
   getch();
   if(!((x<7)&&(x>0)))
    pbat(p);
   else
    if(x==y)
     ++out[0];
    else
    score[0]+=x;
   if((p==2)&&(score[0]>score[1]))
   {
    delay(1000);
    getch();
    clrscr();
    for(i=0;i<10;++i)
     {
      gotoxy(30,10+i);
      delay(500);
      textcolor(i);
      cprintf("*Player Wins*");
     }
     ++W;
     done=1;
     return;
    }
   if(out[0]==wickets)
   {
    delay(3500);
    clrscr();
    if(p==1)
     pbowl(2);
    else if(score[0]==score[1])
    {
     delay(1500);
     getch();
     for(i=0;i<10;++i)
     {
      gotoxy(30,10+i);
      delay(500);
      textcolor(i);
      cprintf("*Game Drawn*");
      ++T;
      done=1;
      return;
     }
    }
    else
    {
     delay(1500);
     getch();
     for(i=0;i<10;++i)
     {
      gotoxy(30,10+i);
      delay(500);
      textcolor(i);
      cprintf("*Cpu Wins*");
      ++L;
      done=1;
      return;
     }
    }
   }
   pbat(p);
 }
}
void pbowl(int p)
{
 while(done==0)
{ int i,x,y;
  y=random(6)+1;
  scrb(1);
  gotoxy(5,17);
  cprintf("Cpu Batting");
  if(p==2)
   {
   gotoxy(5,11);
   cout<<"Target     :"<<score[0]+1;
   }
  gotoxy(5,13);
  cout<<"Player :-   ";
  cin>>x;
  gotoxy(5,15);
  cout<<"Cpu    :-   "<<y;
  Comments(y,x);
  getch();
  if(!((x<7)&&(x>0)))
   pbowl(p);
  else
   if(x==y)
    ++out[1];
   else
   score[1]+=y;
   if((p==2)&&(score[1]>score[0]))
   {
    delay(1500);
    getch();
    clrscr();
    for(i=0;i<10;++i)
     {
      gotoxy(30,10+i);
      delay(500);
      textcolor(i);
      cprintf("*Cpu Wins*");
     }
     ++W;
     done=1;
     return;
    }
   if(out[1]==wickets)
  {
   if(p==1)
    pbat(2);
   else if(score[0]==score[1])
   {
    delay(1500);
    getch();
    for(i=0;i<10;++i)
    {
     gotoxy(30,10+i);
     delay(500);
     textcolor(i);
     cprintf("*Game Drawn*");
     done=1;
     ++T;
     return;
    }
   }
  else
   {
    delay(1500);
    getch();
   for(i=0;i<10;++i)
    {
     gotoxy(30,10+i);
     delay(500);
     textcolor(i);
     cprintf("*Player Wins*");
     ++L;
     done=1;
     return;
    }
   }
  }
  pbowl(p);
 }
}
 void scrb(int p)
 {
  clrscr();
  gotoxy(5,3);
  cprintf("scoreboard");
  gotoxy(5,5);
  cprintf("************");
  gotoxy(5,7);
  cprintf("Score");
  cout<<"     :"<<score[p];
  gotoxy(5,9);
  cprintf("Wickets");
  cout<<"   :"<<out[p];
 }
 void Comments(int b,int f)
 {
  char S[40],F[40],O[40],D[40];
  switch(random(3))
  {
   case 0 : strcpy(S,"That's Gone Over The Ropes.Six Runs!!");
	    strcpy(F,"Nice Shot Placed It So Well.Four Runs!!");
	    strcpy(O,"Whoa What A Catch!Superb Wicket");
	    strcpy(D,"Dead Ball! The Batsman Was Not Ready");
	    break;
   case 1 : strcpy(S,"Yeah That's What I Call !!SIXER!!");
	    strcpy(F,"Superb Shot Four Runs!!");
	    strcpy(O,"Howzat! Clean Bowled!");
	    strcpy(D,"Dead Ball! The Umpire Has Some Confusion");
	    break;
   case 2 : strcpy(S,"High Up In The Air And Six Runs!!");
	    strcpy(F,"Powerful Blow And That's Four Runs!!");
	    strcpy(O,"Whoa Direct Hit He's Gone! RUN OUT !");
	    strcpy(D,"Dead Ball! Something Went Wrong There");
	    break;
  }
  gotoxy(5,19);
  if(b==f)
   cprintf(O);
  else if(b==6)
   cprintf(S);
  else if(b==4)
   cprintf(F);
  else if(((b>6)||(b<1))||((f>6)||(f<1)))
   cprintf(D);
 }
};
void Tic()
{
 HScore h,n;
 fstream f;
 player p;
 int win,W,L,T,i,px,sx,s,r;
 char ch,c;
 win=0;
 while(1)
 {
 clrscr();
 W=0,L=0,T=0;
 f.open("Tic.txt",ios::in|ios::binary);
 f.seekg(0);
 f.read((char*)&h,sizeof(h));
 f.close();
 textcolor(133);
 gotoxy(15,5);
 cprintf("Menu");
 gotoxy(10,7);
 textcolor(130);
 cprintf("*******************");
 gotoxy(10,10);
 textcolor(6);
 cprintf("Start Game");
 gotoxy(10,14);
 cprintf("See The High Score");
 gotoxy(10,18);
 textcolor(12);
 cprintf("Exit");
 px=10;
 do
 {
 gotoxy(10,px);
 ch=getch();
  if(ch==72&&px!=10)
   px-=4;
  else if(ch==80&&px!=18)
   px+=4;
 }while(ch!=13);
 if(px==10)
 s=1;
 else if(px==14)
 s=2;
 else
 s=3;
 switch(s)
 {
  case 1 : Start:
	   win=3;
	   p.Prepare();
	   clrscr();
	   cprintf("WELCOME PRESS ANY KEY");
	   getch();
	   while(1)
	   {
	   if(p.play1(1))
	   {
	   win=1;
	   break;
	   }
	   if(p.draw())
	   break;
	   if(p.play1(2))
	   {
	   win=2;
	   break;
	   }
	   }
	   if(win==1)
	   W++;
	   else if(win==2)
	   L++;
	   else
	   T++;
	   if(W==L)
	   {
	    gotoxy(5,15);
	    cprintf("Match Tied So Resume Playing");
	    getch();
	    goto Start;
	   }
	   clrscr();
	   cout<<"\n\nDo You Wish To Continue Playing ?\n\n";
	   gotoxy(5,15);
	   cout<<"Yes";
	   gotoxy(15,15);
	   cout<<"No";
	   sx=5;
	   do
	   {
	    gotoxy(sx,15);
	    c=getch();
	    if(c==75)
	     sx=5;
	    if(c==77)
	     sx=15;
	   }while(c!=13);
	   if(sx==5)
	   goto Start;
	   if(W>L)
	   {
	   n.Won=W;
	   n.Lost=L;
	   r=0;
	   }
	   else
	   {
	   n.Won=L;
	   n.Lost=W;
	   r=1;
	   }
	   n.Tied=T;
	   break;
  case 2 : clrscr();
	   gotoxy(10,5);
	   cprintf("Highscores");
	   gotoxy(7,8);
	   cprintf("*******************");
	   gotoxy(7,11);
	   cprintf("Name           :");
	   cout<<h.Name;
	   gotoxy(7,13);
	   cprintf("Games Won      :");
	   cout<<h.Won;
	   gotoxy(7,15);
	   cprintf("Games Lost     :");
	   cout<<h.Lost;
	   gotoxy(7,17);
	   cprintf("Games Tied     :");
	   cout<<h.Tied;
	   getch();
	   break;
  case 3 : return;
 }
 if(n.Won>h.Won)
 {
  clrscr();
  h=n;
  textcolor(137);
  if(r)
  cprintf("Congrats Player One Has Set A New Record........");
  else
  cprintf("Congrats Player Two Has Set A New Record........");
  cout<<"\n\nEnter Your Name : ";
  gets(h.Name);
 }
 f.open("Tic.txt",ios::out|ios::binary);
 f.seekp(0);
 f.write((char*)&h,sizeof(h));
 f.close();
}
 getch();
}
void Cric()
{
 int s,px,sx,i;
 char ch,ci;
 HScore n,h;
 fstream f;
 Cricket c;
 while(1)
 {
 clrscr();
 n.Won=0,n.Lost=0,n.Tied=0;
 f.open("Cric.txt",ios::in|ios::binary);
 f.seekg(0);
 f.read((char*)&h,sizeof(h));
 f.close();
 textcolor(133);
 gotoxy(15,5);
 cprintf("Menu");
 gotoxy(10,7);
 textcolor(130);
 cprintf("*******************");
 gotoxy(10,10);
 textcolor(6);
 cprintf("Start Game");
 gotoxy(10,14);
 cprintf("See The High Score");
 gotoxy(10,18);
 textcolor(12);
 cprintf("Exit");
 px=10;
 do
 {
 gotoxy(10,px);
 ch=getch();
 if(ch==72&&px!=10)
  px-=4;
 else if(ch==80&&px!=18)
  px+=4;
 }while(ch!=13);
 if(px==10)
 s=1;
 else if(px==14)
 s=2;
 else
 s=3;
 switch(s)
 {
  case 1 :  c.getwick();
	    Start:
	    c.toss();
	    clrscr();
	    textcolor(11);
	    cprintf("\n\nDo You Wish To Continue Playing ?\n\n");
	    gotoxy(5,15);
	    cprintf("Yes");
	    gotoxy(15,15);
	    cprintf("No");
	    sx=15;
	    do
	    {
	     gotoxy(sx,15);
	     ci=getch();
	     if(ci==75)
	      sx=5;
	     if(ci==77)
	      sx=15;
	    }while(ci!=13);
	    if(sx==5)
	    goto Start;
	    n.Won=c.W,n.Lost=c.L,n.Tied=c.T;
	    break;
  case 2 : clrscr();
	   gotoxy(10,5);
	   cprintf("Highscores");
	   gotoxy(7,8);
	   cprintf("*******************");
	   gotoxy(7,11);
	   cprintf("Name           :");
	   cout<<h.Name;
	   gotoxy(7,13);
	   cprintf("Games Won      :");
	   cout<<h.Won;
	   gotoxy(7,15);
	   cprintf("Games Lost     :");
	   cout<<h.Lost;
	   gotoxy(7,17);
	   cprintf("Games Tied     :");
	   cout<<h.Tied;
	   getch();
	   break;
  case 3 : return;
 }
 if(n.Won>h.Won)
 {
  clrscr();
  h=n;
  textcolor(137);
  cprintf("Congrats You Have Set A New Record........");
  cout<<"\n\nEnter Your Name : ";
  gets(h.Name);
 }
 f.open("Cric.txt",ios::out|ios::binary);
 f.seekp(0);
 f.write((char*)&h,sizeof(h));
 f.close();
getch();
}
}
void Type()
{
 randomize();
 fstream f;
 char ch[50],sch[50],c;
 int s,px;
 float time,speed;
 clock_t start,end;
 fstream ft;
 ft.open("TOPSPEED.TXT",ios::binary|ios::in);
 ft.read((char*)&t,sizeof(t));
 ft.close();
 clrscr();
 textcolor(10);
 clrscr();
 gotoxy(17,5);
 cprintf("Menu");
 gotoxy(10,7);
 textcolor(130);
 cprintf("*******************");
 gotoxy(10,10);
 textcolor(6);
 cprintf("Start Game");
 gotoxy(10,14);
 cprintf("See Highscore");
 gotoxy(10,18);
 textcolor(12);
 cprintf("Exit");
 px=10;
 do
 {
 gotoxy(10,px);
 c=getch();
 if(c==72&&px!=10)
  px-=4;
 else if(c==80&&px!=18)
  px+=4;
 }while(c!=13);
 if(px==10)
 s=1;
 else if(px==14)
 s=2;
 else
 s=3;
 switch(s)
 {
  case 1   :  clrscr();
	      textcolor(random(7)+1);
	      cprintf("PRESS ANY KEY TO BEGIN....");
	      getch();
	      clrscr();
	      switch(random(9))
	      {
	       case 1  : strcpy(sch,"Yes I Can And I Will.");
			 break;
	       case 2  : strcpy(sch,"What Is This We Lost.");
			 break;
	       case 3  : strcpy(sch,"Buggatti Veron Is The Fastest.");
			 break;
	       case 4  : strcpy(sch,"Master Blaster Has Set A Record.");
			 break;
	       case 5  : strcpy(sch,"Apple Makes World Class Products.");
			 break;
	       case 6  : strcpy(sch,"Earths Radius Is 6400 Kilometre.");
			 break;
	       case 7  : strcpy(sch,"A Football Team Has 11 Players.");
			 break;
	       case 8 :  strcpy(sch,"Life Is So Beautiful.");
			 break;
	       default : strcpy(sch,"I Like Lamborghinis What A Car.");
	      }
	      cprintf("\r\n\n Start \r\n\n\n");
	      textcolor(random(7)+1);
	      cprintf(sch);
	      cout<<"\n\n";
	      start=clock();
	      gets(ch);
	      end=clock();
	      time=(end-start)/CLK_TCK;
	      if(strcmpi(ch,sch))
	      {
	       textcolor(136+random(7));
	       cout<<"\n";
	       cprintf("Wrong Try Again");
	       delay(2500);
	      }
	      else
	      {
	       cprintf("\r\n\nGood Work....");
	       speed=strlen(ch)/time;
	       cout<<"\n\nTime Is "<<time<<" Seconds\n\nSpeed Is ";
	       cout<<speed<<" Keys Per Second";
	       getch();
	       if((speed>t.tspeed))
	       {
		clrscr();
		t.tspeed=speed;
		textcolor(137);
		cprintf("Congrats You Have Set A New Record........");
		cout<<"\n\nEnter Your Name : ";
		gets(t.Name);
		ft.open("TOPSPEED.txt",ios::binary|ios::out);
		ft.write((char*)&t,sizeof(t));
		ft.close();
	       }
	      }
	      break;
  case 2   :  clrscr();
	      gotoxy(5,5);
	      cout<<"Records\n\n************\n\n";
	      cout<<"Fastest Typer  : "<<t.Name;
	      cout<<"\n\nBest Speed     : "<<t.tspeed;
	      break;
  case 3   :  return;
  default  :  cout<<"\n\nWrong Choice";
 }
 getch();
 Type();
}
void Type2()
{
 while(1)
 {
 randomize();
 fstream f;
 char ch,sch,c;
 int rx,ry,moves=0,px,s;
 float cut=5,mtime=5;
 float time,ttime=0;
 clock_t start,end;
 fstream ft;
 ft.open("MAXTIME.TXT",ios::binary|ios::in);
 ft.read((char*)&x,sizeof(x));
 ft.close();
 clrscr();
 textcolor(133);
 gotoxy(15,5);
 cprintf("Menu");
 gotoxy(10,7);
 textcolor(130);
 cprintf("*******************");
 gotoxy(10,10);
 textcolor(6);
 cprintf("Start Game");
 gotoxy(10,14);
 cprintf("See The High Score");
 gotoxy(10,18);
 textcolor(12);
 cprintf("Exit");
 px=10;
 do
 {
 gotoxy(10,px);
 c=getch();
 if(c==72&&px!=10)
  px-=4;
 else if(c==80&&px!=18)
  px+=4;
 }while(c!=13);
 if(px==10)
 s=1;
 else if(px==14)
 s=2;
 else
 s=3;
 switch(s)
 {
  case 1 :    clrscr();
	      textcolor(random(7)+1);
	      cprintf("PRESS ANY KEY TO BEGIN....");
	      getch();
	      gl:clrscr();
	      gotoxy(5,31);
	      cout<<"Time  : "<<ttime;
	      cout<<"    Last move  : "<<time;
	      cout<<"    No Of Moves  : "<<moves;
	      rx=random(30)+1;
	      ry=random(30)+1;
	      sch=65+random(26)+32*(random(2));
	      gotoxy(rx,ry);
	      cprintf("%c",sch);
	      start=clock();
	      bl:ch=getch();
	      if(ch!=sch)
	      {
	       gotoxy(5,35);
	       cprintf("WRONG!!!!!");
	       delay(cut*250);
	       goto bl;
	      }
	      moves++;
	      end=clock();
	      time=(end-start)/CLK_TCK;
	      ttime+=time;
	      if(time<mtime)
	      mtime=time;
	      switch(moves)
	      {
	       case 15  : cut=4;
			  break;
	       case 35  : cut=3;
			  break;
	       case 75  : cut=2;
			  break;
	       case 125 : cut=1.5;
			  break;
	       case 150 : cut= 1;
			  break;
	       case 200 : cut=.8;
			  break;
	      }
	      if(time>cut)
	      {
	      delay(1000);
	      clrscr();
	      gotoxy(10,10);
	      cprintf("Oops You Were Not Quick Enough\r\n\n");
	      cprintf("\r\n\n             Game Over");
	      }
	      else
	      goto gl;
	      getch();
	      gotoxy(9,20);
	      cout<<"You Survived For "<<ttime<<" Seconds\n\n";
	      cout<<"\tYou Played "<<moves<<" Moves\n\n";
	      cout<<"\tYour Best Move "<<mtime<<" Seconds\n\n\n\n";
	      cprintf("      Well Done ");
	      getch();
	      if((moves>x.Moves))
	       {
		clrscr();
		x.stime=ttime;
		x.Moves=moves;
		textcolor(137);
		cprintf("Congrats You Have Set A New Record........");
		cout<<"\n\nEnter Your Name : ";
		gets(x.Name);
		ft.open("MAXTIME.txt",ios::binary|ios::out);
		ft.write((char*)&x,sizeof(x));
		ft.close();
	       }
	      break;
  case 2:    clrscr();
	     gotoxy(5,5);
	     cout<<"Records\n\n***************\n\n";
	     cout<<"Fastest Typer  : "<<x.Name;
	     cout<<"\n\nBest Time      : "<<x.stime;
	     cout<<"\n\nNo Of Moves    : "<<x.Moves;
	     break;
  case 3:    return;
  default :  cout<<"\n\nWrong Choice";
  }
 getch();
 }
}
void Learning()
{
start:
clrscr();
int px,s;
char ch;
textcolor(10);
clrscr();
gotoxy(17,5);
cprintf("Menu");
gotoxy(10,7);
textcolor(130);
cprintf("*******************");
gotoxy(10,10);
textcolor(6);
cprintf("Type Sprint");
gotoxy(10,14);
cprintf("Type Survival");
gotoxy(10,18);
textcolor(12);
cprintf("Exit");
px=10;
do
{
gotoxy(10,px);
ch=getch();
 if(ch==72&&px!=10)
  px-=4;
 else if(ch==80&&px!=18)
  px+=4;
}while(ch!=13);
if(px==10)
s=1;
else if(px==14)
s=2;
else
s=3;
switch(s)
{
 case 1  : Type();
	   goto start;
 case 2  : Type2();
	   goto start;
 default : break;
 }
}
void piano()
{
 clrscr();
 randomize();
 char a,b,c,d,e,f,g,h,p,m[1];
 a=186,b=205,c=188,d=200,e=201,f=187,g=185,h=203;
 int i,j,x,y,z,l;
 m[0]=14;
 x=3,y=3;
 textcolor(1);
 for(j=1;j<12;++j)
 for(i=0;i<10;++i)
 {
 gotoxy(2+4*j,7+i);
 cout<<a;
 }
 for(i=1;i<12;++i)
 {
 gotoxy(1+4*i,16);
 cout<<b<<c;
 }
 for(i=2;i<12;++i)
 {
  gotoxy(4*i,8);
  l=i-2;
  cout<<l;
 }
 for(j=3;j<16;++j)
 {
 gotoxy(2,j);
 cout<<a;
 }
 gotoxy(2,16);
 cout<<d<<b;
 for(i=3;i<46;++i)
 {
 gotoxy(i,2);
 cout<<b;
 }
 gotoxy(2,2);
 cout<<e;
 gotoxy(46,2);
 cout<<f;
 for(j=0;j<4;++j)
 {
  gotoxy(46,3+j);
  if(j<3)
  cout<<a;
  else
  cout<<g;
 }
 for(i=6;i<46;++i)
 {
  gotoxy(i,6);
  cout<<b;
 }
  gotoxy(6,6);
  cout<<e;
  for(i=0;i<9;i++)
  {
   gotoxy(i*4+10,6);
   cout<<h;
  }
 gotoxy(4,16);
 cout<<b;
 gotoxy(22,4);
 textcolor(4);
 cprintf("VIRTUAL PIANO");
 getch();
 while(1)
 {
  gotoxy(4,4);
  textcolor(129+random(16));
  cprintf(m);
  textcolor(0);
  gotoxy(5,4);
  cprintf("                 ");
  gotoxy(33,4);
  p=getch();
  switch(p)
  {
   case '0' : z=100;
	      break;
   case '1' : z=200;
	      break;
   case '2' : z=300;
	      break;
   case '3' : z=400;
	      break;
   case '4' : z=500;
	      break;
   case '5' : z=600;
	      break;
   case '6' : z=700;
	      break;
   case '7' : z=800;
	      break;
   case '8' : z=900;
	      break;
   case '9' : z=1000;
	      break;
   case  27 : return;
   default  : z=0;
  }
  sound(z);
  delay(200);
  nosound();
}
}
void calculator()
{
float a,b,r;
char ch,s=251;
while(1)
{
clrscr();
textcolor(3);
cout<<"\n\n\t\t";
cprintf("Calculator");
cout<<"\n\n";
cprintf("*******************************************");
cout<<"\n\n\t";
cprintf("+ For Addition");
cout<<"\n\n\t";
cprintf("- For Subtraction");
cout<<"\n\n\t";
cprintf("* For Multiplication");
cout<<"\n\n\t";
cprintf("/ For Division");
cout<<"\n\n\t";
cprintf("^ For Square Root");
cout<<"\n\n\t";
cprintf("Esc For Exit");
cout<<"\n\n";
textcolor(2);
cprintf("Enter Your Choice ");
ch=getch();
switch(ch)
{
 case '+':cout<<"\n\n";
	  cprintf("Enter The Two Numbers");
	  cout<<"\n\n";
	  cin>>a>>b;
	  r=a+b;
	  cout<<"\n\n"<<a<<"\t+\t"<<b<<"\t=\t"<<r;
 break;
 case '-':cout<<"\n\nEnter The Two Numbers\n";
	  cin>>a>>b;
	  r=a-b;
	  cout<<"\n\n"<<a<<"\t-\t"<<b<<"\t=\t"<<r;
 break;
 case '*': cout<<"\n\nEnter The Two Numbers\n";
	   cin>>a>>b;
	   r=a*b;
	   cout<<"\n\n"<<a<<"\t*\t"<<b<<"\t=\t"<<r;
 break;
 case '/': cout<<"\n\nEnter The Two Numbers\n";
	   cin>>a>>b;
	   r=a/b;
	   cout<<"\n\n"<<a<<"\t/\t"<<b<<"\t=\t"<<r;
	   break;
 case '^': cout<<"\n\n";
	   cprintf("Enter Number");
	   cout<<"\n\n";
	   cin>>a;
	   r=sqrt(a);
	   cout<<"\n\n"<<s<<a<<"\t=\t"<<r;
	   break;
 case 27 : return;
 }
 getch();
}
getch();
}
void Extras()
{
 while(1)
 {
  clrscr();
  int px,s;
  char ch;
  textcolor(10);
 clrscr();
 gotoxy(17,5);
 cprintf("Menu");
 gotoxy(10,7);
 textcolor(130);
 cprintf("*******************");
 gotoxy(10,10);
 textcolor(6);
 cprintf("Piano");
 gotoxy(10,14);
 cprintf("Calculator");
 gotoxy(10,18);
 textcolor(12);
 cprintf("Exit");
 px=10;
 do
 {
 gotoxy(10,px);
 ch=getch();
  if(ch==72&&px!=10)
   px-=4;
  else if(ch==80&&px!=18)
   px+=4;
 }while(ch!=13);
 if(px==10)
 s=1;
 else if(px==14)
 s=2;
 else
 s=3;
 switch(s)
  {
   case 1   : piano();
	      break;
   case 2   : calculator();
	      break;
   default  : return;
  }
 getch();
 }
}
class Expenses
{
 float Food,Education,Travel,Entertainment,Medical;
 float Charity,Household,Others,Debts,Rents;
 float Salary,Share,Extra,Tincome,Texpense,Rcash;
 public:
 void Expense()
 {
  clrscr();
  textcolor(2);
  gotoxy(5,5);
  cprintf("Enter Your Food Expenses : ");
  cin>>Food;
  gotoxy(5,7);
  cprintf("Enter Your Educational Expenses : ");
  cin>>Education;
  gotoxy(5,9);
  cprintf("Enter Your Travel Expenses : ");
  cin>>Travel;
  gotoxy(5,11);
  cprintf("Enter Your Medical Expenses : ");
  cin>>Medical;
  gotoxy(5,13);
  cprintf("Enter Your Entertainment Expenses : ");
  cin>>Entertainment;
  gotoxy(5,15);
  cprintf("Enter Your Household Expenses : ");
  cin>>Household;
  gotoxy(5,17);
  cprintf("Enter Charity And Donations Made : ");
  cin>>Charity;
  gotoxy(5,19);
  cprintf("Enter Debts You Paid : ");
  cin>>Debts;
  gotoxy(5,21);
  cprintf("Enter Your Other Expenses : ");
  cin>>Others;
  Texpense=Food+Education+Travel+Medical+Entertainment;
  Texpense+=Household+Charity+Debts+Others;
  getch();
 }
 void Income()
 {
  clrscr();
  textcolor(1);
  gotoxy(5,5);
  cprintf("Enter Your Salary : ");
  cin>>Salary;
  gotoxy(5,7);
  cprintf("Enter Stock Market Shares You Got : ");
  cin>>Share;
  gotoxy(5,9);
  cprintf("Enter Rents You Got : ");
  cin>>Rents;
  gotoxy(5,11);
  cprintf("Enter Extra Incomes : ");
  cin>>Extra;
  Tincome=Salary+Share+Rents+Extra;
  Rcash=Tincome-Texpense;
  getch();
 }
 void Display()
 {
  clrscr();
  textcolor(9);
  gotoxy(5,3);
  cprintf(" Your Total Expenses ");
  gotoxy(5,5);
  cprintf("Food Expenses          : ");
  cout<<Food;
  gotoxy(5,7);
  cprintf("Educational Expenses   : ");
  cout<<Education;
  gotoxy(5,9);
  cprintf("Travel Expenses        : ");
  cout<<Travel;
  gotoxy(5,11);
  cprintf("Medical Expenses       : ");
  cout<<Medical;
  gotoxy(5,13);
  cprintf("Entertainment Expenses : ");
  cout<<Entertainment;
  gotoxy(5,15);
  cprintf("Household Expenses     : ");
  cout<<Household;
  gotoxy(5,17);
  cprintf("Charity And Donations  : ");
  cout<<Charity;
  gotoxy(5,19);
  cprintf("Debts                  : ");
  cout<<Debts;
  gotoxy(5,21);
  cprintf("Your Other Expenses : ");
  gotoxy(5,25);
  cprintf("Total Expense  : ");
  cout<<Texpense;
  textcolor(11);
  gotoxy(35,3);
  cprintf(" Your Total Incomes ");
  gotoxy(35,5);
  cprintf("Salary               : ");
  cout<<Salary;
  gotoxy(35,7);
  cprintf("Stock Market Shares  : ");
  cout<<Share;
  gotoxy(35,9);
  cprintf("Rents You Got        : ");
  cout<<Rents;
  gotoxy(35,11);
  cprintf("Extra Incomes        : ");
  cout<<Extra;
  gotoxy(35,25);
  cprintf("Total Income  : ");
  cout<<Tincome;
  gotoxy(20,30);
  textcolor(14);
  if(Rcash>0)
  {
  cprintf("Total Money You Have  : ");
  cout<<Rcash;
  }
  else
  {
  cprintf("Total Money You Owe   : ");
  cout<<-Rcash;
  }
  getch();
 }
}A;
void Exp()
{
fstream f;
int px,s;
char ch;
do
{
textcolor(10);
clrscr();
gotoxy(17,5);
cprintf("Menu");
gotoxy(10,7);
textcolor(130);
cprintf("*******************");
gotoxy(10,10);
textcolor(6);
cprintf("Add New Transactions");
gotoxy(10,14);
cprintf("See Last Transactions");
gotoxy(10,18);
textcolor(12);
cprintf("Exit");
px=10;
do
{
gotoxy(10,px);
ch=getch();
 if(ch==72&&px!=10)
  px-=4;
 else if(ch==80&&px!=18)
  px+=4;
}while(ch!=13);
if(px==10)
s=1;
else if(px==14)
s=2;
else
s=3;
switch(s)
{
case 1  : clrscr();
	  A.Expense();
	  A.Income();
	  f.open("Expense.txt",ios::binary|ios::out);
	  f.write((char*)&A,sizeof(A));
	  f.close();
	  A.Display();
	  break;
case 2  : clrscr();
	  f.open("Expense.txt",ios::binary|ios::in);
	  f.read((char*)&A,sizeof(A));
	  f.close();
	  A.Display();
	  break;
default : return;
}
}while(1);
getch();
}
void Dir()
{
 int c,fo,v,px;
 char ch,s[30];
 fstream f,g;
 while(1)
 {
  clrscr();
  gotoxy(10,3);
  textcolor(9);
  cprintf("Main Menu");
  gotoxy(7,5);
  textcolor(140);
  cprintf("**************");
  textcolor(14);
  gotoxy(7,7);
  cprintf("Add New Contact");
  gotoxy(7,9);
  cprintf("Veiw All");
  gotoxy(7,11);
  cprintf("Search A Contact");
  gotoxy(7,13);
  cprintf("Delete A Contact");
  textcolor(4);
  gotoxy(7,15);
  cprintf("Exit");
  px=7;
  textcolor(10);
  do
  {
  gotoxy(7,px);
  ch=getch();
  if(ch==72&&px!=7)
   px-=2;
  else if(ch==80&&px!=15)
   px+=2;
  }while(ch!=13);
  c=(px-7)/2+1;
  switch(c)
  {
   case 1   : a.Add();
	      f.open("Tel.txt",ios::app);
	      f.write((char*)&a,sizeof(a));
	      f.close();
	      break;
   case 2   : f.open("Tel.txt",ios::in);
	      f.seekg(0);
	      clrscr();
	      Q:
	      f.read((char*)&a,sizeof(a));
	      if(!f.eof())
	      {
	       a.Show();
	       goto Q;
	      }
	      f.close();
	      break;
   case 3   : clrscr();
	      fo=0;
	      gotoxy(5,3);
	      cprintf("Enter Contact To be Searched   :");
	      gets(s);
	      f.open("Tel.txt",ios::in);
	      f.seekg(0);
	      clrscr();
	      R:
	      f.read((char*)&a,sizeof(a));
	      if(!f.eof())
	      {
	       if(strcmpi(s,a.Name)==0)
	       {
		clrscr();
		gotoxy(5,3);
		cprintf("Contact Found");
		getch();
		a.Show();
		fo++;
	       }
	       goto R;
	      }
	      f.close();
	      gotoxy(5,3);
	      if(!fo)
	      cprintf("\Contact Not Found");
	      getch();
	      break;
   case 4   : clrscr();
	      fo=0;
	      g.open("Temp.txt",ios::out);
	      gotoxy(5,3);
	      cprintf("Enter Contact To be Deleted   :");
	      gets(s);
	      f.open("Tel.txt",ios::in);
	      f.seekg(0);
	      g.seekp(0);
	      T:
	      f.read((char*)&a,sizeof(a));
	      if(!f.eof())
	      {
	       if(strcmpi(s,a.Name)==0)
	       {
		clrscr();
		gotoxy(5,3);
		cprintf("Contact Found");
		getch();
		a.Show();
		gotoxy(5,11);
		cprintf("Are You Sure You Want To Delete This ?");
		gotoxy(5,13);
		cout<<"Yes";
		gotoxy(15,13);
		cout<<"No";
		v=15;
		do
		{
		 gotoxy(v,13);
		 ch=getch();
		 if(ch==75)
		  v=5;
		 if(ch==77)
		  v=15;
		}while(ch!=13);
		gotoxy(5,15);
		if(v==15)
		{
		 g.write((char*)&a,sizeof(a));
		 cprintf("Ok.Contact Not Deleted");
		 getch();
		}
		else
		{
		 cprintf("Ok.Contact Deleted");
		 getch();
		}
		fo++;
	       }
	       else
		g.write((char*)&a,sizeof(a));
	       goto T;
	      }
	      clrscr();
	      g.close();
	      f.close();
	      remove("Tel.txt");
	      rename("Temp.txt","Tel.txt");
	      gotoxy(5,3);
	      if(!fo)
	      cprintf("Contact Not Found");
	      getch();
	      break;
   case 5   : return;
  }
 }
}
void Utilities()
{
 start:
 clrscr();
 int px,s;
 char ch;
 textcolor(10);
 clrscr();
 gotoxy(17,5);
 cprintf("Menu");
 gotoxy(10,7);
 textcolor(130);
 cprintf("*******************");
 gotoxy(10,10);
 textcolor(6);
 cprintf("Telephone Directories");
 gotoxy(10,14);
 cprintf("Expense Calculator");
 gotoxy(10,18);
 textcolor(12);
 cprintf("Exit");
 px=10;
 do
 {
 gotoxy(10,px);
 ch=getch();
  if(ch==72&&px!=10)
   px-=4;
  else if(ch==80&&px!=18)
   px+=4;
 }while(ch!=13);
 if(px==10)
 s=1;
 else if(px==14)
 s=2;
 else
 s=3;
 switch(s)
 {
  case 1  : Dir();
	    goto start;
  case 2  : Exp();
	    goto start;
  default : break;
  }
 }
void Games()
{
start:
clrscr();
int s,px;
char ch;
textcolor(10);
clrscr();
gotoxy(17,5);
cprintf("Menu");
gotoxy(10,7);
textcolor(130);
cprintf("*******************");
gotoxy(10,10);
textcolor(6);
cprintf("Tic Tac Toe");
gotoxy(10,14);
cprintf("Pim Pom Piss");
gotoxy(10,18);
textcolor(12);
cprintf("Exit");
px=10;
do
{
gotoxy(10,px);
ch=getch();
 if(ch==72&&px!=10)
  px-=4;
 else if(ch==80&&px!=18)
  px+=4;
}while(ch!=13);
if(px==10)
s=1;
else if(px==14)
s=2;
else
s=3;
switch(s)
{
 case 1  : Tic();
	   goto start;
 case 2  : Cric();
	   goto start;
 default : break;
 }
}
void Password()
{
 char cho[10],c;
 int i,j,k,l;
 j=2;
 A:
 i=0;
 textcolor(11);
 strcpy(cho,"Password!!");
 strset(cho,'\0');
 clrscr();
 while(1)
 {
  clrscr();
  gotoxy(33,21);
  cprintf("Enter The Password");
  gotoxy(30,30);
  cout<<"No Of Chances Left : "<<j;
  gotoxy(37,23);
  for(k=0;k<i;k++)
  cout<<"*";
  c=getch();
  if(c==13)
  break;
  if(isalpha(c))
  {
   cho[i]=c;
   i++;
  }
  if((c==8)&&(i!=0))
  {
   cho[i]='\0';
   i--;
  }
 }
 for(l=0;l<6;++l)
 {
  textcolor(15);
  gotoxy(34,25);
  cprintf("* * * * * *");
  textcolor(1);
  gotoxy(34+2*l,25);
  cprintf("*");
  gotoxy(32,27);
  cprintf("Verifying Password");
  delay(275);
 }
 clrscr();
 gotoxy(32,27);
 if(strcmpi(cho,"Secrets")==0)
  cout<<"Password Verified";
 else
 {
  cout<<"Wrong Password";
  getch();
  j--;
  if(j+1)
   goto A;
  exit(0);
 }
 getch();
 for(k=14;k>0;k--)
 {
  gotoxy(k+30,29);
  delay(30);
  cout<<"_";
 }
 for(k=1;k<5;k++)
 {
  gotoxy(31,30-k);
  delay(30);
  cout<<"|";
 }
 for(k=0;k<17;k++)
 {
  gotoxy(k+32,25);
  delay(30);
  cout<<"_";
 }
 for(k=0;k<6;k++)
 {
  gotoxy(49,k+26);
  delay(30);
  cout<<"|";
 }
 for(k=10;k>0;k--)
 {
  gotoxy(k+38,31);
  delay(30);
  cout<<"_";
 }
}
void Blink(char A[30],int x,int y)
{
 int i;
 for(i=0;A[i]!='\0';++i)
 {
  textcolor(129+random(15));
  gotoxy(x+i,y);
  cprintf("%c",A[i]);
 }
}
void About()
{
 int i;
 clrscr();
 getch();
 textcolor(6);
 for(i=1;i<170;++i)
 {
  if(i<=25)
  {
   gotoxy(i,5);
   cprintf("Developed");
  }
  if((i>25)&&(i<=62))
  {
   gotoxy(96-i,5);
   cprintf("By");
  }
  if((i>62)&&(i<=77))
  {
   gotoxy(25,i-58);
   cprintf("Developed By");
  }
  if((i>77)&&(i<=104))
  {
   gotoxy(i-76,21);
   cprintf("Chris");
  }
  if((i>104)&&(i<=147))
  {
   gotoxy(175-i,23);
   cprintf("Sison");
  }
  if((i>147)&&(i<=165))
  {
   gotoxy(28,190-i);
   cprintf("Georty");
  }
  if(i==62)
   getch();
  delay(30);
 }
 getch();
 delay(1500);
 clrscr();
 Blink("Developed By",25,19);
 delay(1500);
 Blink("Chris",28,23);
 delay(1500);
 Blink("Sison",28,26);
 delay(1500);
 Blink("Georty",28,29);
 delay(1500);
 getch();
}
void main()
{
 int s,px,ppx,i,j=2,k,l;
 char ch;
 Password();
 getch();
 while(1)
 {
  px=10;
  do
  {
   clrscr();
   textcolor(11);
   struct date d;
   struct time t;
   getdate(&d);
   gotoxy(15,27);
   cprintf("The Current Date Is    :   %d / %d / %d",d.da_day,d.da_mon,d.da_year);
   gotoxy(25,5);
   cprintf("Life Utility Program");
   gotoxy(11,8);
   textcolor(140);
   cprintf("**********************************************");
   textcolor(3);
   gotoxy(10,15);
   cprintf("Utility");
   gotoxy(20,15);
   cprintf("Typing");
   gotoxy(30,15);
   cprintf("Games");
   gotoxy(40,15);
   cprintf("Extra");
   gotoxy(50,15);
   cprintf("About Us");
   textcolor(14);
   gotoxy(12,32);
   cprintf("------------------------------------------------");
   gotoxy(12,35);
   cprintf("ARROWS TO SCROLL : ENTER TO SELECT : ESC TO EXIT");
   textcolor(10);
   gettime(&t);
   gotoxy(15,25);
   cprintf("The Current  Time Is   :   %2d:%02d",t.ti_hour, t.ti_min);
   gotoxy(px-1,15);
   textcolor(132);
   cprintf(">");
   ch=getch();
   if((ch==72||ch==75)&&px!=10)
    px-=10;
   else if((ch==80||ch==77)&&px!=50)
    px+=10;
   else if(ch==27)
   {
    textcolor(130);
    for(i=1;i<11;++i)
    {
     clrscr();
     textcolor(i);
     gotoxy(25,25-i);
     cprintf("Thanks For Using");
     delay(500);
    }
    gotoxy(1,1);
    for(i=1;i<4000;++i)
    {
     textcolor(i%8);
     cprintf(".");
     delay(1);
    }
    exit(0);
   }
  }while(ch!=13);
  if(px==10)
   s=1;
  else if(px==20)
   s=2;
  else if(px==30)
   s=3;
  else if(px==40)
   s=4;
  else
   s=5;
  switch(s)
  {
   case 1  : Utilities();
	     break;
   case 2  : Learning();
	     break;
   case 3  : Games();
	     break;
   case 4  : Extras();
	     break;
   case 5  : About();
	     break;
  }
 }
}