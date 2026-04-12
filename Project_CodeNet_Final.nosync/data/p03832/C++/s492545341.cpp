#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
#define int long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define err(A) cout << #A << " = " << (A) << endl
using namespace std;
const int N=1e3+10,mod=1e9+7;
ll dp[N][N];

ll fac[N];
ll power(ll n, ll k){
    if (k==0 || k==n){
        return 1;
    }
    else{
        if (k%2==0){
            ll x=power(n,k/2);
            return x*x%mod;
        }
        else{
            ll x=power(n,k/2);
            x=x*x%mod;
            return x*n%mod;
        }
    }
}
ll fm[N];
ll ent(ll k, ll n){
	if (k==0 || k==n){
        return 1;
	}

	return (((fac[n]*fm[k])%mod)*fm[n-k])%mod;
}
int32_t main(){
    fac[0] = 1;

	for(int i=1;i<N;i++) {
        fac[i]=(fac[i-1]*i)%mod;
	}
	for(int i=0;i<N;i++) {
        fm[i]=power(fac[i],mod-2);
	}
	ll n,a,b,c,d;
	cin >> n >> a >> b >> c >> d;
	//dp[a][a]=1;
	for (int i=0;i<N;i++){
        dp[0][i]=1;
	}
	for (int i=a;i<=n;i++){
        for (int j=a;j<=b;j++){
            /// dp[i][j]; i nafar be grohaye max j nafari chan ravesh
            dp[i][j]=dp[i][j-1];
            ll s=i;
            ll z=1;
            ll p1=1;

            for (int k=1;k<=d;k++){
                if (j>s){
                    break;
                }
                z*=ent(j,s);
                z%=mod;



                s-=j;

                if (k>=c){
                    dp[i][j]+=dp[s][j-1]*z%mod*fm[p1]%mod;
                    dp[i][j]%=mod;

                }
                p1++;
            }
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
	}
	cout << dp[n][b]%mod;;

}
