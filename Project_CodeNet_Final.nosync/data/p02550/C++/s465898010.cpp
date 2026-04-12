#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100100;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	ll n,x,m;cin>>n>>x>>m;
	ll res=0;
	set<ll>c;
	vector<ll>nums(N,0);
	for(ll i=0;i<n&&x%m;++i){
		if(c.count(x)){
			ll idx=0,sm=0,oversm=0;
			while(nums[idx]!=x)++idx;
			for(ll j=idx;j<i;++j)sm+=nums[j];
			ll len=i-idx;
			ll cnt=(n-i)/len;
			ll over=n-i-((n-i)/len*len);
			for(ll j=idx;j<idx+over;++j)oversm+=nums[j];
			res=res+cnt*sm+oversm;
			break;
		}
		c.insert(x);
		nums[i]=x;
		res+=x;
		x=x*x%m;
	}
	cout<<res<<endl;
}
