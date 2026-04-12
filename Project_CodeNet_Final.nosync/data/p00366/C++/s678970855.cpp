#define _AOJ_
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long long lint;
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,a,b) for(int i=a;i<b;++i)

int main(){
	lint n;cin>>n;
	vector<lint>a(n);
	lint mx=0;
	rep(i,n)cin>>a[i],mx=max(mx,a[i]);
	set<lint> s;
	for(int i=1;i*i<=mx;++i){
		if(mx%i==0){
			if(i*i==mx)s.insert(i);
			else s.insert(i),s.insert(mx/i);
		}
	}
	lint ans=0;
	rep(i,n){
		ans+=*s.lower_bound(a[i])-a[i];
	}
	cout<<ans<<endl;
}
//sub-EOF
