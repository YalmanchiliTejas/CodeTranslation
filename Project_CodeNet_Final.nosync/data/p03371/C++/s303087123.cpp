//ABC095C
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <math.h>
#include <stdio.h>
#include <climits>
#include <cfloat>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	long long int ans = 1e9;
	long long int m = 2*max(x,y);
	for(int i=0;i<=m;i+=2){
		long long p = i*c+max(0,x-i/2)*a+max(0,(y-i/2)*b);
		ans = min(ans,p);
	}
	cout << ans << endl;
	return 0;
}