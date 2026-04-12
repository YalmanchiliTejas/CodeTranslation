#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <unordered_map>
#include <map>
//#include <queue>
//#include <cstring>

//#include <bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}


#define MOD		1000000007
#define ll		unsigned long long int
#define pll		pair<ll, ll>
#define pb		push_back
#define endl	"\n"
#define f 		first
#define s 		second
#define fastio 	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define all(v)  (v).begin(), (v).end()
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)

//ll power(ll x, ll y) { ll ans = 1; x; while (y) {if (y & 1)ans = (x * ans); x = (x * x); y >>= 1;} return ans;}
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};



void solve() {
    ll n, m, x;

    cin >> n >> x >> m;
    
    if(n == 1) {
        cout << x << endl;
        return;
    }

    map<ll, ll> mp;

    ll pref[m + 10];

    pref[0] = 0;

    ll i = 2;

    pref[1] = x;

    for(; i <= n; i++) {
        x *= x;
        x %= m;

        pref[i] = pref[i - 1] + x;
        //debug(x, pref[i]);
        if(mp[x]) {
            break;
        } else {
            mp[x] = i;
        }
    }

    ll ans = pref[mp[x]];

    if(i <= n) {
        ans = pref[mp[x] - 1];
        ll rem = n - mp[x] + 1;
        ll btw = i - mp[x];

        ans += ((rem/btw) * (pref[i - 1] - pref[mp[x] - 1]));

        ans += ((pref[mp[x] - 1 + (rem % btw)] - pref[mp[x] - 1]));
    }



    cout << ans << endl;

}

int main() {
    fastio;
    solve();
}
