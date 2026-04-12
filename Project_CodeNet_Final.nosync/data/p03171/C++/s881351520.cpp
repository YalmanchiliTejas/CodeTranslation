#include<bits/stdc++.h>
#define ll  long long int
#define fr(i,n) for(ll i=0; i<n; i++)
#define fre(i,n) for(ll i=1; i<=n; i++)
#define pb push_back
#define mp(i,j) make_pair(i,j)
#define fi first
#define se second
#define pii pair<ll,ll>
#define ve vector
#define piii pair<ll, pii>
#define FAST ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;

ll dp[3010][3010];
ll n;
ll val[3010];

ll find(ll l, ll h){

    if(l>h) return 0;
    if(l==h) return val[l];

    if(dp[l][h]!=-1) return dp[l][h];

    ll ans1 = val[l]+min( find(l+2, h), find(l+1, h-1) );
    ll ans2 = val[h]+min(find(l+1, h-1), find(l, h-2));

    dp[l][h] = max(ans1, ans2);
    return dp[l][h];
}

int main()
{  
    FAST;
    memset(dp, -1, sizeof(dp));

    ll sum=0;
    cin>>n;
    fr(i,n) cin>>val[i], sum+= val[i];

    ll ans = find(0, n-1);   
    cout<<ans-(sum-ans)<<endl;
}