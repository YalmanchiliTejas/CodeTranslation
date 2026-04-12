#include<bits/stdc++.h>
using namespace std;

const int N=200100,inf=1e9;
int n,mx,xm,mn=inf,nm=inf;
typedef long long ll;
ll ans;
pair<int,int>a[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].first>>a[i].second;
		if(a[i].first>a[i].second)swap(a[i].first,a[i].second);
		mx=max(mx,a[i].second);mn=min(mn,a[i].second);
	}
	sort(a+1,a+n+1);
	ans=(ll)(a[n].first-a[1].first)*(mx-mn);
	for(int i=1;i<=n;++i){
		xm=max(xm,a[i].second);
		nm=min(nm,a[i].second);
		ans=min(ans,(ll)(max(xm,a[n].first)-min(nm,a[i+1].first))*(mx-a[1].first));
	}
	cout<<ans<<'\n';
	return 0;
}
