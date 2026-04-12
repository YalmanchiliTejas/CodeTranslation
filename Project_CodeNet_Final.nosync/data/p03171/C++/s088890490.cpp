#include <bits/stdc++.h>
#define int long long int
using namespace std;
template<typename T,typename U> using P=pair<T,U>;
template<typename T> using V=vector<T>;
template<typename T>bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}

template<typename T>auto&operator<<(ostream&s,const vector<T>&v){s<<"[";bool a=1;for(auto e:v){s<<(a?"":" ")<<e;a=0;}s<<"]";return s;}
template<typename T,typename U>auto&operator<<(ostream&s,const pair<T,U>&p){s<<"("<<p.first<<","<<p.second<<")";return s;}
template<typename T>auto&operator<<(ostream&s,const set<T>&st){s<<"{";bool a=1;for(auto e:st){s<<(a?"":" ")<<e;a=0;}s<<"}";return s;}
template<typename T,typename U>auto&operator<<(ostream&s,const map<T,U>&m){s<<"{";bool a=1;for(auto e:m){s<<(a?"":" ")<<e.first<<":"<<e.second;a=0;}s<<"}";return s;}
#define DUMP(x)  cerr<<#x<<" = "<<(x)<<endl;

struct edge { int to, cost; };

const int INF = 1e18;
const int MOD = 1e9+7;

signed main()
{
   int n; cin >> n;
   V<int> a(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }

   V<V<int>> dp(n+1, V<int>(n+1));
   for (int i = n-1; i >= 0; i--) {
      for (int j = n-1; j >= 0; j--) {
         if (i + j >= n) continue;

         if ((i + j) % 2 == 0) {
            dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j+1] + a[n-1-j]);
         } else {
            dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j+1] - a[n-1-j]);
         }
      }
   }
   cout << dp[0][0] << endl;

   return 0;
}
