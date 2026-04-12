#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;
string to_string(string s) {
  return '"' + s + '"';
}
string to_string(const char* s) {
  return to_string((string) s);
}
string to_string(bool b) {
  return (b ? "true" : "false");
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#ifndef ONLINE_JUDGE
#define show(...) cerr << "[" << #__VA_ARGS__ << "] :", debug_out(__VA_ARGS__)
#else
#define show(...) 42
#endif
#define f first
#define s second
#define endl "\n"
#define pb push_back
#define  oo 0x3f3f3f3f
#define limit 1000000007
#define two pair<int,int>
#define mod(x,m) ((x%m+m)%m)
#define all(v) v.begin(),v.end()
#define max3(x,y,z) max(x,max(y,z))
#define min3(x,y,z) min(x,min(y,z))
#define int long long int
#define fori(x,n) for(int i = x; i < n; i++)
#define forj(y,m) for(int j = y; j < m; j++)
#define fork(z,p) for(int k = z; k < p; k++)
#define speedforces std::ios::sync_with_stdio(false)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define input_from_file  freopen("input.txt", "r", stdin);

int dp[3005][3005];

int fun(int i,int j,vector<int> &v){
  if(i > j || j < 1 || i > v.size()) return 0;
  if(i == j) return dp[i][i] = v[i];
  if(dp[i][j] != -1) return dp[i][j];
  dp[i][j] = min(fun(i+2,j,v),fun(i+1,j-1,v))+v[i] ;
  return dp[i][j] = max(dp[i][j],min(fun(i+1,j-1,v),fun(i,j-2,v))+v[j]);
}

signed main(){
  //input_from_file;
  speedforces;
  int n; cin>>n;
  vector<int> v(n+1);
  memset(dp,-1,sizeof dp);
  int sum = 0;
  fori(1,n+1) cin>>v[i] , sum += v[i];
  cout<<2*fun(1,n,v)-sum<<endl;
}
