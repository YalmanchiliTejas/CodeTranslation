#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=3010;
int C[maxn][maxn],S[maxn][maxn];
inline int qpow(int base,int _pow,int m){
	int res=1;
	while(_pow){
		if(_pow&1) res=(ll)res*base%m;
		_pow>>=1;
		base=(ll)base*base%m;
	}
	return res;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	S[0][0]=1;
	for(int i=1;i<=n+1;i++)
		for(int j=1;j<=i;j++)
			S[i][j]=((ll)S[i-1][j]*j+S[i-1][j-1])%m;
	C[0][0]=1;
	for(int i=1;i<=n+1;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%m;
	}
	int ans=0;
	for(int i=0;i<=n;i++){
		int add=0;
		for(int j=0;j<=i;j++)
			add=(add+(ll)S[i+1][j+1]*qpow(qpow(2,n-i,m),j,m))%m;
		add=(ll)add*C[n][i]%m*qpow(2,qpow(2,n-i,m-1),m)%m;
		if(i&1) ans=(ans+m-add)%m;
		else ans=(ans+add)%m;
	}
	printf("%d\n",ans);
	return 0;
}