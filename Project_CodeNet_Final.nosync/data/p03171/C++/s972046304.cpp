/*"Everything in the universe is balanced. Every disappointment
   you face in life will be balanced by something good for you!
                Keep going, never give up."            */

#include "bits/stdc++.h"
using namespace std;

#define ll long long
const ll N=1e6+9;
const ll mod=1e9+7;

ll a[N];
ll dp[3003][3003];

ll go(int l, int r, int flag){
	if(l>r){
		return 0;
	}

	ll &ans = dp[l][r]; 
	if(ans!=-1)return ans;

	ans = 0 ;
	if(!flag){
		ans = max( go(l+1,r,1)+a[l], go(l,r-1,1)+a[r] );
	}
	else{
		ans = min( go(l+1,r,0), go(l,r-1,0) );
	}
	//cout<<l<<r<<flag<<" "<<ans<<"\n";
	return ans;
}

void solve()
{    
    ll n, m ,total=0;
    cin>>n;
    memset(dp,-1,sizeof dp);
    for(int i=1; i<=n; i++){
    	cin>>a[i];
    	total+=a[i];
    }

    ll x = go(1,n,0);
    cout<<x-(total-x);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t=1;
    //pre();
    //cin>>t;
    while(t--)
    {
      solve();
    }  
}


// Xorawar