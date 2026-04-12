#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;
using P  = pair<int,int>;
const int INF = 1001001001;
const int MOD = 1000000007;

int main(){
    ll n;
    cin >> n;
    
    ll x, m;
    cin >> x >> m;
    ll y = x;
    ll ans = 0;
    set<ll> a;
    a.insert(y);
    while(!a.count(y*y%m)){
        a.insert(y*y%m);
        y = y*y%m;
    }
    int root = y*y%m;
    
    y = x;
    int hige = 0;
    ll count = 0;
    while(y!=root && count<n){
        ans += y;
        count++;
        y = y*y %m;
        hige++;
    }
    
    if(count==n){
        cout << ans << endl;
        return 0;
    }
    
    int loop = (int)a.size() - hige;
    
    vector<ll> lnum(loop);
    for(int i=0; i<loop; i++){
        lnum[i] = y;
        y = y*y%m;
    }
    
    n -= hige;
    ll c = n / loop;
    ll b = n % loop;
    
    for(int i=0; i<loop; i++){
        ans += c*lnum[i];
        if(i<b) ans += lnum[i];
    }
    
    cout << ans << endl;
    
    return 0;
}