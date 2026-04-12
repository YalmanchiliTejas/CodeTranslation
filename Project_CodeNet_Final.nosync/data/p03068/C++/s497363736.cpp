#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

using namespace std;
int main() {
	int n, k;
	cin >> n;
	string s;
	cin >> s;
	cin >> k;
	rep(i, s.size()) {
		if (s.at(i) != s.at(k - 1)) s.at(i) = '*';
	}
	cout << s << endl;
	return 0;
}
