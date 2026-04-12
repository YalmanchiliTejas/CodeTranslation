#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;


vector<int>  dx = {1,-1,0,0};
vector<int>  dy = {0,0,1,-1};


int main() {
	int r,g,b; cin >> r >> g >> b;

	if ((10 * g + b) % 4 == 0) {
		cout << "YES" << endl;
	}else {
		cout << "NO" << endl;
	}


	return 0;
}
