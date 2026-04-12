#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, s, n) for(int i = s; i < n; ++i)
#define rep(i, n)		 REP(i, 0, n)
#define SORT(c)			 sort((c).begin(), (c).end())
#define IINF					INT_MAX
#define LLINF					LLONG_MAX
#define DEBUG					false
 
typedef long long				ll;
typedef pair <int, int> ii;

int main() {
	
	vector<int>a(12);
	rep(i, 12) cin >> a[i];
	SORT(a);
	
	bool flag = true;
	rep(i, 3){
		if(a[i*4] != a[i*4+1] || a[i*4] != a[i*4+2] || a[i*4] != a[i*4+3]) {
			flag = false;
			break;
		}
	}
	
	cout << (flag ? "yes" : "no") << endl;
	
	return 0;
}