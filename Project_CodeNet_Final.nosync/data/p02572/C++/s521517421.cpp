/**
 * author: BueVonHun 🐼🎋
 * More Info: https://github.com/Bue-von-hon
**/

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>

typedef long long ll;
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define m_p make_pair
#define pii pair<int,int>
#define piii pair<int,pii>
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define X first
#define Y second
#define rep(i, n) for (int i = 0; i < (n); i++)

template <class T> T _min(T a,T b){return (a<b ? a : b);}
template <class T> T _max(T a,T b){return (a>b ? a : b);}
template<class T> void read(T& x) {cin >> x;}

int tc;
int main(void) {
    fast_cin();

    ll n;
    read(n);
    vt<ll> s(n);
    ll sol = 0, mod = 1e9+7;
    for (ll i = 0; i < n; i++) {
        ll temp;
        read(temp);
        s[i]=temp;
    }
    int ans = 0, x = 0;
    rep(i, n) {
        ans = (ans+(s[i]*x))%mod;
        x = (x+(s[i]))%mod;
    }
    cout << ans;
    return 0;
}
