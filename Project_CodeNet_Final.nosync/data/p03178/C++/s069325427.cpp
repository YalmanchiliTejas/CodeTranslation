#include "bits/stdc++.h"
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
#define int long long int
#define mod(x,m) ((x%m+m)%m)
#define ll long long
#define two pair<int,int>
#define all(v) v.begin(),v.end()
#define max3(x,y,z) max(x,max(y,z))
#define min3(x,y,z) min(x,min(y,z))
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define fastio std::ios::sync_with_stdio(false)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define input_from_file  freopen("input.txt", "r", stdin);

// zero included
int d, ans;
int dp[10005][5][105];
string k;

int getans(int i, int f, int s){
  if(dp[i][f][s] != -1) return dp[i][f][s];
  if(k.size() == i){
    if(s%d == 0) { return dp[i][f][s] = 1; }
    return 0;
  }
  int curr = 0;
  int no = k[i]-'0';
  if(f == 1){
   curr = getans(i+1,1,(s+no)%d)%limit;
   for(int j=0;j<no;j++)
   curr += getans(i+1,0,(s+j)%d), curr %= limit;
  }
  else {
   for(int j=0;j<10;j++)
   curr += getans(i+1,0,(s+j)%d), curr %= limit;
 }
 return dp[i][f][s] = curr;
}

signed main(){
 //input_from_file;
 cin>>k>>d;
 ans = 0;
 memset(dp,-1,sizeof dp);
 cout<<((getans(0,1,0)-1)%limit+limit)%limit<<endl;
}
