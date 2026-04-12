#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define LLINF 9223372036854775807
#define MOD ll(1e9+7)


vector<ll> b(51,0);
vector<ll> bp(51,0);
vector<ll> p(51,0);

ll dfs(ll x, int lv){
    ll ans = 0;
    if(x == 0){
        return 0;
    }
    if(x>=1){
        x--;
    }
    if(x < bp[lv]){
        ans += dfs(x, lv-1);
        return ans;
    }else{
        ans += p[lv];
        x -= bp[lv];
    }
    if(x>=1){
        x--;
        ans++;
    }
    if(x==0){return ans;}
    if(x < bp[lv]){
        ans += dfs(x, lv-1);
        return ans;
    }else{
        ans += p[lv];
        x -= bp[lv];
    }
    if(x>=1){
        x--;
    }
    return ans;
}


int main() {
    ll n, x;
    cin >> n >> x;


    bp[0] = 1;
    b[0] = 0;
    p[0] = 1;
    ll pnum = 1;
    for(int i = 1; i < 51; i++){
        bp[i] = 2*bp[i-1]+3;
        pnum *=2;
        p[i] = pnum + p[i-1];
        b[i] = bp[i] - p[i];
    }

    ll ans = dfs(x,n-1);
    cout << ans << endl;

    return 0;
}
