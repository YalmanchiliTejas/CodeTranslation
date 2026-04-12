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

const ll N_MAX=3010;
ll a[N_MAX];
ll dp[N_MAX][N_MAX][3];

ll solve(int p,int q,int r){
  if(dp[p][q][r]!=-1) return dp[p][q][r];
  if(p>q) return 0;
  if(r){
    dp[p][q][r]=max(solve(p+1,q,0)+a[p],solve(p,q-1,0)+a[q]);
  }else if(r==0){
    dp[p][q][r]=min(solve(p+1,q,1)-a[p],solve(p,q-1,1)-a[q]);
  }
  return dp[p][q][r];

}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll N;
  cin >> N;

  //ll k;
  for(int i=1;i<=N;i++){
    cin >> a[i];
    //a.push_back(k);
  }

  for(int i=0;i<N_MAX;i++){
    for(int j=0;j<N_MAX;j++){
      dp[i][j][0]=dp[i][j][1]=-1;
    }
  }
  //1が太郎
  cout << solve(1,N,1) << endl;
  return 0;
}