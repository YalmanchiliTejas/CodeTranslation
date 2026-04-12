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
const int N = 3*1e3 + 10;
// make sure N size is correctttt!!!!!!!!!

int dp[N][N][2], a[N], n;

int solve(int idx1, int idx2, int person){
   if(idx1 > idx2){
      return 0;
   }
   int &ans = dp[idx1][idx2][person];
   if(ans != -1){
      return ans;
   }
   if(person == 0){
      ans = max(a[idx1]+solve(idx1+1, idx2, 1^person), a[idx2]+solve(idx1, idx2-1, 1^person));
   }
   else{
      ans = min(-a[idx1]+solve(idx1+1, idx2, 1^person), -a[idx2]+solve(idx1, idx2-1, 1^person));
   }
   return ans;
}

int32_t main(){_

   cin>>n;
   for (int i = 0; i < n; ++i)
   {
      cin>>a[i];
   }

   memset(dp, -1, sizeof dp);
   cout<<solve(0,n-1,0);

   //make sure N size is correct!!!!!!!!!
   return 0;
}