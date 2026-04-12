#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
#define int long long
#define pb push_back
#define getMat(v, n, m, val) vector<vector<int>> v(n,vector<int>(m, val))
#define lb lower_bound
#define up upper_bound
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define size(v) (int)v.size()
using namespace std;
//const int mod = 1e9+7;

int power(int a, int b, int mod){
    if(b == 0) return 1;
    int res = power(a, b/2, mod);
    res = res*res%mod;

    if(b&1) res = res*a%mod;
    return res;
}

int32_t main(){
    fastio;
    int n, x, m; cin >> n >> x >> m;

    unordered_map<int,int> mp;
    vector<int> v;
    int val = x,idx=0;
    while(true){
        if(mp.count(val)>0){
            idx = mp[val];
            break;
        }
        mp[val] = idx++;
        v.pb(val);
        val = power(val,2,m);
    }

    vector<int> pre(size(v), 0);
    pre[0] = v[0];
    for(int i=1; i<size(pre); i++){
        pre[i] = pre[i-1]+v[i];
    }

    int ans = 0;
    if(n <= size(v)){
        ans += pre[n-1];
    }else{
        int last = (idx-1)>=0?pre[idx-1]:0;
        // for(int x: pre) cout << x << " ";
        // cout << endl;
        ans += last;
        int rep = ((n-idx)/(size(v)-idx));
        ans += rep*(pre[size(v)-1]-last);

        int f = ((n-idx)%(size(v)-idx))-1;
        if(f >= 0) ans += pre[idx+f]-last;
    }
    cout << ans << endl;
    return 0;
}