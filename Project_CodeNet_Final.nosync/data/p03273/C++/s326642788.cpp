#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i, m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define rep(i, n) REP(i, 0, n)
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;





int main(){

	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	for (int i = 0; i < h; i++){
		cin >> a[i];
	}

	vector<bool> row(h, false);
	vector<bool> col(w, false);

	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			if (a[i][j] == '#'){
				row[i] = true;
				col[j] = true;
			}
		}
	}

	for (int i = 0; i < h; i++){
		if (row[i]){
			for (int j = 0; j < w; j++){
				if (col[j]){
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}

	return 0;
}