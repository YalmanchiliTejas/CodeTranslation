#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
string k;
ll d, n, dp[10123][120][2];
bool used[10123][120][2];

// 0 --> not less yet
// 1 -->less already

void add_self(ll& a, ll b){
    a += b;
    if(a >= mod){a -= mod;}
}

ll rec(ll pos, ll sum, ll less){
    if(pos == n){ return (sum == 0);}
    if(used[pos][sum][less]){ return dp[pos][sum][less];}
    used[pos][sum][less] = 1;
    ll temp = 0;
    if(less){
        for(ll i = 0; i < 10; i++){
            add_self(temp, rec(pos+1, (sum+i) % d, 1));
        }
    }else{
        ll num = (k[pos]-'0');
        add_self(temp, rec(pos+1, (sum + num) % d, 0));
        for(ll i = 0; i < num; i++){
            add_self(temp, rec(pos+1, (sum + i) % d, 1));
        }
    }
    return dp[pos][sum][less] = temp % mod;
}

int main() {
    cin>>k>>d;
    n = (ll)k.size();
    ll num = (k[0]-'0');
    ll ans = rec(1, num % d, 0);
    for(ll i = 0; i < num; i++){
        add_self(ans, rec(1, i % d, 1));
    }
    ans--;
    if(ans == -1){
        ans = mod - 1;
    }
    cout<<ans;
	return 0;
}