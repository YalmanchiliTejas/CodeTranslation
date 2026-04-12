#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pld pair<long double, int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define ff first
#define ss second
#define SZ(x) ((int)(x).size())
#define ld long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int M = 1e9 + 7;
const int MAXN = 2e5+100;
int N;
ll a[MAXN];

void read(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }
}

void solve(){
    read();
    vector<ll> prefix(N+1, 0);
    for(int i = 1; i <= N; i++){
        prefix[i] = (prefix[i-1] + a[i]) % M;
    }
    ll ans = 0;
    for(int i = N; i > 0; i--){
        ans = (ans + ((prefix[i-1] * a[i]) % M))%M;
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

