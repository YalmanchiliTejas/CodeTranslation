#include <bits/stdc++.h>
#include <unordered_map>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(ll i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
ll f(ll n){
    return (n*n + 4) / 8;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll X,Y,Z;
    cin >> X >> Y >> Z;
    ll lv = 0, rv = 1e5;
    while(rv - lv > 1){
        ll mid = (rv + lv) / 2;
        if(mid * (Y + Z) + Z <= X){
            lv = mid;
        }else{
            rv = mid;
        }
    }
    print(lv);


}