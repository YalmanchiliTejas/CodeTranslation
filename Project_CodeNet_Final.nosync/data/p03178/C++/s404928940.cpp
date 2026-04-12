#include<bits/stdc++.h> 
using namespace std;

#define ll long long int
#define absdiff(a,b) (a>b)?a-b:b-a
#define mp make_pair 
#define pb push_back
#define pp pop_back
#define ff first
#define ss second
#define fast  ios_base::sync_with_stdio(false);cin.tie(0);
#define endl "\n"
const ll ll_MAX = 19223372036859;
const ll MOD = 1e9 + 7;
ll fast_expo(ll x,ll p){if(p==0) return 1;
    else if(p%2==0){ ll t=fast_expo(x,p/2)%MOD;return (t*t)%MOD;} 
    else return (x*(fast_expo(x,p-1))%MOD)%MOD;}
ll gcd(ll a,ll b){if(a==0||b==0) return a+b;  
    else return gcd(b%a,a); }

ll dp[10001][101][2];
string str;
ll d, ans = 0;

ll find(ll pos, bool f, ll sum){
    if(dp[pos][sum][f] != -1) 
        return dp[pos][sum][f];

    if(pos == str.size()){
        if(sum % d == 0)
            return 1;
        return 0;
    }

    dp[pos][sum][f] = 0;   
    if(f){
        ll val = str[pos] - '0';
        for(ll i = 0; i < val; ++i){
            dp[pos][sum][f] += find(pos+1, false, (sum-i+10*d)%d);
            dp[pos][sum][f] %= MOD;
        }
        dp[pos][sum][f] += find(pos+1, true, (sum-val+d)%d);
        dp[pos][sum][f] %= MOD;
    } else {
        for(ll i = 0; i < 10; ++i){
            dp[pos][sum][f] += find(pos+1, false, (sum-i+10*d)%d);
            dp[pos][sum][f] %= MOD;
        }
    }
    return dp[pos][sum][f];
}

int main()
{
    // fast
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    ll t_c; t_c = 1;
    // cin >> t_c;
    for(ll t_i=0; t_i<t_c; ++t_i){
        memset(dp, -1, sizeof(dp));
        cin >> str;
        cin >> d;
            
        cout << (find(0, true, 0)-1+MOD)%MOD;     
    }  
    return 0;
}