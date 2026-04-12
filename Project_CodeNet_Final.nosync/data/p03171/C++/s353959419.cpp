#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>

#define REP(i,n) for(long long i=0;i<n;++i)
#define REPR(i,n) for(long long i=n;i>=0;--i)
#define REPI(itr,v) for(auto itr=v.begin();itr!=v.end();++itr)
#define REPIR(itr,v) for(auto itr=v.rbegin();itr!=v.rend();++itr)
#define FOR(i,a,b) for(long long i=a;i<b;++i)
#define SORT(v,n) sort(v, v+n)
#define SORTV(v) sort(v.begin(), v.end())
#define ALL(v) v.begin(),v.end()
#define llong long long
#define INF 999999999
#define MOD 1000000007
#define pb push_back
#define pf push_front
#define MP make_pair
#define SV(v) {for(long long sitr=0;sitr<v.size();++sitr){cin>>v[sitr];}}

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

using namespace std;

typedef pair<int,int> pii;

llong dp[3010][3010];

int main(){

  int n;
  cin >> n;

  vector<llong> v(n);
  REP(i,n){
    cin >> v[i];
  }

  for(int len = 1; len <= n; ++len){
    for(int i = 0; i + len <= n; ++i){
      int j = len + i;
      if((n - len) % 2 == 0){
          if(i + 1 == n - 1)
            dp[i][j] = v[i];
          else
            dp[i][j] = max(dp[i+1][j] + v[i], dp[i][j-1] + v[j-1]);
      }else{
          if(i + 1 == n - 1)
            dp[i][j] =  - v[i];
          else
            dp[i][j] = min(dp[i+1][j] - v[i], dp[i][j-1] - v[j-1]);
      }
    }
  }

  /*
  ///これは遷移おかしい
  REP(i,n){
    for(int j = i; j <= n; ++j){
      if(j == 0) continue;
      int len = j - i;

      if((n - len) % 2 == 0){
        if(i+1 == n){
          dp[i][j] = dp[i][j-1] + v[j-1];
        }
        else
          dp[i][j] = max(dp[i+1][j] + v[i], dp[i][j-1] + v[j-1]);
      }else{
        if(i + 1 == n)
          dp[i][j] = dp[i][j-1] - v[j-1];
        else
          dp[i][j] = min(dp[i+1][j] - v[i], dp[i][j-1] - v[j-1]);
      }
    }
  }
  */
  cout << dp[0][n] << endl;
  
  return 0;
}

