#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
	int n, k;
	string s;
	cin >> n >> s >> k;

	//vector<int> v(n);
	//for (size_t i = 0; i < n; i++)
	//{
	//	cin >> v[i];
	//}
	char c = s[k - 1];
	for (size_t i = 0; i < n; i++)
	{
		if (s[i] != c) s[i] = '*';
	}

	cout << s << endl;
}


