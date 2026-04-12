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
#define piii pair<pii, ll>
#define FAST ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;


ll dp[3010][3010];
vector<ll> v;

ll score( int l, int r){
    if( r < l )
        return 0;
    if( l == r )
        return v[l];
    if( dp[l][r] != -1 )
        return dp[l][r];

    ll ans1 = 0, ans2 = 0;
    ans1 =  v[l] + min(score(l+2, r), score(l+1, r-1));
    ans2 =  v[r] + min(score(l+1, r-1), score(l, r-2));
    dp[l][r] = max(ans1, ans2);
    return dp[l][r];
}

int main(){
   
   for(int i=0; i<3010; i++){
        for(int j=0; j<3010; j++)
            dp[i][j] = -1; 
   }
   ll n,x, sum=0;
   cin>>n;

   for(int i=0; i<n; i++){
        cin>>x;
        v.push_back(x);
        sum += x;
   }
   ll ans = 2*score(0, n-1)-sum; 
   cout<<ans<<endl;
}