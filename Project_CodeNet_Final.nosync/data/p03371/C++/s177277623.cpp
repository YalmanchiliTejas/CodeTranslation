#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <math.h>
#define INF 1000000007
using namespace std;

int main(void) {
	long long a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	long long half=min(x,y);
	long long ans=0;
	ans+=a+b<=c*2?(a+b)*half:c*2*half;
	ans+=a<=c*2?a*(x-half):c*2*(x-half);
	ans+=b<=c*2?b*(y-half):c*2*(y-half);
	cout << ans << endl;
	return 0;
}