#include "bits/stdc++.h"
using namespace std;

int main() {
	int A,B,C,X,Y;
	cin >>  A >> B >> C >> X >> Y;
	long long int ans,tmp;
	int a = X,b = Y,c=0;

	ans = A*a + B*b + C*c;
	while(a>0 || b>0){
		a = max(a-1,0);
		b = max(b-1,0);
		c += 2;
		tmp = a*A + b*B + c*C;
		if(tmp < ans){
			ans = tmp;
		}
	}
	 cout << ans << endl;
}
