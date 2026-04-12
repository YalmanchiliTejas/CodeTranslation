#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

int n, a[100009];
multiset<int> mst;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int cur = 1;
	mst.insert(a[0]);
	cur++;
	for (int i = 1; i < n; i++) {
		auto p = mst.lower_bound(a[i]);
		if (p == mst.begin()) {
			cur++;
			mst.insert(a[i]);
		}
		else {
			p--;
			mst.erase(p);
			mst.insert(a[i]);
		}
	}
	cout << cur - 1 << E;
	//system("pause");
	return 0;
}