#include<bits/stdc++.h>
using namespace std;
long long int b[100001],pre[1000001],a[100001];
int main() {
    long long n,m,x;
    cin>>n>>x>>m;
    long long ans=pre[1]=a[1]=x;
    b[x]=1;
	for (int i=2;i<=n;i++){
		a[i]=a[i-1]*a[i-1]%m;
		ans=pre[i]=pre[i-1]+a[i];
		if (b[a[i]]>0) {
			long long t1=(n-b[a[i]])/(i-b[a[i]]),t2=(n-b[a[i]])%(i-b[a[i]]);
			ans=pre[b[a[i]]+t2]+(pre[i]-pre[b[a[i]]])*t1;
			break;
		}
		b[a[i]]=i;
	}    
	cout<<ans<<endl;
	return 0;
}