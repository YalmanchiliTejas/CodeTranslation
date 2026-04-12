#include<iostream>
#include<stdio.h>
#include<fstream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<map>
#include<iomanip>
#include<cassert>
#include<complex>
#include<functional>
#include<list>
#include<cmath>
#include<stack>
#include<assert.h>
#define LL long long
#define PB push_back
#define MP make_pair
#define PII pair<int,int>
#define F first
#define S second
using namespace std;
LL t[55],p[55];
LL n,k;
LL ans;
void dfs(LL x,LL m){
  if(m==0)
    return;
  if(x==0){
  	ans++;
  	return;
  }
  if(m>=t[x]-1){
  	ans+=p[x];
  	return;
  }
  if(m>=t[x-1]+2){
  	ans+=p[x-1]+1;
  	dfs(x-1,m-t[x-1]-2);
  }
  else
    dfs(x-1,m-1);
}
int main(){
  cin>>n>>k;
  t[0]=1;
  p[0]=1;
  for(LL i=1;i<=n;i++){
  	t[i]=2*t[i-1]+3;
  	p[i]=2*p[i-1]+1;
  }
  dfs(n,k);
  cout<<ans;
  return 0;
}