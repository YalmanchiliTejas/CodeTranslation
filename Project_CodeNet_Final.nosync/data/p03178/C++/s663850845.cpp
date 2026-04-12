#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
#define int ll
#define pb push_back
#define sz(i) (int)(i.size())
#define fi first
#define se second
#define ld long double
#define pii pair<int, int>
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
const int inf = 0x3f3f3f3f3f3f3f3LL;
const int mod = 1e9 + 7;
using namespace std;
#ifndef ONLINE_JUDGE
#define tr(...) {__l(__LINE__);__f(#__VA_ARGS__, __VA_ARGS__);}
inline void __l(int line) { cerr << "#" << line << ": "; }template <typename Arg1>
void __f(const char* name, Arg1&& arg1){cerr << name << " : " << arg1 << std::endl;}template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args){const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);}
#else
#define tr(...)
#endif
template<class T> void smin(T& a, T val) {if (a > val) a = val;}template<class T> void smax(T& a, T val) {if (a < val) a = val;}template<typename T>inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v){bool first = true;os << "[";for(auto i: v){if(!first)os << ", ";os << i;first = false;}return os << "]";}
const int N = 5*1e5 + 10;
// make sure N size is correctttt!!!!!!!!!

string s;
int d;

int si, dp[10000+10][100+10];

// 1 => tight
// 0 => restrictless

int dfs(int idx, int f, int rem){
   if(idx <= -1){
      return (rem == 0);
   }

   if(f == 0 and dp[idx][rem] != -1){
      return dp[idx][rem];
   }

   int lim = (f) ? (s[idx]-'0') : 9;
   int ans = 0;

   for (int i = 0; i <= lim; ++i)
   {
      int nf = ((s[idx]-'0') == i) ? f : 0;
      ans += dfs(idx-1, nf, (rem+i)%d);  
      ans %= mod;
   }

   if (f == 0)
      dp[idx][rem] = ans; 
   return ans;
}

int32_t main(){_
   cin>>s;
   cin>>d;
   memset(dp, -1, sizeof dp);

   si = sz(s);
   reverse(s.begin(), s.end());//MSB is on si-1

   cout<<(dfs(si-1,1,0)-1+mod)%mod;

   //make sure N size is correct!!!!!!!!!
   return 0;
}
/*
15545748545646573454135
100
*/