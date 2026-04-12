#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using ll = long long;
#define ull unsigned ll
#define endl "\n"
#define vi vector<int>
#define vl vector<ll>
#define all(v) (v).begin(),(v).end()
#define mst(a,b) memset(a,b,sizeof(a))
#define pi pair<int,int>
#define pl pair<ll, ll>
#define ppi pair<int, pii>
#define mt make_tuple
#define eb emplace_back
using namespace std;

const ll N = 2e5 + 5, mod = 1e9 + 7;
const ll inf = 1e18;

bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b){
    if(a.F == b.F) return a.S < b.S;
    return a.F > b.F;
}
ll power(ll x, ll p){
    ll r = 1ll;
    x = x % mod;
    while(p > 0){
        if(p & 1) r = (r * x) % mod;
        p = p >> 1;
        x = (x * x) % mod;
    }
    return r;
}

void solve(){
    int x;
    cin >> x;
    if(x >= 30){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);//cout.tie(0);
    /*#ifndef ONLINE_JUDGE
        freopen("Input.txt", "r", stdin);
    #endif*/
    //freopen("running_on_fumes_chapter_1_input (1).txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    int t = 1, p;
    //cin >> t;
    for(p = 1; p <= t; p++){
        //cout << "Case #" << p << ": ";
        solve();
    }
    return 0;
}

