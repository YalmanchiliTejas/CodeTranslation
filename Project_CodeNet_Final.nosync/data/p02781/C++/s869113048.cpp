#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

string s;
ll x, n, lim, d[105][2][5]={1};
int main() {
	ll i, j, k, l;
	cin >> s >> x;
	n = s.size();
	for(i=0; i<n; i++) {
		for(j=0; j<2; j++) {
			lim = (j ? 9 : s[i]-'0');
			for(k=0; k<=x; k++) {
				for(l=0; l<=lim; l++) {
					d[i+1][j||l<lim][k+(l>0)] += d[i][j][k];
				}
			}
		}
	}
	cout << d[n][0][x] + d[n][1][x];
	return 0;
}