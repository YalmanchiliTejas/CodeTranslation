#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
typedef long long ll;
 
int main() {
	int n,m,a,b,g[9][9] = {},z=0;
	cin >> n >> m;
	for (int i=0;i<m;i++) cin >> a >> b, g[a][b] = g[b][a] = 1;
	int c[8] = {1,2,3,4,5,6,7,8};
	do {
		bool y=1;
		for (int i=1;i<n;i++) {
			if (g[c[i-1]][c[i]]==0) y=0;
		}
		if (y) z++;
	} while (next_permutation(c+1,c+n));
	cout << z;
}