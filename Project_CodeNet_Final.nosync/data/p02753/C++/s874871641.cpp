#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define repe(i,n) for (int i = 0; i <= (n); ++i)
#define repe1(i,n) for (int i = 0; i <= (n); ++i)
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(k,v) emplace_back(k,v)
#define ct(res) cout << res << "\n";
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
const int INF = 1e9;
const ll mod = 1000000007;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a * b / gcd(a, b);}
 
ll pow_kai(ll a, ll n) {
    ll x = 1;
    while(n > 0) {
        if(n&1) {
            x = x*a;
        }
        a = a*a;
        n >>= 1;
    }
    return x;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    if (s=="AAA" || s=="BBB") {
        ct("No");
    }
    else {
        ct("Yes");
    }

}