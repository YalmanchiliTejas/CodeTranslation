#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> x;
	vector<int> in;
	for (int i = 0;i < n;i++){
		int c; cin >> c;
		x.push_back(c);
		in.push_back(c);
	}	

	sort(x.begin(),x.end());

	int cent = x[n/2 - 1];

	for (int i = 0;i < n;i++){
		if(in[i] <= cent) cout << x[n/2] << endl;
		else cout << x[n/2-1] << endl;
	}

	return 0;

}
