#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5+5;

string s;
bool A, B;

int main() {
//#define LOCAL
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	for(int i = 0; i < s.length(); ++i) {
		if(s[i] == 'A') A = true;
		if(s[i] == 'B') B = true;
	}
	if(A & B) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}

