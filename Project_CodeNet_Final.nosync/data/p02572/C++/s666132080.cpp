#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ***********************************/

const int mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <ll> A(n), suff(n+1, 0);
    for (ll &i: A) cin >> i;   
    for (int i = n-1; i >= 0; --i) {
        suff[i] = A[i];
        if (i < n-1) (suff[i] += suff[i+1]) %= mod;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        (ans += A[i] * suff[i+1]) %= mod;
    }

    cout << ans;


    return 0;
}

