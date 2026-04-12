/*In the name of Allah*/
#include <bits/stdc++.h>
using namespace std;
#define inf 1000000111
#define MAX 200111
#define mod 998244353
#define ll long long

multiset<ll> s;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	ll ans = 1,x;
	cin>>n>>x;
	s.insert(inf - x);
	for(int i = 1; i < n; i++){
		cin>>x;
		auto it = s.upper_bound(inf - x);
		if(it != s.end()){
			// cout<<inf - *it<<" ";
			s.erase(it);
			s.insert(inf - x);
		}else{
			s.insert(inf - x);
			ans++;
		}
	}
	cout<<ans;

	return 0;
}
