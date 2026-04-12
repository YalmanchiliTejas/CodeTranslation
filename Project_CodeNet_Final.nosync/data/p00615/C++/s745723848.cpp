#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
	int n, m;
	while(cin >> n >> m) {
		if(n == 0 && m == 0) break;

		vector<int> v(n+m);
		rep(i,n) cin >> v[i];
		rep(i,m) cin >> v[n+i];

		sort(v.begin(), v.end());
		v.insert(v.begin(), 0);

		int ans = 0;
		REP(i,1,v.size()) {
			ans = max(ans, v[i] - v[i-1]);
		}

		cout << ans << endl;
	}

	return 0;
}