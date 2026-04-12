#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
   int n,i;
   int dice0,dice1,dice2;
   string m;
   int ans;

   for(;;){
      cin>>n;
      if(n==0) break;
      
      ans=1;dice0=1,dice1=2,dice2=3;
      for(i=0;i<n;i++){
         cin>>m;
      
         if(m=="North"){
            ans+=dice1;
            dice0=7-dice0;
            swap(dice0,dice1);
         }
         else if(m=="East"){
            ans+=7-dice2;
            dice2=7-dice2;
            swap(dice0,dice2);
         }
         else if(m=="South"){
            ans+=7-dice1;
            dice1=7-dice1;
            swap(dice0,dice1);
         }
         else if(m=="West"){
            ans+=dice2;
            dice0=7-dice0;
            swap(dice0,dice2);
         }  
         else if(m=="Right"){
            ans+=dice0;
            dice1=7-dice1;
            swap(dice1,dice2);
         }
         else if(m=="Left"){
            ans+=dice0;
            dice2=7-dice2;
            swap(dice1,dice2);
         }
      }
      printf("%d\n",ans);
   }
   return 0;
}