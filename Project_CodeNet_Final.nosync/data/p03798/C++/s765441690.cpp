#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<functional>
#include<map>
#include<set>
#include<string.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int n;
string s;
bool b[100010];
bool a[] = { 0,0,1,1 };
int main() {
	cin >> n >> s;
	do {
		b[0] = a[0];
		b[1] = a[1];
		for (int i = 1; i < n - 1; i++) {
			if (s[i] == 'o') {
				if (!b[i])b[i + 1] = b[i - 1];
				else {
					if (b[i - 1])b[i + 1] = 0;
					else b[i + 1] = 1;
				}
			}
			else {
				if (!b[i]) {
					if (b[i - 1])b[i + 1] = 0;
					else b[i + 1] = 1;
				}
				else b[i + 1] = b[i - 1];
			}
		}
		if (!b[n - 1] && s[n - 1] == 'o'&&b[n - 2] != b[0])continue;
		if (!b[n - 1] && s[n - 1] == 'x'&&b[n - 2] == b[0])continue;
		if (b[n - 1] && s[n - 1] == 'o'&&b[n - 2] == b[0])continue;
		if (b[n - 1] && s[n - 1] == 'x'&&b[n - 2] != b[0])continue;
		if (!b[0] && s[0] == 'o'&&b[n - 1] != b[1])continue;
		if (!b[0] && s[0] == 'x'&&b[n - 1] == b[1])continue;
		if (b[0] && s[0] == 'o'&&b[n - 1] == b[1])continue;
		if (b[0] && s[0] == 'x'&&b[n - 1] != b[1])continue;
		for (int i = 0; i < n; i++){
			if (!b[i])cout << 'S';
			else cout << 'W';
		}
		cout << endl;
		return 0;
	} while (next_permutation(a, a + 4));
	cout << -1 << endl;
	return 0;
}