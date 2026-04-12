#include <bits/stdc++.h>
int N,M,a,b,d[64]={},v[8]={1};
int dfs(int x) {
int r=0,l=1;
for(int i=0;i<N;i++)if(!v[i])l=0;
if(l)return 1;
for(int i=0;i<N;i++)if(d[x*N+i]&!v[i])v[i]=1,r+=dfs(i),v[i]=0;
return r;
}
int main(){
std::cin>>N>>M;
for(int i=0;i<M;i++)std::cin>>a>>b,d[--a*N+--b]=d[b*N+a]=1;
std::cout<<dfs(0);
}