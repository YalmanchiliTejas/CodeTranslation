#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> h, m;
int ans;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	h.resize(n); m.resize(n);
	for(auto &i:h) cin >> i;
	m[0] = h[0];
	for(int i=1; i<n; ++i) m[i] = max(m[i-1], h[i]);
	for(int i=0; i<n; ++i)
		if(m[i] == h[i])
			++ans;
	cout << ans << "\n";
}