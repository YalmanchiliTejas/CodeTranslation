#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<iomanip>
#include<cstdio>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007
#define MAXS(x,y) (x = max(x,y))
#define MINS(x,y) (x = min(x,y))

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;


int N;

ll memo[3001][3001];
ll a[3001];

ll dp(int l , int r, int t){
  if(memo[l][r] != INF)return memo[l][r];

  if(l==r){
    if(t%2==0){
      return memo[l][r] = a[l];
    }else{
      return memo[l][r] = -a[l];
    }
  }

  if(t%2==0){
    return memo[l][r] = max(dp(l+1, r, t+1) + a[l], dp(l, r-1, t+1) + a[r]);
  }else{
    return memo[l][r] = min(dp(l+1, r, t+1) - a[l], dp(l, r-1, t+1) - a[r]);
  }
}

int main(){
  cin >> N;

  REP(i,N)cin >> a[i];
  REP(i,3000)REP(j,3000)memo[i][j]=INF;

  ll ans = dp(0,N-1,0);

  cout << ans << endl;
}