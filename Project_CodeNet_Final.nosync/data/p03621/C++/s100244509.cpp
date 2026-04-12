#include<bits/stdc++.h>
using namespace std;

const int Mod=998244353;

int N,Cnt1,Cnt2,Ans;
char A[10005],B[10005];
int Fac[10005],Inv[10005];
int F[10005][10005];

int C(int n,int m){
	return 1llu*Fac[n]*Inv[m]%Mod*Inv[n-m]%Mod;
}

int main(){
	int i,j;
	scanf("%s%s",A+1,B+1);
	N=strlen(A+1);
	for(i=1;i<=N;i++)
		if(A[i]=='1')
			B[i]=='1'?Cnt1++:Cnt2++;
	Fac[0]=Inv[0]=Fac[1]=Inv[1]=1;
	for(i=2;i<=N;i++){
		Fac[i]=1llu*Fac[i-1]*i%Mod;
		Inv[i]=1llu*(Mod-Mod/i)*Inv[Mod%i]%Mod;
	}
	for(i=2;i<=N;i++)
		Inv[i]=1llu*Inv[i-1]*Inv[i]%Mod;
	F[0][0]=1;
	for(i=0;i<=Cnt1;i++)
		for(j=1;j<=Cnt2;j++)
			F[i][j]=(1llu*F[i][j-1]*(Cnt2-j+1)*(Cnt2-j+1)+(i?1llu*F[i-1][j]*i*j:0))%Mod;
	for(i=0;i<=Cnt1;i++)
		Ans=(Ans+1llu*F[i][Cnt2]*Fac[Cnt1-i]%Mod*Fac[Cnt1-i]%Mod*C(Cnt1,i)%Mod*C(Cnt1+Cnt2,i+Cnt2))%Mod;
	printf("%d\n",Ans);
	return 0;
}