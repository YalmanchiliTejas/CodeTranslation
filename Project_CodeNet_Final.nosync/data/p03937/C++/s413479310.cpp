#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <functional>
#include <queue>
#include <cmath>
#include <utility>

using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define rep1(i,n) for(int i=1;i<=(int)n;++i)

string A[8];
signed main()
{
	int h,w;cin>>h>>w;
	rep(i,h)cin>>A[i];
	rep(i,h)rep(j,w) {
		if (A[i][j] != '#') continue;
		if (i+1<h and j+1<w and A[i+1][j] == '#' and A[i][j+1] == '#') {
			cout << "Impossible\n";
			return 0;
		}
		if (i-1>=0 and j-1>=0 and A[i-1][j] == '#' and A[i][j-1] == '#') {
			cout << "Impossible\n";
			return 0;
		}
	}

	cout << "Possible\n";
}
