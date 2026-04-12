#include<bits/stdc++.h>
#define LCH (cur<<1)
#define RCH (cur<<1|1)
using namespace std;

const int MaxN=1e5+5;
const int Size=(1<<18)+5;
const int Mod=998244353;

int N,M,InvM,Cnt1,Cnt2,Ans;
char A[MaxN],B[MaxN];
int Fac[MaxN],Inv[MaxN];
int R[Size],Tmp[Size],F[Size],G[Size];

vector<int> V[MaxN<<2];

int C(int n,int m){
	return 1llu*Fac[n]*Inv[m]%Mod*Inv[n-m]%Mod;
}

int Pow(int base,int n){
	int ans=1;
	if(n<0)
		n+=Mod-1;
	for(;n;n>>=1){
		if(n&1)
			ans=1llu*ans*base%Mod;
		base=1llu*base*base%Mod;
	}
	return ans;
}

void NTT(int *a,int f){
	int i,j,k,w,wn,x,y;
	for(i=0;i<M;i++)
		if(i<R[i])
			swap(a[i],a[R[i]]);
	for(i=1;i<M;i<<=1){
		wn=Pow(3,f*(Mod-1)/(i<<1));
		for(j=0;j<M;j+=i<<1)
			for(k=0,w=1;k<i;k++){
				x=a[j+k],y=1llu*w*a[j+k+i]%Mod;
				a[j+k]=(x+y)%Mod;
				a[j+k+i]=(x-y+Mod)%Mod;
				w=1llu*w*wn%Mod;
			}
	}
}

void Solve(int cur,int l,int r){
	if(l==r){
		V[cur].resize(2);
		V[cur][0]=1,V[cur][1]=Mod-l;
		return;
	}
	int i,j=0,mid=l+r>>1;
	Solve(LCH,l,mid),Solve(RCH,mid+1,r);
	for(M=1;M<=r-l+1;M<<=1,j++);
	InvM=Pow(M,Mod-2);
	for(i=0;i<M;i++)
		R[i]=(R[i>>1]>>1)+((i&1)<<j-1);
	V[LCH].resize(M),V[RCH].resize(M);
	V[cur].resize(M);
	NTT(V[LCH].data(),1),NTT(V[RCH].data(),1);
	for(i=0;i<M;i++)
		V[cur][i]=1llu*V[LCH][i]*V[RCH][i]%Mod;
	NTT(V[cur].data(),-1);
	V[cur].resize(r-l+2);
	for(i=0;i<=r-l+1;i++)
		V[cur][i]=1llu*V[cur][i]*InvM%Mod;
}

void Get_Inv(int *a,int *b,int n){
	if(n<2){
		b[0]=Pow(a[0],Mod-2);
		return;
	}
	Get_Inv(a,b,n+1>>1);
	int i,j=0;
	for(M=1;M<=n<<1;j++,M<<=1);
	InvM=Pow(M,Mod-2);
	for(i=0;i<M;i++)
		R[i]=(R[i>>1]>>1)+((i&1)<<j-1);
	for(i=0;i<n;i++)
		Tmp[i]=a[i];
	for(i=n;i<M;i++)
		Tmp[i]=0;
	NTT(Tmp,1),NTT(b,1);
	for(i=0;i<M;i++)
		b[i]=1llu*b[i]*(2-1llu*Tmp[i]*b[i]%Mod+Mod)%Mod;
	NTT(b,-1);
	for(i=0;i<n;i++)
		b[i]=1llu*b[i]*InvM%Mod;
	for(i=n;i<M;i++)
		b[i]=0;
}	

int main(){
	int i,j,k;
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
	if(Cnt2){
		Solve(1,1,Cnt2);
		for(i=0;i<=Cnt2;i++)
			F[i]=V[1][i];
	}
	else F[0]=1;
	Get_Inv(F,G,Cnt1+1);
	for(i=0;i<=Cnt1;i++)
		Ans=(Ans+1llu*G[i]*Inv[i+Cnt2])%Mod;
	printf("%d\n",1llu*Ans*Fac[Cnt2]%Mod*Fac[Cnt2]%Mod*Fac[Cnt1]%Mod*Fac[Cnt1+Cnt2]%Mod);
	return 0;
}