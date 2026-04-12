#include "bits/stdc++.h"
using namespace std;

int main() {
	int A,B,C,X,Y;
	cin >>  A >> B >> C >> X >> Y;
	long long int s = 99999999999;

	for(int i=0;i<=100000;i++){
		int a,b;
		a = max(0,X-i);
		b = max(0,Y-i);
		//cout << a << b;
		long long int s1 = 2*C*i + A*a + B*b;
		s = min(s,s1);
	}
	cout << s << endl;

}
