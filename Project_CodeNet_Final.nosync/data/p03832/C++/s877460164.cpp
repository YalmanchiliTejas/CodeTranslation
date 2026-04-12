#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 1000000007
#define ll long long
using namespace std;
ll dp[1140][1140];
int ka[214514],inv[214514];
int invp[1140][1140];
int combb[1140][1140];
void setkaijo(int n){
	ka[0]=1;
	for(int i=1;i<=n;i++){
		ka[i] = ka[i-1] * i;
		ka[i] %= inf;
	}
}
int modpow(int x,int k){
	// x ^ k mod inf
	if(k==0)return 1;
	int p2[55],res=1;
	p2[0]=1;p2[1]=x%inf;
	for(int i=2;i<=50;i++){
		p2[i]=p2[i-1]*p2[i-1];
		p2[i] %= inf;
	}
	for(int i=1;i<=50;i++){
		if(k%2==1){
			res *= p2[i];
			res %= inf;
		}
		k /= 2;
	}
	return res;
}
void setinv(int n){
	inv[0]=1;
	for(int i=1;i<=n;i++){
		inv[i] = modpow(ka[i],(ll)inf-2);
	}
}
int comb(int n,int k){
	if(k==0 || k==n)return 1;
	int res = (ka[n] * inv[k]) % inf;
	res = (res*inv[n-k]) % inf;
	return res;
}
signed main(){
	ll n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	dp[0][0]=1;
	setkaijo(10000);
	setinv(10000);
	for(int i=0;i<a;i++){
		dp[i][0]=1;
	}
	for(int i=1;i<1100;i++){
		for(int j=0;j<1100;j++){
			invp[i][j] = modpow(inv[i],j);
			if(i>=j)combb[i][j] = comb(i,j);
		}
	}
	combb[0][0]=1;
	inv[0]=1;
	for(int i=a;i<=b;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=j/i;k++){
				if( k==0 || ( c<=k && k<=d) ){
				ll cur = dp[i-1][j-i*k];
				ll mul = combb[n-j+i*k][i*k];
				mul *= ka[i*k];
				mul %= inf;
				mul *= invp[i][k];
				mul %= inf;
				mul *= inv[k];
				mul %= inf;
				cur *= mul;
				cur %= inf;
				//cout<<i<<j<<" "<<cur<<" "<<mul<<endl;
				dp[i][j] += cur;
				dp[i][j] %= inf;
				}
			}
		}
	}
	cout<<dp[b][n]<<endl;
	return 0;
}