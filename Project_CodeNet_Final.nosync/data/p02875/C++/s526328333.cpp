#include <bits/stdc++.h>
using namespace std;
const int fish=998244353;
int fac[10000007],N,inv[10000007];
int Pow(int x,int y){int ans=1;for (;y;y>>=1,x=1ll*x*x%fish) if (y&1) ans=1ll*ans*x%fish;return ans;}
void Pre(int ned){
	fac[0]=1;
	for (int i=1;i<=ned;i++)
		fac[i]=1ll*fac[i-1]*i%fish;
	inv[ned]=Pow(fac[ned],fish-2);
	for (int i=ned-1;i>=0;i--)
		inv[i]=1ll*inv[i+1]*(i+1)%fish;
}
int C(int n,int r){if (n<r) return 0;return 1ll*fac[n]*inv[r]%fish*inv[n-r]%fish;}
void work(){
	scanf("%d",&N);
	long long ans=Pow(3,N);
	for (int i=N/2+1;i<=N;i++)
		((ans-=1ll*C(N,i)*Pow(2,N-i+1))+=fish)%=fish;
	cout<<ans;
	return;
}
int main(){
	Pre(10000000);
	work();
	return 0;
}