#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<numeric>
#include<cmath>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define VSORT(v) sort(v.begin(), v.end());
#define VE vector<int>
#define llong long long
#define pb(a) push_back(a)
using namespace std;
int main() {
	int l, index;
	string str;
	cin >> l;
	cin >> str;
	cin >> index;
	char c = str[index-1];
	REP(i, str.size()) {
		if (str[i] != c) {
			str[i] = '*';
		}
	}
	cout << str << endl;
	return 0;
}