#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

ll solve(ll n,ll x,ll sum){
  if(sum==1){
    return 1;
  }
  if(x==1){
    return 0;
  }else if(x<=(sum-3)/2+1){
    return solve(n-1,x-1,(sum-3)/2);
  }else if(x==(sum-3)/2+2){
    return solve(n-1,(sum-3)/2,(sum-3)/2)+1;
  }else if(x==sum){
    return 2*solve(n-1,(sum-3)/2,(sum-3)/2)+1;
  }else{
    return solve(n-1,(sum-3)/2,(sum-3)/2)+1+solve(n-1,x-2-(sum-3)/2,(sum-3)/2);
  }
}

int main()
{
  ll N,X;
  cin >> N >> X;

  ll sum=1;
  REP(i,N){
    sum=2*sum+3;
  }

  cout << solve(N,X,sum) << endl;
}