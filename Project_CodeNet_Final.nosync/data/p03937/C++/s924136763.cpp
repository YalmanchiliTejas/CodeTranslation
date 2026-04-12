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
#define DUMP(x) cout<<#x<<" = "<<(x)<<endl
#define COUT(x) cerr<<#x<<" = "; cout<<(x)<<endl

struct edge { int to, cost; };

const int INF = 1e18;
const int MOD = 1e9+7;

signed main()
{
   int H, W; cin >> H >> W;
   V<string> A(H);
   map<char,int> cnt;
   for (int i = 0; i < H; i++) {
      cin >> A[i];
      for (int j = 0; j < W; j++) {
         cnt[A[i][j]]++;
      }
   }

   if (cnt['#'] != H+W-1) {
      cout << "Impossible" << endl;
      return 0;
   }

   for(int i = 0, j = 0; i != H-1 || j != W-1;) {
      if (i != H-1 && A[i+1][j]) {
         i++; continue;
      }
      if (j != W-1 && A[i][j+1]) {
         j++; continue;
      }
      cout << "Impossible" << endl;
      return 0;
   }
   cout << "Possible" << endl;

   return 0;
}
