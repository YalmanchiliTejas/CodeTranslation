#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define all(x) x.begin() , x.end()
int const N = 101;
int n , m ;
char g[N][N];
int main(){
   // freopen("input.txt","r",stdin);
   scanf("%d%d",&n,&m);
   for(int i=0;i<n;++i){
       cin>>g[i];
   }
  // vector<int>row , col ;
   bool row[N] = {} , col[N]={};
   int x = 0 ;
   for(int i=0;i<n;++i){
       int cnt=0;
       for(int j=0;j<m;++j){
           if(g[i][j]=='.')++cnt;
       }
       if(cnt==m){row[i]=true;++x;}
   }
   for(int j=0;j<m;++j){
       int cnt=0;
       for(int i=0;i<n;++i){
           if(!row[i]){
               if(g[i][j]=='.')++cnt;
           }
           else if(row[i])continue ;
       }
     //  cout<<cnt<<"\n";
       if(cnt>=n-x)col[j]=true;
   }

   for(int i=0;i<n;++i){
       if(!row[i]){
       for(int j=0;j<m;++j){
           if(!col[j])
             cout<<g[i][j];
       }
       cout<<endl;
   }
   }
 } 