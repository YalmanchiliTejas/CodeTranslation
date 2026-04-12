#define rep(i,n) REP(i,0,n)
#define REP(i, a, b) for(int i = a; i < (int)(b); i++)
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
template<class T> inline void chmax(T &a, const T &b) {if(a < b) a = b;}
template<class T> inline void chmin(T &a, const T &b) {if(a > b) a = b;}
const long long INF = 1LL<<60;

const ll MAXN = (ll)3e3+10;
const ll DIV = (ll)1e9+7;
// ll dp[MAXN][MAXN];

ll dp[MAXN][MAXN];
vector<int> A;
ll Update(int l, int r) {
   if (dp[l][r] != -INF) return dp[l][r];
   if (l==r) dp[l][r] = A[l];
   else {
      chmax(dp[l][r],A[l]-Update(l+1,r));
      chmax(dp[l][r],A[r]-Update(l,r-1));
   }
   return dp[l][r];
}

int main(void) {
   int N;
   cin>>N;
   A.resize(N);
   rep(i,N) cin>>A[i];
   rep(i,MAXN) rep(j,MAXN) dp[i][j] = -INF;
   rep(i,N/2) Update(i,N-i);
   cout<<Update(0,N-1)<<endl;


   return 0;
}