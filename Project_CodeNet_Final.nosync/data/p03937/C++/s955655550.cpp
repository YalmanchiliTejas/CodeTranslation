#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll h, w; cin >> h >> w;
	string s[h];
	for(ll i = 0; i < h; ++i) cin >> s[i];
	ll si = 0, na = 1;
	for(ll i = 0; i < h; ++i)for(ll j = 0; j < w; ++j) si += (s[i][j] == '#' ? 1 : 0);
	pair<ll, ll> now = pair<ll, ll>(0, 0);
	while(now.first != h - 1 || now.second != w - 1){
		ll dx[] = {1, 0};
		ll dy[] = {0, 1};
		bool po = 0;
		pair<ll, ll> tmp;
		for(ll i = 0; i < 2; ++i){
			pair<ll, ll> next = pair<ll, ll>(now.first + dx[i], now.second + dy[i]);
			if(next.first == h || next.second == w) continue;
			if(s[next.first][next.second] == '.') continue;
			if(po){
				cout << "Impossible\n";
				return 0;
			}
			po = 1;
			tmp = next;
		}
		if(!po){
			cout << "Impossible\n";
			return 0;
		}
		now = tmp;
		na++;
	}
	cout << (si == na ? "Possible\n" : "Impossible\n");
	return 0;
}