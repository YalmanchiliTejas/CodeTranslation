#include <bits/stdc++.h>
using namespace std;
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define md 1000000007

ll strsz,D,dp[100005][3][102];
string s,ss;

ll fnc(ll pos, ll is_choto, ll sum)
{
    if(pos == strsz) return 0;
    if(dp[pos][is_choto][sum] != -1) return dp[pos][is_choto][sum];

//    cout<<pos<<" "<<is_choto<<" "<<sum<<endl;

    ll low = 0;
    ll high = 9;

    if(!is_choto)high = (s[pos] - '0');
    ll ans = 0;
    for(ll i = low; i<=high; i++){
//        if((sum + i)%D == 0)cout<<sum+i<<endl;
        ans = (ans%md + (fnc(pos + 1, (is_choto | (i<high)), (sum + i) % D) % md + ((sum + i)%D == 0 && (sum + i)>0) % md)) % md;
    }
    return dp[pos][is_choto][sum] = ans;
}

int main()
{
    faster_io;

    ll n;

    cin>>s>>D;

    memset(dp, -1, sizeof dp);

    ll x=0;

    strsz = s.size();
    cout<<fnc(0,0,0)<<endl;

//    cout<<x<<endl;
    return 0;
}
