#include<bits/stdc++.h>
using namespace std;
#define int           long long
#define pb            push_back
#define all(a)        (a).begin(),(a).end()
#define sz(x)         (int)x.size()
#define F             first
#define S             second
#define endl          "\n"
#define inf           (long long)1000000007
#define FOR(i, a, b)  for(int i=a; i<b; i++)
#define bigint        1e18
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count()); 
#define SHUF(v) shuffle(aint(v), RNG);
// Use mt19937_64 for 64 bit random numbers. 

template <typename T>
T ceil(T a, T b){ return (a+b-1)/b; }


template<typename T>
T binpow(T a, T b, T m) {
    a %= m;
    T res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n; cin>>n;
    int a[n];
    vector<int> suff(n);
    FOR(i, 0, n) cin>>a[i];
    suff[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--) {
        suff[i] = (suff[i+1]+a[i])%inf;
    }
    int res=0;
    FOR(i, 0, n-1) {
        res = (res + (a[i] % inf * (suff[i+1])%inf )%inf)%inf;
    }
    cout<<res;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);     
    int t=1;
    //cin>>t;
    FOR(i, 1, t+1){ 
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
 
}