#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll modpow(ll a, ll b){

    ll ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b=b/2;
    }
    return ans;
}

ll dp[110][2][5];

ll solve(int ind, int match, int rem, string& digits) {
    if(ind == digits.size()) {
        if(rem != 0) return 0;
        return 1;
    }

    if(rem < 0) return 0;

    if(dp[ind][match][rem] != -1) return dp[ind][match][rem];

    int res = 0;

    if(match) {
        if(digits[ind] == '0') {
            // need to put 0, no other option
            res = res + solve(ind + 1, 1, rem, digits);
        } else {
            // try putting the same digit (non-zero)
            res = res + solve(ind + 1, 1, rem - 1, digits);

            // try putting lower digit which is non zero
            res = res + (digits[ind]-'0'-1)*solve(ind + 1, 0, rem - 1, digits);

            // try putting zero which is lower digit
            res = res + solve(ind + 1, 0, rem, digits);
        }
    } else {
        res = res + solve(ind + 1, 0, rem, digits);

        res = res + 9*solve(ind + 1, 0, rem - 1, digits);
    }

    dp[ind][match][rem] = res;
    return res;

}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    string digits;
    int k;
    cin>>digits>>k;

    
    memset(dp, -1, sizeof(dp));

    cout<<solve(0, 1, k, digits)<<endl;

}
