#include <bits/stdc++.h>
using namespace std;
//cin.sync_with_stdio(false);

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i,n) FOR(i,0,n)

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> Vector;
typedef vector<Vector>	DVector;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	int cash = 0;
	int n = min(x, y);
	int deal = min(a+b, c*2);

	cash = deal * n;

	n = max(x, y) - n;

	if(x >= y){
		deal = min(a, c*2);
	}else{
		deal = min(b, c*2);
	}
	cash += deal * n;
	cout << cash << endl;
	return 0;
}