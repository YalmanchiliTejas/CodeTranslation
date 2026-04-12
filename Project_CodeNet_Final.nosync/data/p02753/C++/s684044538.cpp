#include <bits/stdc++.h>
#define maxn 100005
#define MOD 998244353
using namespace std;
#define ll long long

#define pii pair<ll, ll>
#define piii pair<ll, pii>

#define ft first
#define sd second

void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}


ll power(ll a, ll b){
    if(b==0) return 1;
    ll R =1, k=a;
    for (ll j=b;j>0;j/=2){
        if (j&1) R=(R*k)%MOD;
        k=(k*k)%MOD;
    }
    return R;
}

void solve(){

    string s;
    cin >> s;
    if(s == "AAA" || s == "BBB") cout << "No\n";
    else cout << "Yes\n";

}

int main()
{


    ll t = 1;//cin >> t;
    while(t--){
        solve();
    }
}
