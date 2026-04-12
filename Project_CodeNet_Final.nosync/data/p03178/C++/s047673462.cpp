#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

ll dp[10005][105][2];
ll d;
string s;

ll solve(int pos, int sum, bool tight){
    if(pos == s.length()) return sum==0;

    if(dp[pos][sum][tight] != -1) return dp[pos][sum][tight];

    ll ans=0;
    int end = ((tight)?(s[pos]-'0'):9);
    for(int i=0; i<=end; i++){
        ans = (ans + solve(pos+1, (sum+i)%d, tight&(i==end)))%mod;
    }
    dp[pos][sum][tight]=ans;
    return dp[pos][sum][tight];
}

int main(){
    cin>>s;
    cin>>d;
    memset(dp, -1, sizeof(dp));
    ll ans = solve(0, 0, 1);
    ans = (ans-1+mod)%mod;
    cout<<ans<<endl;
    return 0;
}