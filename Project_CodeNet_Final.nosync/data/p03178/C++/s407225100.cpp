#include <bits/stdc++.h>
#define ll int
#define maxn 10001
#define MOD 1000000007
using namespace std;
 
string s;
ll k, n;
ll dp[maxn][101][2];
vector<ll> num;
 
/*
 dp[p][s][f]
    p = position
    s = sum upto p
    f = flag if the value is crossing the range or not
*/
 
ll solve(ll pos, ll sum, ll f){
    if(n==pos){
        if(sum==0) return 1;
        else return 0;
    }
    if(dp[pos][sum][f] != -1) return dp[pos][sum][f];
    ll res = 0, lmt;
    if(f==0){ // the pos can only be (0, s[pos])
        lmt = num[pos];
    }
    else { // the pos can be anything
        lmt = 9;
    }
    for(ll i = 0; i <= lmt; i++){
        ll newf = f; // newf is the flag value for next position
        if(f==0 && i<lmt) newf = 1; // if currently f =0 ie restricted and
                                 // current pos is less than the edge value
                                 //the next pos can be anything bw (0,9), hence newf is 1
        res += solve(pos+1, (sum+i)%k, newf);
        res %= MOD;
    }
    return dp[pos][sum][f] = res;
}
 
int main(){
    //ll t; cin >> t; while(t--){
        cin >> s >> k;
        num.clear();
        n = s.length();
        for(ll i=0; i<n; i++){
            num.push_back(s[i]-'0');
        }
        memset(dp, -1, sizeof(dp));
        ll ans = solve(0,0,0);
        ans--;
        if(ans<0) ans+= MOD;
        cout << ans << endl;
    //}
}