#include <bits/stdc++.h>

const int N=1e4+10,Mod=998244353;

int n,dp[N][N],fact[N],inv[N],cnt,dif,sam;
char A[N],B[N];

void Init() {
	scanf("%s%s",A,B); 
	n=strlen(A);
	for (int i=0;i<n;++i) if (A[i]=='1') ++cnt;
	for (int i=0;i<n;++i) if (B[i]=='1' && A[i]=='1') sam++;
	dif=cnt-sam;
}

int Calc(int n,int m) { return 1ll*fact[n]*inv[n-m]%Mod*inv[m]%Mod; }

void Solve() {
	fact[0]=1; for (int i=1;i<=cnt;++i) fact[i]=1ll*fact[i-1]*i%Mod;
	inv[0]=inv[1]=1;  for (int i=2;i<=cnt;++i) inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	for (int i=1;i<=cnt;++i) inv[i]=1ll*inv[i]*inv[i-1]%Mod;
	for (int i=0;i<=dif;++i) dp[0][i]=1ll*fact[i]*fact[i]%Mod;
	for (int i=1;i<=sam;++i)
		for (int j=1;j<=dif;++j)
			dp[i][j]=(1ll*dp[i-1][j]*i+1ll*dp[i][j-1]*j)%Mod*j%Mod;
	int ans=0;
	for (int j=0;j<=sam;++j)
		ans=(ans+1ll*dp[sam-j][dif]*fact[j]%Mod*fact[j]%Mod*Calc(sam,j)%Mod*Calc(cnt,j))%Mod;
	printf("%d\n",ans);
}

int main() {
	Init();
	Solve();
	return 0;
}