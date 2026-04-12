
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main() {
	int n;cin>>n;
	vector<ll> x(n),y(n),a(n),b(n);
	vector<pair<ll,ll>> p(n);
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
		a[i]=x[i];
		b[i]=y[i];
		if(x[i]<y[i]){
			a[i]=y[i];
			b[i]=x[i];
		}
		p[i].first=a[i];
		p[i].second=b[i];
	}
	sort(p.begin(),p.end(),greater<pair<ll,ll>>());
	sort(a.begin(),a.end(),greater<ll>());
	sort(b.begin(),b.end(),greater<ll>());
	ll max=a[0];
	ll min=b[n-1];
	ll ans=(a[0]-a[n-1])*(b[0]-b[n-1]);
	ll max2=p[0].second;
	ll min2=a[n-1];
	ll sub=a[0]-a[n-1];
	for(int i=0;i<n-1;i++){
		if(min2>p[i].second){
			min2=p[i].second;
		}
		if(max2<p[i].second){
			max2=p[i].second;
		}
		if(max2<p[i+1].first){
			if(sub>p[i+1].first-min2){
				sub=p[i+1].first-min2;
			}
		}else{
			if(sub>max2-min2){
				sub=max2-min2;
			}
			break;
		}
	}
	if(ans>(max-min)*sub){
		ans=(max-min)*sub;
	}
	cout<<ans<<endl;
	return 0;
}