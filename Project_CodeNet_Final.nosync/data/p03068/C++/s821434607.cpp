#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 110;
string s;
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		char vis;
		cin >> s;
		int k;
		cin >> k;
		vis = s[k-1];
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != vis)
				s[i] = '*';
		}
		cout << s << endl;
	}

	//system("pause");
}

