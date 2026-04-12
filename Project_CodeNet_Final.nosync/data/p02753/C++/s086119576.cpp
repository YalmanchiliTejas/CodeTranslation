#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define REPR(i, n) for(int i=n-1; i>=0; i--)
#define FOR(i, m, n) for(int i=m; i<n; i++)
#define FORR(i, m, n) for(int i=m-1; i>=n; i--)
#define SORT(v, n) sort(v, v+n);
#define REVERSE(v) reverse(v.begin(), v.end());
#define DEBUG(x) cout<<#x<<": "<<x<<"\n"


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S;
	cin >> S;

	bool can = true;
	if (S[0] == S[1] && S[0] == S[2]) can = false;
	if (can) cout << "Yes" << "\n";
	else cout << "No" << "\n";
}
