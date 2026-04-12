/*---Author:HenryHuang---*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=3e3+5;
int n,p;
int ksm(int a,int b,int p){
	int ans=1;
	while(b){
		if(b&1) ans=1ll*ans*a%p;
		b>>=1,a=1ll*a*a%p;
	}
	return ans;
}
int C[maxn][maxn],S[maxn][maxn];
void init(){
	C[0][0]=S[0][0]=1;
	for(int i=1;i<=n+1;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j){
			S[i][j]=(S[i-1][j-1]+1ll*j*S[i-1][j]%p)%p;
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>p;init();
	int ans=0;
	for(int i=0;i<=n;++i){
		int tmp=1ll*ksm(2,ksm(2,n-i,p-1),p)*C[n][i]%p,owo=0;
		if(i&1) tmp=p-tmp;
		for(int j=0;j<=i;++j){
			owo=(owo+1ll*S[i+1][j+1]*ksm(2,1ll*(n-i)*j%(p-1),p)%p)%p;
		}
		(ans+=1ll*tmp*owo%p)%=p;
	}
	cout<<ans<<'\n';
	return 0;
}
