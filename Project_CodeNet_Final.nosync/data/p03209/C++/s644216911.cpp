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
#include<bits/stdc++.h>
#include <utility>

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
using ll = long long;
map <int ,int> mpa,mpb;
typedef pair<ll, ll> P;
priority_queue<P, vector<P>, greater<P>> pque;

ll s[55],p[55];
ll N,X;

ll dfs(ll a,ll b){
  if(a==0)return 1;
  if(b==1)return 0;
  if(b<=s[a-1]+1) return dfs(a-1,b-1);
  if(b==s[a-1]+2) return p[a-1]+1;
  if(b==s[a-1]*2+3) return p[a];
  else return p[a-1]+1+dfs(a-1,b-2-s[a-1]);
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> X;
  s[0]=1LL,p[0]=1LL;
  for(int i=0;i<N;i++){
    s[i+1]=s[i]*2+3;
    p[i+1]=p[i]*2+1;
  }

  cout << dfs(N,X) << endl;
  return 0;
}