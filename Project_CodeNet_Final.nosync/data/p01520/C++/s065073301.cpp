#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
 
int main() {
	int N, T, E;
	cin >> N >> T >> E;
	vector<int> v(N);
	REP(i,N) cin >> v[i];
	int ans = -2;
	REP(i,N) {
		int c = v[i];
		for(int j = 1; j * c <= T + E; j++) {
			if(T - E <= j * c && j * c <= T + E)
				ans = i;
		}
	}
	cout << 1 + ans << endl;
}