#include<bits/stdc++.h>
using namespace std;
const int N=10000005,P=998244353;
int n,inv[N];
int main()
{
	scanf("%d",&n);inv[1]=1;
	for(int i=2;i<=n;i++)inv[i]=1ll*(P-P/i)*inv[P%i]%P;
	int s=0;for(int i=0,c=1,p=1;i<n/2;i++){s=(s+1ll*c*p)%P;p=p*2%P;c=1ll*c*(n-i)%P*inv[i+1]%P;}
	int t=1;for(int i=1;i<=n;i++)t=3ll*t%P;t=(t-2ll*s%P+P)%P;printf("%d\n",t);return 0; 
}
