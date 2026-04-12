#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cstdio>
#include <cctype>
#include <queue>
#include <complex>
#include <climits>

typedef long long ll;

using namespace std;

int main(void){
	int n;
	while(cin >> n){
		if(!n) break;
		int d[15][15] = {0};
		int nx = (n-1)/2;
		int ny = (n+1)/2;
		for(int i=0; i<n*n; ++i){
			if(nx < 0) nx = n-1;
			if(nx >= n) nx = 0;
			if(ny >= n) ny = 0;
			while(d[ny][nx]){
				nx--, ny++;
				if(nx < 0) nx = n-1;	
				if(nx >= n) nx = 0;
				if(ny >= n) ny = 0;
			}
			d[ny][nx] = i+1;
			nx++, ny++;
		}
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j){
				if(j != n-1) printf("%4d", d[i][j]);
				else printf("%4d\n", d[i][j]);
			}
		}
	}

	return 0;
}