#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(int argc, char const *argv[])
{
	string s; cin >> s;
	bool flag = false;
	rep(i, 2) {
		if (s[i] != s[i + 1]) {
			flag = true;
		}
	}
	cout << (flag ? "Yes" : "No") << endl;
	return 0;
}
