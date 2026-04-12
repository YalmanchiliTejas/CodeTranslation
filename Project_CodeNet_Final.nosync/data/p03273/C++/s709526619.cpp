#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int h,w,cnt=0,k=0;
   char ch;
   string s="\0",str[105];
   scanf("%d %d",&h,&w);
   for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
        cin>>ch;
       if(ch=='.'){
        cnt++;
       }
     s+=ch;

    }
    if(cnt!=w){
       str[k++]=s;
    }
    s="\0";
    cnt=0;
   }
   cnt=0;
   for(int i=0;i<w;i++){
    for(int j=0;j<k;j++){
     if(str[j][i]=='.'){
        cnt++;
     }
    // printf("j %d i %d\n",j,i);
    }
    if(cnt==k){
        for(int r=0;r<k;r++){
            str[r][i]='1';////////
        }
    }
    cnt=0;
   }
   for(int p=0;p<k;p++){
     for(int i=0;i<w;i++){
        if(str[p][i]!='1'){
            printf("%c",str[p][i]);
        }
     }
     printf("\n");
   }

    return 0;
}
