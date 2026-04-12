#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int r, g, b;
	cin >> r >> g >> b;

	int x = 100 * r + 10 * g + b;
	if(x % 4 == 0){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}
