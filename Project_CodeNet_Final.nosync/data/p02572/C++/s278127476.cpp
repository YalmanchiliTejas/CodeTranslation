#include <bits/stdc++.h>

#define all(X) (X).begin(), (X).end()
#define ll long long
#define linf (1ll << 60)

using namespace std;

// -------- FUNCS -------- //
vector<string> SPLIT(string str,char ch){vector<string> res;stringstream ss(str);string s;while(getline(ss, s, ch))res.push_back(s);return res;}
ll STOI(string str,int base){ll res=0;for(auto c:str){res*=base;res+=c-'0';}return res;}
string ITOS(ll val,int base){string res;while(val>0){res+='0'+(val%base);val/=base;}reverse(all(res));return res;}


// -------- Main Code -------- //
int n;
vector<ll> mem;
vector<ll> arr;
ll mod = 1e9+7;

ll pm(ll x, ll y, ll mod) {
    ll res = 1;
    x = x % mod;
    while (y > 0) {
        if ((y & 1) == 1) res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}


ll dfs() {
    ll res = 0;
    
    ll sum = arr[n-1]; 
    for (int i=n-2; i>=0; i--) {
        ll t = sum * arr[i] % mod;
        sum += arr[i];
        sum %= mod;
        res += t;
        res %= mod;
    }

    return res;

    // ll sum = 0;
    // for (auto u: arr) {
    //     sum += u; 
    // }
    // ll sum_sq = pm(sum, 2, mod);
    // // cout << sum_sq << '\n';
    // ll res = sum_sq;
    // ll t = 0;
    // for (auto u : arr) {
    //     t += u * u;
    //     // if (res < t) {
    //     //     ll toAdd = t - res;
    //     //     res += ceil(1.0 * toAdd / mod) * mod;
    //     //     // res += mod;
    //     // } 
    //     // res -= t;
    //     t %= mod;
    // }
    // // cout << res << '\n';

    // return (res - t + mod) / 2; 
} 


void runcase() {
    cin >> n; 
    arr.resize(n, 0);
    for (auto& u : arr) cin >> u;
    sort(all(arr));
    ll res = dfs() % mod;
    cout << res << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t;
    // cin >> t;
    // while (t-- > 0)
        runcase();
    return 0;
}
