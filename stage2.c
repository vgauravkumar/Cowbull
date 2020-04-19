//Though at first the game is just of 3 digits, but you'll have to make it for many digits even.
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int digit(int a)
{
   int i=1;
    while(a/10!=0)
    {
        i++;
        a=a/10;
    }
    return i;
}

/*void sleep()
{
   int i = 0;
   while (i < 1e8)  { i++; }
}*/
int getnum(int n)
{
    int a,b;
    srand(time(0));//    sleep();
    int arr[n];
    phirse:
    for(int i=0;i<n;i++)
    {
        int a=rand()%10;
        if(a==0) i=i-1;
        else arr[i]=a;
    }
    for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           if (i!=j)
           {
               if(arr[i]==arr[j])
               goto phirse;
           }
           else break;
       }
   }
    for(int i=0;i<n;i++)
    for(int i=0;i<n;i++)
    {
        if(i==0){b=arr[i];}else{b=(b+(arr[i]*pow(10,i)));}
    }
    return b;
}
void cowbull(int a,int x,int n)
{
    int arr1[n],arr2[n];
    for(int i=(n-1);i>=0;i--)
    {
        arr1[i]=a%10;
        a=a/10;
    }
    for(int i=(n-1);i>=0;i--)
    {
        arr2[i]=x%10;
        x=x/10;
    }
    int cow=0,bull=0;
    for(int i=0;i<n;i++)
    {
        if(arr1[i]==arr2[i])
        {bull=bull+1;}
    }
    for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           if(i!=j)
           {
               if(arr2[i]==arr1[j])cow=cow+1;
               else{continue;}
           }
       }
   }
    printf("Cow = %d Bull = %d",cow,bull);
}
void main()
{
   system("cls");
   int n;
   start:
   printf("Enter the difficulty level starting from 3 upto 9...");
   scanf("%d",&n);
   printf("GAURAV'S GUESS GAME\n\nThe motive of this game is to read mind of the PC.\nCow is used for match of the digit in the number but not at exact place.\nBull is used if the digit matches at exact places.\nIf you want to give up, give your guess as 0.\n\nRULES:\n1. Enter the %d digited number as your guess.\n2. The numer should be a non zero number.\n3. The digits of the number should not repeat.\n\nIf at any moment you feel like quiting the game just enter 0 as your guess.",n);
   int x,c=0,b,a=0,d,e[n],z,g=0;
   x=getnum(n);
   while(a!=x)
   {
   again:
   printf("\n\nEnter your guess...");
   scanf("%d",&a);
   d=a;
   z=a;
   if(d<0){printf("ERROR!!!");goto again;}//************BUG**************
   if(d!=0||z!=0)
   {
   for(int i=0;i<n;i++)
   {
//       if(d%10==0){printf("ERROR!!!");goto again;}
        d=d/10;
        if(d==0&&i<(n-1)){printf("ERROR!!!");goto again;}
        if(i==(n-1)&&d!=0){printf("ERROR!!!");goto again;}
         }
   for(int i=0;i<n;i++)
   {
       e[i]=z%10;
       if(z%10==0){printf("ERROR!!!");goto again;}
       z=z/10;
       
   }
   //Now it is the program to check weather any of the elements in the number dosen't matches...
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           if (i!=j)
           {
               if(e[i]==e[j])
               {printf("ERROR!!!");goto again;}
           }
           else break;
       }
   }
   }
   if(a==000)
   {
       printf("%d was the number. You lost...",x);
       c=1;
       break;
   }//else if(a==-231){printf("%d",x);}         ***********BUG*********** will be valid for any negetive number.
   cowbull(a,x,n);
   g=g+1;
   }
   if(c==0)
   {
        if(g<=5){g=100;} else if(g<=10)g=90;else if(g<=15)g=80;else if(g<=20)g=70;else if(g<=25)g=60;else if(g<=30)g=50;else if(g<=35)g=40;else if(g<=40)g=30;else if(g<=45)g=20;else if(g<=50)g=10;else g=0;
         printf("\n\n\n!!!Congratulations!!!\n  !!!!!YOU WON!!!!!\n\nYour score is  %d\n\nIf you want to play again, press 1 or else press any key to exit...",g);
         int h;
         scanf("%d",&h);
         if(h==1)goto start;
   }
}