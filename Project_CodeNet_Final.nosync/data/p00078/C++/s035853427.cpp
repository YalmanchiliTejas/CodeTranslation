#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>

using namespace std;

int a[15][15];

void solve(int n){
	memset(a,0,sizeof(a));
	int x = n/2,y = x+1;
	for (int i = 1; i <= n*n; i++,x++,y++){
		while(true){
			if(y < 0) y += n;
			if(y >= n) y -= n;
			if(x < 0) x += n;
			if(x >= n) x -= n;
			if(a[y][x] == 0) break;
			x--; y++;
		}
		a[y][x] = i;
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("%4d",a[i][j]);
		}
		puts("");
	}
}

int main(){
	int n;
	while(cin>>n,n){
		solve(n);
	}
    return 0;
}