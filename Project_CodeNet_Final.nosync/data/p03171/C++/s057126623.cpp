#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stdio.h>
#include <stack>
#include <queue>
#include <deque>
#include <numeric>
#include <bits/stdc++.h>
#include <utility>
#include <iomanip>

#define ALL(obj) (obj).begin(), (obj).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,a,b) for(int i = (a); (b) <= i; i--)
#define REP(i,n) for(int i = 0; i < (n); i++)
#define RREP(i,n) for(int i = n; n <= i; i--)
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define elif else if
#define MOD 1000000007
#define INF (1<<29)

using namespace std;

#define ld long double
#define ll long long

map <int ,int> mpa,mpb;
typedef pair<ll, ll> P;
priority_queue<P, vector<P>, greater<P>> pque;



int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  ll a[3010];
  for(int i=0;i<N;i++){
    cin >> a[i];
  }
  ll dp[3010][3010];
  for(int i=0;i<N;i++){
    dp[i][i]=0;
  }
  for(int len=1;len<=N;len++){
    for(int i=0;i+len<=N;i++){
      int j=i+len;
      if((N-len)%2==0){
        dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j-1]);
      }else{
        dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j-1]);
      }
    }
  }
  cout << dp[0][N] << endl;
  return 0;
}
