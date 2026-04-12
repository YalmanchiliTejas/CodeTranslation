#include<cstdio>
#include<cstring>
#include<algorithm>
#define qmax(x,y) (x=max(x,y));
using namespace std;

typedef long long ll;
const int Maxn=11000;
const ll mod=1000000007;

char a[Maxn];
int k,f[Maxn][110],ans;

int main() {
	scanf("%s",a);
	scanf("%d",&k);
	int n=strlen(a);
	f[0][0]=1;
	for(int i=1;i<n;i++)
		for(int l=0;l<=9;l++)
		for(int j=0;j<=k;j++) f[i][(j+l)%k]=(f[i][(j+l)%k]+f[i-1][j])%mod;
	int sum=0;
	for(int i=0;i<n;sum=(sum+a[i]-'0')%k,i++)
		for(int j=0;j<a[i]-'0';j++) {
			ans+=f[n-i-1][(k-(sum+j)%k)%k];
			ans%=mod;
		}
	if(sum==0) ans++;ans--;ans+=mod;
	ans%=mod;
	printf("%d",ans);
	return 0;
}
