#include <bits/stdc++.h>
#define INF (1<<30)
#define MOD 1000000007
#define l_ength size
using ll = long long;
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	bool graph[n][n];
	for( int i = 0; i < n; ++i ){
		for(  int j = 0; j < n; ++j ){
			graph[i][j] = false;
		}
	}
	for( int i = 0; i < m; ++i ){
		int x, y;
		cin >> x >> y;
		--x; --y;
		graph[x][y] = true;
		graph[y][x] = true;
	}
	vector<int> v(n-1);
	iota(v.begin(), v.end(), 1);
    int ans = 0;
	do {
		bool flag = true;
		if( !graph[0][v.at(0)] ){
			continue;
		}
		for( int i = 0; i < n-2; ++i ){
			if( !graph[v.at(i)][v.at(i+1)] ){
				flag = false;
				break;	
			}
		}
		if( flag ) ++ans;
    } while( next_permutation(v.begin(), v.end()) );
	cout << ans << endl;
	return 0;
}