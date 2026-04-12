#define rep(i, a, b) for(int i = a; i < (int)(b); i++)
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
template<class T> inline void chmax(T &a, const T &b) {if(a < b) a = b;}
template<class T> inline void chmin(T &a, const T &b) {if(a > b) a = b;}
const long long INF = 1LL<<60;
const long long MOD = (ll)1e9+7;
const long long MAX = (ll)1e5+100;



int main(void) {
   ll N;
   cin>>N;
   vector<ll> s(N);
   rep(i,0,N) cin>>s[i];

   ll ans = 0;
   rep(C,1,N-1) {
      ll cad = 0;
      rep(n,0,(int)(N-1)/C) {
         ll A = N-1 - C*n;
         cad += s[A] + s[C*n];
         if (A <= C*n && A%C == 0) continue;
         chmax(ans,cad);
      }
   }
   cout<<ans<<endl;




   return 0;
}