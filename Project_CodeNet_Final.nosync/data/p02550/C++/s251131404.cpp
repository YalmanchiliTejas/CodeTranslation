#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,x,m;
	cin >> n >> x >> m;
	map<ll,int> pos,mp;
	ll ans = 0;
	vector<ll> elements(m+5,0);
	elements[1] = x;
	++mp[x];
	pos[x] = 1;
	int l = -1,r = -1;
	for(int i = 2; i <= n;++i){
		ll next = (elements[i-1] * elements[i-1])%m;
		if(mp.count(next) == 1){
			l = pos[next];
			r = i-1;
			break;
		}
		++mp[next];
		pos[next] = i;
		elements[i] = next;
	}
	for(int i = 1; i <= l-1;++i){
		ans += elements[i];
	}
	if(l != -1){
		int len = r-l+1;
		ll temp = 0;
		for(int i = l; i <= r;++i){
			temp += elements[i];
		}
		n = n - l + 1;
		ans += (n/len) * temp;
		for(int i = l; i < l + n%len;++i){
			ans += elements[i];
		}
	}
	else{
		for(int i = 1; i <= n;++i){
			ans += elements[i];
		}
	}
	cout << ans << "\n";
}
