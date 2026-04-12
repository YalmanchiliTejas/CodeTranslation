#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)



double r1, r2;
//-----------------------------------------------------------------
int main() {
	cin >> r1 >> r2;
	double ans = 1.0 / (1.0 / r1 + 1.0 / r2);
	printf("%.10f\n", ans);
}