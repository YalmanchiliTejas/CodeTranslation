#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	string n;
	int k;
	cin>>n;
	cin>>k;
	n = "0" + n;
	
	long long d[112][2][10];
	
	for (int i = 0; i < n.size(); i++)
	for (int eq = 0; eq <= 1; eq++)
	for (int t = 0; t <= k; t++)
		d[i][eq][t] = 0;
	
	
	d[0][1][0] = 1;
		
	for (int i = 1; i < n.size(); i++)
	for (int iseq = 0; iseq <= 1; iseq++)
	for (int cnt = 0; cnt <= k; cnt++) {
		d[i][iseq][cnt] = 0;
		
		if (iseq == 1) {
			d[i][iseq][cnt] += (cnt - (n[i] != '0') >= 0) * d[i - 1][1][cnt - (n[i] != '0')];
			continue;
		}
		
		for (int ch = 0; ch <= 9; ch++) {
			d[i][iseq][cnt] += (cnt >= (ch != 0)) * (d[i - 1][0][cnt - (ch != 0)] + ('0' + ch < n[i]) * d[i - 1][1][cnt - (ch != 0)]);
		}
	}
	long long res = d[n.size() - 1][1][k] + d[n.size() - 1][0][k];
	cout<<res<<"\n";
}
