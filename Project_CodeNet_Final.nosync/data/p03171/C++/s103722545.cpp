#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> psum(n+2);
	vector<vector<ll>> v(n+2,vector<ll>(n+2));
	for (int i=1; i<=n; ++i){
		cin >> v[1][i];
		psum[i] = psum[i-1] + v[1][i];
	}
	for (int h=2; h<=n; ++h){
		for (int b=1; b<=n-h+1; ++b){
			int e=b+(h-1);
			v[h][b]=(psum[e]-psum[b-1])-min(v[h-1][b],v[h-1][b+1]);
		}
	}
	cout << 2*v[n][1]-psum[n];
	return 0;
}