#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define pb push_back
#define MOD 1000000007
#define sz5 100005
#define sz6 1000005
#define UP upper_bound
#define LB lower_bound
#define F first
#define S second
#define PI pair<int,int>
#define PL pair<ll,ll>
#define VI vector<int>
#define VL vector<ll>

ll dp[3003][3003], arr[3003];
bool mk[3003][3003];

ll solve(ll l, ll r){
    if(l>r)
        return 0;

    if(mk[l][r])
        return dp[l][r];

    mk[l][r]=true;
    ll ans=max(arr[l]-solve(l+1, r), arr[r]-solve(l, r-1));

    dp[l][r]=ans;
    return ans;
}

int main() {
    FAST
    
    ll n,la,lb;
    cin>>n;
    
    for(la=1;la<=n;la++)
        cin>>arr[la];

    ll ans=solve(1, n);
    cout<<ans<<endl;

    return 0;
}