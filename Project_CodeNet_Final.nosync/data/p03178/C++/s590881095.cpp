#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//namespaces
using namespace __gnu_pbds; 
using namespace std;

//MACROS
#define ld long double
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long 
#define For(i,s,e) for (int i=(s); i<(e); i++)
#define Fod(i,s,e) for (int i=(s); i>=(e); i--)
#define pii pair<ll,ll>
#define f first
#define s second
#define endl "\n"
#define all(container) container.begin(), container.end()
#define mp make_pair

//debug
#define TRACE
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//Templates
template <typename T>
using ordered_set =tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T> ostream& operator << (ostream &os, const set<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const pair<T, S> &v) { os << v.first << ' ' << v.second; return os; }
template <class T, class S> ostream& operator << (ostream &os, const unordered_map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; }

//globals
ll const prime1 = 304933;
ll const prime2 = 15486277;
ll const mod = 1e9+7;
ll const inf = 1e18;
ll const size_1d = 1e4 + 7;
ll const size_2d = 1e3 + 7;

//functions
ll power(ll x, ll y, ll mod = 2e18){ ll ans = 1;x %= mod;while(y){if(y&1)ans = (x * ans) % mod;x = (x * x) % mod;y >>= 1;}return ans;}
ll modInverse(ll a, ll m){ll m0 = m;ll y = 0, x = 1;if (m == 1) return 0;while (a > 1){ ll q = a / m;ll t = m;m = a % m,a = t;t = y;y = x - q * y;x = t;}if(x < 0) x += m0;return x;} 
ll gcdext(ll a,ll b,ll *x = 0, ll *y = 0){if(a == 0){*x = 0;*y = 1;return b;}ll x1,y1;ll gcd1 = gcdext(b%a,a,&x1,&y1);*x = y1 - (b/a)*x1;*y = x1;return gcd1;}
int randomize(){return (rand()%10000);} 

// CODE STARTS HERE
ll dp[2][size_1d][101];
ll recur(int tight,int i1,int sum,std::vector<int> &digits,int d){
    if(i1 == digits.size() && sum == 0){ 
        return 1;
    }
    if(i1 == digits.size())
        return 0;
    if(dp[tight][i1][sum] != -1)
        return dp[tight][i1][sum];
    ll k = !tight ? 9 : digits[i1];
    ll ans = 0; 
    For(i,0,k + 1){
        if(tight && i == digits[i1])
            ans += recur(1,i1 + 1,(sum + i)%d,digits,d);
        else
            ans += recur(0,i1 + 1,(sum + i)%d,digits,d);
        ans %= mod;
    }
    dp[tight][i1][sum] = ans;
    return ans;
}

int main(){
    IOS

    For(i,0,2){
        For(j,0,size_1d){
            For(z,0,101){
                dp[i][j][z] = -1;
            }
        }
    }

    string s;cin >> s;
    std::vector<int> digits;
    int d;cin >> d;
    For(i,0,s.length()){
        digits.pb(s[i] - '0');
    }
    cout << (recur(1,0,0,digits,d)- 1 + mod)%mod << endl;

    return 0;
}