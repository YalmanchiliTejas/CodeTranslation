#include <bits/stdc++.h>
using namespace std;

int distt[301];
int dists[301];

int main() {
	int N, s, t;
	cin >> N >> s >> t;
	vector<pair<int, int>> K;
	cout << "? " << s << " " << t << endl;
	cin >> distt[s];
	dists[t] = distt[s];
	for(int n = 1; n <= N; n++) {
		if (n == s or n == t) continue;
		cout << "? " << s << " " << n << endl;
		cin >> dists[n];
		cout << "? " << t << " " << n << endl;
		cin >> distt[n];
		if (distt[n] + dists[n] == distt[s]){
			K.push_back(make_pair(dists[n], n));
		}
	}
	sort(K.begin(), K.end());
	vector<int> ans;
	ans.push_back(s);
	for(int i = 0; i < K.size(); i++) {
		int q = (int)ans.size();
		q -= 1;
		int p = K[i].second;
		cout << "? " << ans[q] << " " << p << endl;
		int an;
		cin >> an;
		if (dists[ans[q]] + an + distt[p] == distt[s]) {
			ans.push_back(p);
		}
	}
	ans.push_back(t);
	cout << "! ";
	for(int i = 0; i < ans.size(); i++) {
		if (i + 1==ans.size()) cout << ans[i] << endl;
		else cout << ans[i] << " ";
	}
}
