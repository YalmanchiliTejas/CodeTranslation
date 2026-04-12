/*"Everything in the universe is balanced. Every disappointment
   you face in life will be balanced by something good for you!
                Keep going, never give up."            */

#include "bits/stdc++.h"
using namespace std;

#define ll long long
const ll N=1e6+9;
const ll mod=1e9+7;

ll a[N],n,m;
int dp[10005][101][2];
     string s;

 int add(int x, int y){
 	ll p = x+y;
 	return p%mod;
 }

int go(int index, int mode, int flag){
	if(index==n)
		return mode==0;
	int &ans  = dp[index][mode][flag];
	if(ans!=-1)return ans;

	ans = 0 ;
	int maxm = s[index]-'0';

	if(flag) {
		for(int i=0; i<=9; i++){
			ans  = add(ans,go(index+1, (mode+i)%m, flag )) ;
		}
	}
	else{
		for(int i=0; i<maxm; i++){
			ans  = add(ans,go(index+1, (mode+i)%m, 1 )) ;
		}
		ans = add(ans , go(index+1, (mode+maxm)%m, 0 )) ;
	}
	//cout<<index<<mode<<flag<<maxm<<" "<<ans<<"\n";
	return ans;
}

void solve()
{    
    cin>>s>>m;
    memset(dp,-1,sizeof dp);
    n = s.size();
    cout<<(go(0,0,0)-1+mod)%mod;

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


// Xoraware