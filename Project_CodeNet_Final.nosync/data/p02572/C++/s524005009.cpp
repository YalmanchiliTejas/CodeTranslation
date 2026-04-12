/************************************
/ AUTHOR : YATHARTH GOSWAMI         /  
/ ALIAS : hacker_yg                 /
/ INSTITUTE : IIT Kanpur            /
************************************/
//          TEMPLATE                //

#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.14159265359

using namespace std;

/*ll powMod(ll a, ll y)
{
    ll ans = 1;
    
    while (y > 0) 
    { 
        if (y & 1) 
            ans = (ans*a) % MOD; 
  
        y = y>>1;
        a = (a*a) % MOD; 
    } 
    return ans;
}*/

/*ll modInv(ll a)
{
    return powMod(a, MOD-2);	
}*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector <ll> v(n);
    for (ll &x : v) cin >> x;
    sort(v.begin(), v.end());
    vector <ll> sum(n, 0);
    sum[0] = v[0]%MOD; 
    for (int i = 1; i < n; i++) {
        sum[i] = (sum[i-1] + v[i])%MOD;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += ((v[i]%MOD) * ((sum[n-1]-sum[i]+MOD)%MOD))%MOD;
        ans %= MOD;
    }
    cout << (ans+MOD)%MOD << endl;
    return 0;
}


