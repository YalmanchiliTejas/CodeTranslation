#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define inf 1000000007
#define int long long
using namespace std;
int ka[214514],inv[214514];
void setkaijo(int n){
	ka[0]=1;
	for(int i=1;i<=n;i++){
		ka[i] = ka[i-1] * i;
		ka[i] %= inf;
	}
}
int modpow(int x,int k){
	// x ^ k mod inf
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
	int n,m,k;
	cin>>n>>m>>k;
	setkaijo(210000);
	setinv(210000);
	int ans = 0;
	for(int i=1;i<n;i++){
		int tmp = i;
		tmp *= (n-i) * m * m;
		tmp %= inf;
		tmp *= comb(n*m-2,k-2);
		tmp %= inf;
		ans += tmp;
		ans %= inf;
	}
	for(int i=1;i<m;i++){
		int tmp = i;
		tmp *= (m-i) * n * n;
		tmp %= inf;
		tmp *= comb(n*m-2,k-2);
		tmp %= inf;
		ans += tmp;
		ans %= inf;
	}
	cout<<ans<<endl;
	return 0;
}