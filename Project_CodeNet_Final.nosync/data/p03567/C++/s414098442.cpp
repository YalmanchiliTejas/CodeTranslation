#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
#define REP(i, a, n) for(int i=a; i<n; i++)
#define RREP(i, a, n) for(int i=n-1; i>=a; i--)
#define INF 1000000000
#define ll long long

int n, m;
string s;
int main()
{
	cin >> s;
	bool flag = false;
	REP(i, 0, s.size() - 1) {
		if (s[i] == 'A' && s[i + 1] == 'C') {
			flag = true;
			break;
		}
	}
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}