#include<bits/stdc++.h>
using namespace std;

#define CO const
#define IN inline
typedef long long LL;
typedef long double LD;

template<class T> T read(){
	T x=0,w=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-') w=-w;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*w;
}
template<class T> IN T read(T&x){
	return x=read<T>();
}

int mod;
IN int add(int a,int b){
	return (a+=b)>=mod?a-mod:a;
}
IN int mul(int a,int b){
	return (LL)a*b%mod;
}
IN int fpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=mul(a,a))
		if(b&1) ans=mul(ans,a);
	return ans;
}

CO int N=3000+10;
int C[N][N],S[N][N],B[N];

int main(){
	int n=read<int>();read(mod);
	for(int i=0;i<=n;++i){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;++j) C[i][j]=add(C[i-1][j-1],C[i-1][j]);
	}
	S[0][0]=1;
	for(int i=1;i<=n+1;++i)for(int j=1;j<=i;++j)
		S[i][j]=add(S[i-1][j-1],mul(j,S[i-1][j]));
	B[0]=1;
	for(int i=1;i<=n;++i){
		B[i]=B[i-1]<<1;
		if(B[i]>=mod-1) B[i]-=mod-1;
	}
	int ans=0;
	for(int i=0;i<=n;++i){
		int sum=0;
		for(int j=0;j<=i;++j) sum=add(sum,mul(S[i+1][j+1],fpow(2,(n-i)*j)));
		sum=mul(sum,mul(C[n][i],fpow(2,B[n-i])));
		ans=add(ans,i&1?mod-sum:sum);
	}
	printf("%d\n",ans);
	return 0;
}
