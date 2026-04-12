#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <map>
#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define INF 1000000000000000
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;

ll dfs(ll n, ll x){
  if(n==0) return 1;
  if(x<0) return (1LL<<(n+1))-1;
  if(x==1) return 0;
  if(x>1&&x<(1LL<<(n+1))-1) return dfs(n-1,x-1);
  if(x==(1LL<<(n+1))-1) return dfs(n-1,-1)+1;
  if(x>(1LL<<(n+1))-1&&x<(1LL<<(n+2))-3) return dfs(n-1,-1)+1+dfs(n-1,x-2-((1LL<<(n+1))-3));
  else return dfs(n-1,-1)+1+dfs(n-1,-1);
}

int main(){
  ll n,x;
  cin >> n >> x;
  cout << dfs(n,x) << endl;
  return 0;
}
