#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
const int mod=998244353;
ll n,x,m,ans,tp;
int d[100001],a[100001];
int main(){
	cin>>n>>x>>m;
	d[x]=1,ans=x,a[1]=x;
	for(int i=2;i<=n;i++){
		x=x*x%m;
		if(d[x]){
			ans=0;
			for(int j=1;j<d[x];j++) tp+=a[j];
			for(int j=d[x];j<i;j++) ans+=a[j];
			n-=d[x]-1;
			ans*=(n/(i-d[x]));
			for(int j=1;j<=n%(i-d[x]);j++) ans+=a[d[x]-1+j];
			cout<<ans+tp;
			return 0;
		}
		else d[x]=i,ans+=x,a[i]=x;
	}
	cout<<ans;
}