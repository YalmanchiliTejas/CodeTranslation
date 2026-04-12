#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define endl "\n"
#define ar array
#define pb push_back
#define sz(X) ((int)(X).size())
#define pcnt __builtin_popcount
#define sort_unique(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define get_pos(c, x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define all(X) (X).begin(), (X).end()
#define ms(c,x)  memset(c,x,sizeof c)
#define  No cout<<"NO"<<endl;
#define  Yes cout<<"YES"<<endl;
#define  nl cout<<endl;
template<typename T>
using orderedSet=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
ostream &operator+(ostream &out, const vector<T> &vec) {
    for (const auto &x : vec) {
        out << x << " ";
    }
    out << "\n";
    return out;
}

template<typename T>
ostream &operator*(ostream &out, const vector<T> &vec) {
    for (const auto &x : vec) {
        out + x;
    }
    return out;
}

template<typename T>
istream &operator>>(istream &in, vector<T> &vec) {
    for (auto &x : vec) {
        in >> x;
    }
    return in;
}

template<class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }

template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }


const int mod = 1e9 + 7;
const int mod2 = 998244353;
const ll INF = 1e9 + 6;

ll add(ll a, ll b) {
    a += b;
    return a % mod;
}

ll mul(ll a, ll b) {
    a *= b;
    return a % mod;
}

inline ll power(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

inline ll modInverse(ll x, ll p,int chance) {
    return power(x, p - 2, p);
}
const int MXN=3002;
ll cache[MXN][MXN];
ll a[MXN];

ll dp(int l,int r){
    if(l>r){
        return 0;
    }
    ll &ans=cache[l][r];
    if(ans!=-1){
        return ans;
    }
    return ans=max(a[l]-dp(l+1,r),a[r]-dp(l,r-1));

}
void solve() {
    int n;
    cin >>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<MXN;i++)for (int j = 0; j <MXN ; ++j)cache[i][j]=-1;

    cout<<dp(0,n-1)<<endl;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)solve();
#ifndef ONLINE_JUDGE
    cerr << endl << "Time elapsed : " << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';
#endif
    return 0;
}
//look if it requires ll