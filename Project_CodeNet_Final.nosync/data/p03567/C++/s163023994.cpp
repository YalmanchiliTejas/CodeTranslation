#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
     char s[10];
     int k=0;
     scanf("%s",s);
     for(int i=0;i<strlen(s);i++)
     {
          if(s[i]=='A'&&s[i+1]=='C')
          {
               k=1;
               break;
          }
     }
     if(k==1)
          printf("Yes\n");
     else
          printf("No\n");
     return 0;
}