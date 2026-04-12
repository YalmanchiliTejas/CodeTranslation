#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <complex>
#include <vector>
#include <limits>
#include <iomanip>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define debug(x) cout << #x << " = " << (x) << endl;
#define rep(i, n) for(int i = 0;i < n;i++)
#define repr(i, n) for(int i = n-1;i >= 0;i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second

const long double pi = 3.141592653589793;
const int mod = 1e9 + 7;

int dp[6011][6011], N, A[6011], hlp[2022][2022], hlp2[2022][2022];

bool cost(int &a, int &b,int &c) {
  return (a == b) && (b == c) && (a == c);
}

void updateDP(int &i, int &j, int &a, int &b, int &c, int &d, int &e) {
  dp[a][b] = max(dp[a][b], dp[i][j]+cost(A[c], A[d], A[e]));
}

int separate(int grp) {
  int xin = 3*grp-1;
  int yin = xin + 1, zin = xin + 2;
  if(A[xin] == A[yin]) return zin;
  if(A[xin] == A[zin]) return yin;
  return xin;
}
pair<int,int> solver(int grp, int val) {
  int xin = 3*grp-1;
  int yin = xin + 1, zin = xin + 2;
  if(A[xin] == val) return {yin,zin};
  if(A[yin] == val) return {xin,zin};
  return {xin,yin};
}

int main() {

 // freopen("input.in","r",stdin);
 // freopen("output.out","w",stdout);

 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);

 int M;
 cin>>M;
 cin>>A[N++];
 cin>>A[N++];
 int x,y,z,tans=0;
 rep(j, M-1) {
   cin>>x>>y>>z;
   if(cost(x,y,z)) {tans++;continue;}
   A[N++]=x;
   A[N++]=y;
   A[N++]=z;
 }
 cin>>A[N++];
 N /= 3;

 rep(i, N+2) rep(j, N+2) hlp[i][j] = hlp2[i][j]= -1;

 for(int i = 2;i+1 < 3*N;i+=3) {
   int grp = (i+1)/3;
   int x = A[i], y = A[i+1], z = A[i+2];
   hlp2[x][grp]=grp;
   hlp2[y][grp]=grp;
   hlp2[z][grp]=grp;
   if(x != y && y != z && x != z) continue;
   if(x == y) hlp[x][grp]=grp;
   if(x == z) hlp[x][grp]=grp;
   if(z == y) hlp[y][grp]=grp;
 }

 for(int i = 1;i <= N;i++) {
   for(int j = N-1;j >= 1;j--) {
     if(hlp[i][j] == -1) hlp[i][j] = hlp[i][j+1];
     if(hlp2[i][j] == -1) hlp2[i][j] = hlp2[i][j+1];
   }
 }

 int ans = 0;
 for(int i = 0;i < 3*N-1;i++) {
   for(int j = i+1;j < 3*N-1;j++) {
     ans = max(ans, dp[i][j] + cost(A[i], A[j], A[3*N-1]));
     int grp = 1 + (j+1)/3;
     if(grp >= N) continue;
     int xin = 3*grp-1;
     int yin = xin + 1, zin = xin + 2;
     updateDP(i,j,i,xin,j,yin,zin);
     updateDP(i,j,i,yin,j,xin,zin);
     updateDP(i,j,i,zin,j,xin,yin);
     updateDP(i,j,j,xin,i,yin,zin);
     updateDP(i,j,j,yin,i,xin,zin);
     updateDP(i,j,j,zin,i,xin,yin);
     updateDP(i,j,xin,yin,i,j,zin);
     updateDP(i,j,xin,zin,i,j,yin);
     updateDP(i,j,yin,zin,i,j,xin);
     
     if(A[i] == A[j]) {
       int a = hlp2[A[i]][grp];
       if(a == -1) continue;
       auto x = solver(a, A[i]);
       int ii = x.F, jj = x.S;
       dp[ii][jj] = max(dp[ii][jj], 1+dp[i][j]);
       continue;
     }

     int a = hlp[A[i]][grp];
     int b = hlp[A[j]][grp];
     if(a == -1 && b == -1) {
      continue;
     }
     if(a == -1) {
       int in = separate(b);
       dp[i][in] = max(dp[i][in], 1+dp[i][j]);
       continue;
     }
     if(b == -1) {
       int in = separate(a);
       dp[j][in] = max(dp[j][in], 1+dp[i][j]);
       continue;
     }
     if(a < b){
       int in = separate(a);
       dp[j][in] = max(dp[j][in], 1+dp[i][j]);
       continue;
     }
     int in = separate(b);
     dp[i][in] = max(dp[i][in], 1+dp[i][j]);
   }

 }

 // rep(i,3*N) {
 //   rep(j,3*N) cout<<dp[i][j] <<" ";cout<<endl;
 // }

  cout << ans+tans << endl;

 return 0;
}
