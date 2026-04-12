#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll; 
int x,m,a[100005],f[100005];
ll n,ans=0,t=0,o=0;
int main(){
	cin>>n>>a[1]>>m,f[a[1]]=1,o=a[1];
	for(int i=2;i<=n;i++){
		a[i]=1ll*a[i-1]*a[i-1]%m;
		o+=a[i];
		if(f[a[i]]){
			ll p=0;
			for(int j=1;j<f[a[i]];j++)ans+=a[j],p++;
			for(int j=f[a[i]];j<i;j++)t+=a[j];
			ans+=t*((n-f[a[i]]+1)/(i-f[a[i]])),p+=(n-f[a[i]]+1)/(i-f[a[i]])*(i-f[a[i]]);
			for(int j=f[a[i]];j<f[a[i]]+(n-f[a[i]]+1)%(i-f[a[i]]);j++)ans+=a[j],p++;
			cout<<ans;
			return 0;
		}
		f[a[i]]=i;
	}
	cout<<o;
    return 0;
}