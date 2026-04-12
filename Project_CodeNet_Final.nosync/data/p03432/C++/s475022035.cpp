#include<bits/stdc++.h>
#define ll long long
#define N 40010
#define mo 998244353
using namespace std;
ll jie[N+10],nj[N+10],m,n,dp[210][8010],ans,A[N],B[N],w[N],p,lo;
ll po(ll x,ll y){ll z=1;while (y){if (y%2)z=x*z%mo;x=x*x%mo;y/=2;}return z;}
ll c(ll x,ll y){return (jie[x]*nj[y]%mo)*nj[x-y]%mo;}
void fft(ll *a,int fh){
	for (int i=0;i<p;i++)if (w[i]>i) swap(a[i],a[w[i]]);
	for (int i=1;i<p;i*=2){
		for (int j=0;j<p;j+=i*2){
			ll w=1,W=(po(3,(mo-1)/(i*2))+mo)%mo;
			for (int k=0;k<i;k++,w=w*W%mo){
				ll x=a[j+k],y=a[i+j+k]*w%mo;
				a[j+k]=(x+y)%mo;a[j+k+i]=(x-y+mo)%mo;
			}
		}
	}
	if (fh==-1){reverse(a+1,a+p);ll x=po(p,mo-2);for (int i=0;i<p;i++)a[i]=a[i]*x%mo;}
}
int main(){
	cin>>n>>m;
	for (p=1,lo=0;p<=n*2;p*=2,lo++);
	for (int i=0;i<p;i++)w[i]=w[i/2]/2+(i&1)*(1<<(lo-1));
	jie[0]=1;for (int i=1;i<=N;i++)jie[i]=jie[i-1]*i%mo;
	nj[N]=po(jie[N],mo-2);for (int i=N-1;i>=0;i--) nj[i]=nj[i+1]*(i+1)%mo;
	dp[0][0]=1;
	for (int i=0;i<m;i++){
		memset(A,0,sizeof(A));memset(B,0,sizeof(B));
		for (int j=0;j<=n;j++){
			A[j]=dp[i][j]*nj[j]%mo;
			dp[i+1][j]=(dp[i+1][j]+dp[i][j]*(1+c(j+1,2)))%mo;
			if (j)B[j]=nj[j+2];
		}
		fft(A,1);fft(B,1);
		for (int j=0;j<p;j++)A[j]=A[j]*B[j]%mo;
		fft(A,-1);
		for (int j=1;j<=n;j++)dp[i+1][j]=(dp[i+1][j]+A[j]*jie[j+2])%mo;
	}
	for (int i=0;i<=n;i++)ans=(ans+dp[m][i]*c(n,i))%mo;
	cout<<ans<<endl;
	return 0;
}
/*	for (int k=1;k+j<=n;k++){
		dp[i+1][j+k]=(dp[i+1][j+k]+dp[i][j]*c(j+k+2,k+2))%mo;
	}
*/