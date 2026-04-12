#include <bits/stdc++.h>
using namespace std;

int main(){
	double r1,r2;
	cin >> r1 >> r2;
	double ans = 1/(1/r1+ 1/r2);
	cout.precision(13);
	cout << ans << '\n';
}
