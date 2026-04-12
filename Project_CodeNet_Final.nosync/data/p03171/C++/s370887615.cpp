#include<bits/stdc++.h> 
using namespace std;

#define ll long long int
#define absdiff(a,b) (a>b)?a-b:b-a
#define mp make_pair 
#define pb push_back
#define ff first
#define ss second
#define fast  ios_base::sync_with_stdio(false);cin.tie(0);
#define endl "\n"
const ll ll_MAX = 19223372036859;
const ll MOD = 1000000007;
ll fast_expo(ll x,ll p){if(p==0) return 1;
    else if(p%2==0){ ll t=fast_expo(x,p/2)%MOD;return (t*t)%MOD;} 
    else return (x*(fast_expo(x,p-1))%MOD)%MOD;}
ll gcd(ll a,ll b){if(a==0||b==0) return a+b;  
    else return gcd(b%a,a); }

ll arr[3001];
ll dp[3001][3001];
ll n;

ll solve(ll i,ll j)
{
    if(i == j && n%2 == 1) return arr[i];
    else if(i == j && n%2 == 0) return -arr[i];
    if(dp[i][j] != ll_MAX) return dp[i][j];

    ll turn = (n-j+i)%2;
    if(turn == 1) return dp[i][j] = max(solve(i+1,j)+arr[i],solve(i,j-1)+arr[j]);
    else return dp[i][j] = min(solve(i+1,j)-arr[i],solve(i,j-1)-arr[j]);

}

int main()
{
    ll t_c; t_c = 1;
    // cin >> t_c;
    for(ll t_i=0; t_i<t_c; ++t_i){
        for(ll i=0; i<3001; ++i){
            for(ll j=0; j<3001; ++j)
                dp[i][j] = ll_MAX;
        }
        cin >> n;
        for(ll i=1; i<=n; ++i)
            cin >> arr[i];

        cout << solve(1,n);
    }   
    return 0;
}