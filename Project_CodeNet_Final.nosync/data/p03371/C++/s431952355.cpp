#include <bits/stdc++.h>
typedef long long ll;
#define REP(i,a) for(int i = 0; i < (a); i++)
using namespace std;

int main(){
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	int tmp;
	if(x > y)tmp = a;
	else tmp = b;
	cout << min(a * x + b * y, min(c * 2 * max(x, y), c * 2 * min(x, y) + tmp * abs(x - y))) << endl;
}