#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <sstream>
#include <cmath>
#include <climits>
#include <set>
#include <iostream>
#include <map>
#include <functional>
#include <cstdlib>
#include <numeric>
#include <queue>
#include <complex>

using namespace std;

#define reep(i,f,n) for(int i=f; i<int(n); ++i)
#define rep(i,n) reep(i,0,n)

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef complex<double> Point;

int main()
{
	int n;
	while(scanf("%d", &n), n){
		vector<vi> field(n, vi(n, 0));

		int i = n/2, j = n/2+1;
		int cnt = 1;
		while(cnt<=n*n){
			if(i<0)
				i = n-1;
			else if(n<=i)
				i = 0;
			else if(n<=j)
				j = 0;
			else if(field[j][i]){
				i--;
				j++;
			}else{
				field[j][i] = cnt++;
				i++;
				j++;
			}
		}

		rep(k, n){
			rep(l, n)
				printf("%4d", field[k][l]);
			puts("");
		}
	}

	return 0;
}