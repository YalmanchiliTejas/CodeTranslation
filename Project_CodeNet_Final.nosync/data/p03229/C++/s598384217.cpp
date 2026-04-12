#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
int main(){
	ll m,n,i,j,k;
	cin>>m;
	for(i=1;i<=m;i++) cin>>a[i];
	sort(a+1,a+1+m);
	multiset<ll> s,ss;
	for(i=1;i<m;i++){
		s.insert(a[i]);
		ss.insert(-a[i]);
	}
	multiset<ll>::iterator it;	
	ll ans=0,l=a[m],r=a[m];
	for(i=1;i<m;i++){
		ll mx=-*ss.begin();
		ll mi=*s.begin();
		ll tmp=max(max(abs(l-mx),abs(l-mi)),max(abs(r-mx),abs(r-mi)));
		ll chose;
		if(abs(l-mx)==tmp){
			ans+=abs(l-mx);
			l=mx;
			chose=mx;
			goto l;
		}
		if(abs(l-mi)==tmp){
			ans+=abs(l-mi);
			l=mi;
			chose=mi;
			goto l;
		}
		if(abs(r-mx)==tmp){
			ans+=abs(r-mx);
			r=mx;
			chose=mx;
			goto l;
		}
		if(abs(r-mi)==tmp){
			ans+=abs(r-mi);
			r=mi;
			chose=mi;
			goto l;
		}
		l:;
		it=s.lower_bound(chose);
		s.erase(it);
		it=ss.lower_bound(-chose);
		ss.erase(it);
	}
	cout<<ans<<endl;
}