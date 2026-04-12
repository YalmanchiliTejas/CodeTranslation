#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
const ll MOD=1000000007;
const ll INF=1000000010;
const ll LINF=4000000000000000010;
int main(){
	int n;cin>>n;
	ll x[200010],y[200010];
	ll ma=-1,mi=INF;int miid;
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
		if(x[i]<y[i])swap(x[i],y[i]);
		if(ma<x[i]){
			ma=x[i];
		}
		if(mi>y[i]){
			mi=y[i];
			miid=i;
		}
	}
	ll ans=LINF;
	ll rmi=INF,bma=-1;
	for(int i=0;i<n;i++){
		bma=max(bma,y[i]);
		rmi=min(rmi,x[i]);
	}
	ans=min(ans,(ma-rmi)*(bma-mi));
	ll rma=ma;rmi=mi;
	mi=LINF;
	ll bmi=LINF;
	int co=n;
	vector<P> v;
	for(int i=0;i<n;i++){
		if(i!=miid){
			v.push_back(P(y[i],i));
			bmi=min(bmi,y[i]);
			bma=max(bma,y[i]);
		}else{
			v.push_back(P(x[i],i));
			bmi=min(bmi,x[i]);
			bma=max(bma,x[i]);
		}
	}
	sort(all(v));
	ll bmi2=LINF;
	for(int i=0;i<n;i++){
		mi=min(mi,bma-min(bmi2,v[i].first));
		bma=max(bma,x[v[i].second]);
		bmi2=min(bmi2,x[v[i].second]);
		if(v[i].second==miid)break;
	}
	ans=min(ans,(rma-rmi)*mi);
	cout<<ans<<endl;
}
