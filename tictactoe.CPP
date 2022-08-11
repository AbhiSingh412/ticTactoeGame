#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
using namespace std;

void exite();
void graphics(char matfg[][3], int);
int allfilled(char matfall[][3], int);
void squarecheck(char matfs[][3], int);
char checkwin(char matfch[][3], int);
void humantick(char matfh[][3], int nh=3)
{   	    int xh;
	    cout <<"Human's turn!!\n";
	    cout <<"Enter where to tick as X (1-9):\n";
	    cin >> xh;
		if(xh==1)matfh[0][0]='X';

		if(xh==2)matfh[0][1]='X';

		if(xh==3)matfh[0][2]='X';

		if(xh==4)matfh[1][0]='X';

		if(xh==5)matfh[1][1]='X';

		if(xh==6)matfh[1][2]='X';

		if(xh==7)matfh[2][0]='X';

		if(xh==8)matfh[2][1]='X';

		if(xh==9)matfh[2][2]='X';
}
void opponhtick(char matfo[][3], int no=3)
{
	int xo;
	cout <<"\nOpponent's turn(Human 2)!!"<<endl;
	cout <<"Enter where to tick as 0 (1-9):\n";
	cin >> xo;

		if(xo==1)matfo[0][0]='0';

		if(xo==2)matfo[0][1]='0';

		if(xo==3)matfo[0][2]='0';

		if(xo==4)matfo[1][0]='0';

		if(xo==5)matfo[1][1]='0';

		if(xo==6)matfo[1][2]='0';

		if(xo==7)matfo[2][0]='0';

		if(xo==8)matfo[2][1]='0';

		if(xo==9)matfo[2][2]='0';

}
void oppontick(char matfo[][3], int no=3)
{
	int xo;
	char temp_o;
	cout <<"\nOpponent's turn!!(computer)"<<endl;
	do
	{
	    xo=(rand()%(10-1)) + 1;
	    if(xo==1)
		temp_o=matfo[0][0];
	    if(xo==2)
		temp_o=matfo[0][1];
	    if(xo==3)
		temp_o=matfo[0][2];
	    if(xo==4)
		temp_o=matfo[1][0];
	    if(xo==5)
		temp_o=matfo[1][1];
	    if(xo==6)
		temp_o=matfo[1][2];
	    if(xo==7)
		temp_o=matfo[2][0];
	    if(xo==8)
		temp_o=matfo[2][1];
	    if(xo==9)
		temp_o=matfo[2][2];

	 }  while(temp_o != '\0');
	 if(xo==1)matfo[0][0]='0';

	 if(xo==2)matfo[0][1]='0';

	 if(xo==3)matfo[0][2]='0';

	 if(xo==4)matfo[1][0]='0';

	 if(xo==5)matfo[1][1]='0';

	 if(xo==6)matfo[1][2]='0';

	 if(xo==7)matfo[2][0]='0';

	 if(xo==8)matfo[2][1]='0';

	 if(xo==9)matfo[2][2]='0';
	 cout <<"Opponent ticked on "<<xo<<endl;
}
int main()
{    system("cls");
	 int wine, ch;
     char mat[3][3];
     for(int i=0; i<3; i++)
     {
	for(int j=0; j<3; j++)
	{
	    mat[i][j]='\0';
	}
     }
     cout <<"------------Welcome to Play Tic-Tac-Toe Game------------\n\n";
     graphics(mat, 3);
     cout <<"\nHow you want to play?\n";
     cout <<"1. Human Vs Human\n";
     cout <<"2. Human Vs Computer\n";
     cout <<"3. Exit\n";
     cout <<"Enter your choice(1-3):\n";
     cin >> ch;
     if(ch==1){do
	     {	humantick(mat, 3);
		squarecheck(mat, 3);
		opponhtick(mat, 3);
		graphics(mat, 3);
		squarecheck(mat, 3);
	     }  while(1 == 1);
	     }
     if(ch==2){do
	     {	humantick(mat, 3);
		squarecheck(mat, 3);
		oppontick(mat, 3);
		graphics(mat, 3);
		squarecheck(mat, 3);
	     }  while(1 == 1);
	     }
     if(ch==3){cout <<endl<<"Exiting...";
	     exit(0);}
     getch();
}
void graphics(char matfg[][3], int ng=3)
{
     cout <<"\t\t\t\t"<<matfg[0][0]<<" |  "<<matfg[0][1]<<" | "<<matfg[0][2]<<"\n";
     cout <<"\t\t\t       --- --- ---\n";
     cout <<"\t\t\t\t"<<matfg[1][0]<<" |  "<<matfg[1][1]<<" | "<<matfg[1][2]<<"\n";
     cout <<"\t\t\t       --- --- ---\n";
     cout <<"\t\t\t\t"<<matfg[2][0]<<" |  "<<matfg[2][1]<<" | "<<matfg[2][2]<<"\n";
     cout <<"\n\n";
}
int allfilled(char matfall[][3], int nal=3)
{
     int all_f=1;
     for(int alli=0 ; alli<3 ; alli++)
     {
	for(int allj=0 ; allj<3 ; allj++)
	{
	    if(matfall[alli][allj]=='\0')
		all_f=0;
	}
     }
     return all_f;
}
void squarecheck(char matfs[][3], int nas=3)
{       char win;
	int all_fill = allfilled(matfs, 3);
	if(all_fill==1)
	{
	   win = checkwin(matfs, 3);
	   if(win==1)
	   {	cout <<"\nGame Is DRAW...";
		exite();
	   }
	   else
	   {
		cout <<"\n"<< win <<" WINS!!";
		exite();
	   }
	}
	else
	{
	    win = checkwin(matfs, 3);
	    if(win != '1')
	    {	cout <<"\n"<< win <<" WINS!!";
		exite();
	    }
	}
}
char checkwin(char matfch[][3], int nac=3)
{
	char winch='1';
	if(matfch[0][0]==matfch[1][0] && matfch[1][0]==matfch[2][0])
	{
	   winch=matfch[0][0];
	   if(winch=='\0')
		winch='1';
	}
	else if(matfch[2][0]==matfch[2][1] && matfch[2][1]==matfch[2][2])
	{
	   winch=matfch[2][0];
	   if(winch=='\0')
		winch='1';
	}
	else if(matfch[2][2]==matfch[1][2] && matfch[1][2]==matfch[0][2])
	{
	   winch=matfch[2][2];
	   if(winch=='\0')
		winch='1';
	}
	else if(matfch[0][0]==matfch[0][1] && matfch[0][1]==matfch[0][2])
	{
	   winch=matfch[0][0];
	   if(winch=='\0')
		winch='1';
	}
	else if(matfch[1][0]==matfch[1][1] && matfch[1][1]==matfch[1][2])
	{
	   winch=matfch[1][0];
	   if(winch=='\0')
		winch='1';
	}
	else if(matfch[0][1]==matfch[1][1] && matfch[1][1]==matfch[2][1])
	{
	   winch=matfch[0][1];
	   if(winch=='\0')
		winch='1';
	}
	else if(matfch[0][0]==matfch[1][1] && matfch[1][1]==matfch[2][2])
	{
	   winch=matfch[0][0];
	   if(winch=='\0')
		winch='1';
	}
	else if(matfch[2][0]==matfch[1][1] && matfch[1][1]==matfch[0][2])
	{
	   winch=matfch[2][0];
	   if(winch=='\0')
		winch='1';
	}
	return winch;
}
void exite()
{
	char name[20], feed[100];
	cout <<"\nEnter your name:(max 20 characters)"<<endl;
	cin>>name;
	system("cls");
	cout <<"\nEnter your feedback:(max 80 characters)"<<endl;
	gets(feed);
	exit(0);
}
