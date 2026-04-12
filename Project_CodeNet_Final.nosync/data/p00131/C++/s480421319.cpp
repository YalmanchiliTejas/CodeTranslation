#include<bits/stdc++.h>
#define l(i,n) for(int i=0;i<n;i++)
using namespace std;
bool m[12][12],c[12][12],d[12][12],q;
int main(){int n;cin>>n;l(u,n){l(i,10)l(j,10)cin>>m[i][j];
bool f[10],t[10]={0};for(int p=1;p<=1024;p++){
l(i,10)f[i]=t[i];l(i,10)l(j,10)c[i][j]=m[i][j];l(k,10){l(i,10)
if(f[i]){for(int j=max(0,i-1);j<=min(9,i+1);j++)c[k][j]^=1;c[k+1][i]^=1;}
l(i,10)d[k][i]=f[i];l(i,10)f[i]=c[k][i];}q=0;l(i,10)q|=f[i];
if(!q){l(i,10){l(j,10){if(j)cout<<" ";cout<<d[i][j];}cout<<endl;}
break;}l(i,10)if(p%(int)pow(2,i)==0)t[i]^=1;
}}return 0;}