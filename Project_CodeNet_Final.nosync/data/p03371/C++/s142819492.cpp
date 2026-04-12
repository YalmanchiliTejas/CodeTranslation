#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <numeric>
#include <bitset>
#include <map>
#include <limits.h>
using namespace std;
typedef unsigned long ul;
typedef pair<ul, ul> P;
const int INF = 1e9;

long long gcd(long long x, long long y){
			if(x<y){
				long long temp = x;
			x = y;
				y = temp;
			}
			long long r = x % y;
				while(r!=0){
					x = y;
					y = r;
				r = x % y;
	    		}
			return y;
	    }

int main(){
int A,B,C,X,Y;
cin >> A >> B >> C >> X >> Y;
long long  ans = 0;
if(A+B>2*C){
	long long ans_1 = C*2*min(X,Y);
	if(X>Y){
		ans_1 += A*(X-Y);
	}
	else{
		ans_1 += B*(Y-X);
	}

	long long ans_2 = C*2*max(X,Y);
	ans = min(ans_1,ans_2);
}
else{
	ans += A*X + B*Y;
}
cout << ans << endl;
}