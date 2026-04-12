#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

int main() {
	ll n;
	cin>>n;
	map<ll,ll>a;
	a[-1]++;
	for(ll i=0;i<n;i++){
		ll now;
		cin>>now;
		a[now]++;
		auto itr=a.lower_bound(now);
		itr--;
		if(itr==a.begin()){
			continue;
		}
		else{
			a[itr->first]--;
			if(itr->second==0){
				a.erase(itr);
			}
			//cout << itr->first;
			//cout << itr->second<<endl;
		}
	}
	ll ans=0;
	for(auto itr=a.begin();itr!=a.end();itr++){
		ans+=itr->second;
	//	cout <<itr->second;
	//	cout << itr->first<<endl;
	}
	cout <<ans-1;
	// your code goes here
	return 0;
}