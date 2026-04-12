#include <bits/stdc++.h>

#define FLASH ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long int
#define MAX 1e9
#define MIN -1e9
#define mod 1000000007
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define output(x) cout << ( x ? "Yes" : "No" ) << '\n' ;
#define mxn 100005
using namespace std;


void find(int n,int x,int m){
    int sum = x;
    for(int i = 2; i <= n; i++){
        x = (x * x) % m;
        sum += x;
    }
    cout << sum ;
}

void solve(){
    int n,x,m;
    cin >> n >> x >> m ;
    if(n <= (1e6)){
        find(n,x,m);
        return;
    }
    
    vector<int> v;
    map<int,int> mp;

    v.pb(x);
    mp[x] = 0;
    int val = -1;
    
    for(int i = 2; ; i++){
        x = (x * x) % m;
        if(mp.find(x) != mp.end()){
            val = x;
            break;
        }
        v.pb(x);
        mp[x] = i - 1;
    }
    // cout << val << " " << mp[val] << '\n' ; 
    int sum = 0,ind = mp[val];
    int tot = (int)v.size();
    for(int i = 0; i < ind; i++){
        sum += v[i];
    }
    n -= (ind);
    vector<int> pref;
    for(int i = ind; i < tot; i++){
        pref.pb(v[i]);
    }
    tot = (int)pref.size();
    for(int i = 1; i < tot; i++){
        pref[i] += pref[i - 1];  
    }
    int times = n / (tot);
    sum += (pref[tot - 1]) * times;
    int remain = n % (tot);
    if(remain >= 1)
        sum += pref[remain - 1];
    cout << sum;
}

int32_t main()
{
    FLASH
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

