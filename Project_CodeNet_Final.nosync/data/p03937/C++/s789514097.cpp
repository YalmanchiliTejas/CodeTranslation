#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T&a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T&a,T b){if(a>b){a=b;return 1;}return 0;}
typedef long long ll;

int n,m,k,h,w;
string s,t;
string a[10];

int main() {
  cin >> h >> w;
  rep(i,h) cin >> a[i];
  int cnt=0;
  rep(i,h)rep(j,w)if(a[i][j]=='#') cnt++;
  cout << (cnt==h+w-1 ? "Possible" : "Impossible") << endl;
}