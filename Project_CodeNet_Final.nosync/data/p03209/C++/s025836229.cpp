#include<bits/stdc++.h>
using namespace std;

long dfs(long n,long x){
  ///cout<<n<<" "<<x<<" "<<x-((1<<(n+1))-3+2)<<endl;
  //レベルnのを下からx食べていくつPがあるか
  if(x==0)return 0;
  if(n==0)return(x==0?0:1);
  if(x==(((long)1<<(n+2))-3)) return -1+((long)1<<(n+1));
  if(x<((long)1<<n+1)-3+2)return dfs(n-1,x-1);
  else if(x==((long)1<<n+1)-3+2)return -1+((long)1<<(n))+1;
  else return dfs(n-1,((long)1<<(n+1))-3)+1+dfs(n-1,x-(((long)1<<(n+1))-3+2));
}
int main(){
  long N,X;cin>>N>>X;
  cout<<dfs(N,X)<<endl;
}