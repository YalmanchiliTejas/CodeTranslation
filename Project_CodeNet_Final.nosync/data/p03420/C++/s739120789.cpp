#include <iostream>

#include <iomanip>

#include <algorithm>

#include <vector>

#include <stack>

#include <queue>

#include <cmath>

#include <set>

#include <map>



using namespace std;


const int INF = 100000;

typedef pair<int, int> P;
typedef long long ll;

char maze[100][101];

ll n, m;
ll k;
int sx, sy;

int gx, gy;



//各座標までの最短距離

int d[100][100];


//移動方向のベクトル

int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

int main() {

	cin >> n >> k;
	ll sum = 0;
	if (k == 0) {
		sum = n * n;
		cout << sum << endl;
		return 0;
	}
	for (int i = k + 1; i <= n; i++) {
		sum += (n / i)*(i - k);
		int res = n - n / i * i;
		if (k <= res) sum += res-k+1;
	}
	cout << sum << endl;
	int qqq; cin >> qqq;
	return 0;

}