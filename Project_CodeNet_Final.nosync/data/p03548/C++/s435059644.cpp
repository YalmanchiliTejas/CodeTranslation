#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int x, y, z;
	cin >> x >> y >> z;

	x -= 2 * z;
	if(x < y){
		cout << 0 << endl;
		return 0;
	}

	x -= y;

	cout << x / (y + z) + 1 << endl;

}
