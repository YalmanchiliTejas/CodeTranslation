#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i, s, n) for(int (i)=(s); (i)<(int)(n); (i)++)
#define REP(i, n) for(int (i)=0; (i)<(int)(n); (i)++)
#define REV(i, n) for(int (i)=(n)-1; (i)>=0; (i)--)
typedef long long int lli;
const lli inf = 1e18;

int main(){
	int n;
	cin >> n;
	vector<int> x(n), cp;
	REP(i, n) cin >> x[i];
	cp = x;
	sort(x.begin(), x.end());
	int m1 = x[n/2-1], m2 = x[n/2];
	REP(i, n){
		if(cp[i] <= m1) cout << m2 << endl;
		else cout << m1 << endl;
	}
	return 0;
}
