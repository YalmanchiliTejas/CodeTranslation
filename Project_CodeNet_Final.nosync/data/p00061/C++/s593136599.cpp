#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <string>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
//#include <tuple>
using namespace std;
#define rep(i,n) for(LL i=0;i<n;i++)
#define all(v)	(v).begin(),(v).end()
#define MOD  1000000007
const int INF = INT_MAX;
typedef long long LL;
typedef pair<int, int> pii;
//typedef tuple<int, int> tii;

int main(){
	int x, y;
	bool p[31];
	rep(i, 31) p[i] = false;
	map<int, int> m;
	while (scanf("%d,%d", &x, &y)){
		if (x == 0 && y == 0) break;
		p[y] = true;
		m[x] = y;
	}
	int n;
	
	while (cin >> n){
		int ans = 0;
		for (int i = 30; i >= m[n]; i--){
			if (p[i]) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}