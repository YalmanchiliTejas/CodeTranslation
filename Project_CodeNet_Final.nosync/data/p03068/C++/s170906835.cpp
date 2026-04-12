#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

#define PB push_back
#define ALL(v) (v).begin(), (v).end()
#define SZ size()
#define FOR(i, a, b) for(int (i) = (a); (i) < (b); (i)++)
#define REP(i, n) FOR((i), 0, (n))
#define GET(a) cin >> (a)
#define GET2(a, b) cin >> (a) >> (b)
#define GET3(a, b, c) cin >> (a) >> (b) >> (c)
#define SHOW(v) cout << (v) << endl
#define SHOW2(a, b) cout << (a) << " " << (b) << endl
#define SHOW3(a, b, c) cout << (a) << " " << (b) << " " << (c) << endl
#define MOD 1000000007
template<class T> void GETV(T &v) { REP(i, v.size()) { GET(v[i]); } }
template<class T> void SHOWV(T &v) { REP(i, v.size()) { SHOW(v[i]); } }

typedef long long ll;

int main() {
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	int k;
	cin >> k;
	
	char check = s[k - 1];
	
	for(int i = 0; i < n; i++) {
		if(check == s[i]) {
			cout << s[i];
		}
		else {
			cout << "*";
		}
	}
	cout << endl;
	
    return 0;
}