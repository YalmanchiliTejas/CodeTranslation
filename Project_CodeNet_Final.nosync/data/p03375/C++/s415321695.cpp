#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <iomanip>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

ll mod;
ll n;
ll comb[3010][3010]={};
ll dp[3010]={};
ll dp2[3010][3010]={};
long long ruijo(long long  k,long long m,long long p){
	if(m==0)return (ll)1;
	if(m==1)return k%p;
	long long s = ruijo(k,m/2,p);
	if(m%2==0){
		return (s*s)%p;
	}else{
		long long ans;
		ans = (s*s)%p;
		return (k*ans)%p;
	}
}

int main(){
    cin >> n >> mod;
    rep(i,3010){
        comb[i][i] = 1;
        comb[i][0] = 1;
    }

    for(int i=1;i<3010;i++){
        for(int j= 1;j<=i;j++){
            comb[i][j] = (comb[i-1][j] + comb[i-1][j-1])%mod;
        }
    }
    rep(i,3010){
        dp2[i][0] = 1;
    }
    for(ll i=1;i<3010;i++){
        for(ll j=1;j<=i;j++){
            dp2[i][j] = (dp2[i-1][j-1] + (j+1) * dp2[i-1][j] ) %mod;
        }
    }
    ll w[3010]={};
    rep(i,3010){
        w[i] = ruijo(2,ruijo(2,i,mod-1),mod);
    }
    
    for(ll i=0;i<=n;i++){
        ll tmp = 0;
        for(ll j=0;j<=i;j++){
            ll tmp2 = (dp2[i][j]*ruijo((ll)2,j*(n-i),mod))%mod;
            tmp2 = (tmp2*w[n-i])%mod;
            tmp = (tmp+tmp2)%mod;
        }
        dp[i] = (comb[n][i] * tmp)%mod;
        
    }
   
    ll ans = w[n];
    for(int i=1;i<=n;i++){
        if(i%2==1){
            ans = (ans +mod - dp[i])%mod;
        }else{
            ans = (ans + dp[i])%mod;
        }
        
    }
    cout <<ans << endl;
    return 0;
}