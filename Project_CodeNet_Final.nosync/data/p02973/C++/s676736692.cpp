#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 
map <ll,ll>a;
int main() {
	ll n;
	cin>>n;
	a[-1]++;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		auto now=a.lower_bound(x);
		now--;
		ll sea=now->first;
		if(sea==-1){
			a[x]++;
		}
		else {
			a[sea]--;
			a[x]++;
			if(a[sea]==0){
				a.erase(sea);
			}
		}
	}
	ll ans=0;
    for(auto itr = a.begin(); itr != a.end(); ++itr) {
         ans+= itr->second ;    // 値を表示
    }	
    cout << ans-1;
	// your code goes here
	return 0;
}