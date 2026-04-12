#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
	string s;
	cin >> s;
	int cnt1 = count(s.begin(), s.end(), 'A');
	int cnt2 = count(s.begin(), s.end(), 'B');
	if (cnt1 > 0 && cnt2 > 0) puts("Yes");
	else puts("No");
	return 0;
}