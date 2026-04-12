#include <bits/stdc++.h>
using namespace std;int main(){long n,s,a,k,j,m=998244353,d[3001]={};cin>>n>>s;for(;n--;){cin>>a;for(j=s;j>=a;j--)d[j]=(d[j]+d[j-a])%m;d[a]++;d[0]++;k+=d[s];}cout<<k%m;}