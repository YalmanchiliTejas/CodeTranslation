#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<iomanip>
#include<bitset>
#include<cstdlib>
#include<queue>
#include<utility> //pair
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

typedef long long ll;

int main() {
	//入力;
	int x;
	cin >> x;
	if (x == 3 || x == 5 || x == 7) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;

	//小数点以下の桁数表示;
	//cout << fixed << setprecision(15);


	return 0;
}