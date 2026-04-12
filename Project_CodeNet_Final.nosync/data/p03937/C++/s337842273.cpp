#include "bits/stdc++.h"
#define int long long
#define range(i, a, b) for(auto i = a; i < b; i++)
#define rep(i, a) range(i, 0, a)
#define all(a) (a).begin(),(a).end()
using namespace std;
const int MOD = 1e9 + 7, INF = 1e17;
using vi = vector <int>;
using vvi = vector <vi>;
//g++ -std==c++14

signed main(){
	int h, w;
	cin >> h >> w;
	vector <vector <char>> a(h, vector <char> (w));
	int cnt = 0;
	rep(i, h)rep(j, w){
		cin >> a[i][j];
		cnt += a[i][j] == '#';
	}

	cout << (cnt == h + w - 1 ? "Possible" : "Impossible") << endl;

}
