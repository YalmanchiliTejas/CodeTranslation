#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define rep2(i,n) for(int i=0;i<=n;i++)
#define repr(i,a,n) for(int i=a;i<n;i++)
#define all(a) a.begin(),a.end()
#define P pair<long long,long long>
#define double long double
#define vector2(a,b,c) vector<vector<int>> a(b/*縦！w*/,vector<int>(c/*横！w*/))
#define INF 1e10
#define MOD 1e9+7
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;
signed main(){
  int a,b;
  cin>>a>>b;
  if(a==b)
    cout<<"Yes";
  else
    cout<<"No";
}