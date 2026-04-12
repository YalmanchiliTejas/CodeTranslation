#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> pii;

#define min(a, b) ((a) < (b)? (a):(b))
#define max(a, b) ((a) > (b)? (a):(b))
#define abs(a) ((a) < (0)? -(a):(a))
#define rep(i, n) REP(i, 0, (n))
#define REP(i, a, n) for(int i=(a); i<(n); i++)
#define pb push_back


int main() {
	int n;
	cin >> n;
	int ans = 0, h_max = -1;
	rep(i, n) {
	    int h;
	    cin >> h;
	    if(h >= h_max) {
	        ans += 1;
	        h_max = h;
	    }
	}
	cout << ans << endl;
}
