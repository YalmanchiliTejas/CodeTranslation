#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vvin=vector<vin>;
using vll=vector<ll>;
using vvll=vector<vll>;
using vst=vector<string>;
using P = pair<ll,ll>;
const int inf=1e9+7;
const ll INF=9e18;
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

ll dp[3300][3300];//dp[i][j]=[i,j)の最大値
bool flag[3300][3300];
ll a[3300];

ll f(int l,int r){
  if(flag[l][r])return dp[l][r];
  flag[l][r]=1;
  if(l==r){
   return dp[l][r]=0; 
  }
  return dp[l][r]=max(a[l]-f(l+1,r),a[r-1]-f(l,r-1));
}

int main(){cout<<fixed<<setprecision(20);
		   int n;
           cin>>n;
           rep(i,0,n)cin>>a[i];
           cout<<f(0,n)<<endl;;
}