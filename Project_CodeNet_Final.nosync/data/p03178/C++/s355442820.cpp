#include <bits/stdc++.h>
#define inp_out_work ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define testCase    int T; cin>>T; while(T--)
#define fr(i,n) for(int i=0;i<n;i++)
#define fro(i,s,e) for(int i=s;i<=e;i++)
#define endl '\n'
#define debug(P) cout<<#P<<" = "<<P<<endl;
#define pb push_back
#define FILE freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);


using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
int mod;
const int MAXN = 10001;

int dp[MAXN][101][2];


ll f(int idx, int curr_mod, int tight, string &s){
    if(idx == s.length()){
        return (curr_mod == 0);
    }

    if(dp[idx][curr_mod][tight] != -1)return dp[idx][curr_mod][tight];

    int limit = 9;

    if(tight)limit = s[idx]-'0';

    ll ret = 0;

    for(int curr_dig = 0; curr_dig <= limit; ++curr_dig){
        int newTight = tight;
        if(curr_dig < s[idx]-'0')newTight  = 0;

        int newMod = (curr_mod + curr_dig)%mod;

        ret = (ret + f(idx+1, newMod, newTight, s))%MOD;
    }

    return dp[idx][curr_mod][tight] = ret;

}

int main(){
    inp_out_work

    fr(i,MAXN)fr(j,101)fr(k,2)dp[i][j][k] = -1;

    string k;
    cin>>k>>mod;

    ll ans =  f(0, 0, 1, k) - 1;

    if(ans < 0)ans += MOD;

    cout<< ans << endl;

}
