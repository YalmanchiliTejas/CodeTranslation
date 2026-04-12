#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
typedef long long ll;
int main(){

	int n;
	cin >> n;
	vector<int> h;
	rep(i,n) {
		int a;
		cin >> a;
		h.push_back(a);
	}

	int ans = 1;
	FOR(i,1,n) {
		bool flag = true;
		FOR(j,0,i) {
			if (h[j]>h[i]) {
				flag = false;
				break;
			}
		}
		if (!flag) {
			continue;
		}
		ans++;
	}

	cout << ans << endl;
}