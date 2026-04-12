#include<iostream>
#include<cstdio>
using namespace std;
int main(){
  string ope;
 char a[101][1001];
 int n;
 int now[101];
 int p,q;
 for(int i=0;i<101;i++)now[i]=0;
 cin>>n;
 while(true){
   cin>>ope;
   if(ope=="quit")break;
   if(ope=="push"){cin>>p;
     now[p]++;
     cin>>a[p][now[p]];
   }
   if(ope=="move"){
     cin>>p>>q;
     now[q]++;
     a[q][now[q]]=a[p][now[p]];
     now[p]--;
   }
   if(ope=="pop"){
     cin>>p;
     cout<<a[p][now[p]]<<endl;
     now[p]--;
   }
 }
}