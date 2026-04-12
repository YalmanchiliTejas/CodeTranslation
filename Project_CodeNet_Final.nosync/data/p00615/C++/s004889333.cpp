#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>

using namespace std;

#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,N) for(long long i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()

#define PI acos(-1.0)
#define INF 10000000

typedef long long ll;

int n, m, t, k = -1;
vector<int> vi;

int main(){
	while (cin >> n >> m){
		if (n + m == 0)break;
		vi.push_back(0);
		REP(i, n + m){
			cin >> t;
			vi.push_back(t);
		}
		sort(ALL(vi));
		REP(i, vi.size() - 1){
			k = max(k, vi[i + 1] - vi[i]);
		}
		cout << k << endl;
		k = -1;
		vi.clear();
	}
}