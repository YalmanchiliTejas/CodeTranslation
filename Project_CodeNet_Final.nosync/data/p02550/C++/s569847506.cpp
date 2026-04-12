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
    ll n, x, m;
    cin >> n >> x >> m;
    ll ans = 0, a = x, count = 1;
    map <int, int> mpz;
    ans += a%m;
    while (!mpz[a] && n > count) {
        mpz[a]++;
        a = (a*a)%m;
        ans += a;
        count++;
    }
    ll cycle_sum = 0, len = 0;
    map <int, int> m2;
    while (!m2[a]) {
        m2[a]++;
        cycle_sum += a;
        a = (a*a)%m;
        len++;
    }
    ans += ((n-count)/len)*cycle_sum;
    n = (n-count)%len;
    while (n--) {
        ans += (a*a)%m;
        a = (a*a)%m;
    }
    cout << ans << endl;
    return 0;
}


