#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <cstring>

using namespace std;
const int INF = (1<<30);
typedef pair<int, int> P;
typedef long long ll;
#define PB push_back
#define rep(i, a) for (int i = 0; i < a; i++)

int sx, sy;

int gx, gy;

int qqq;

//各座標までの最短距離
int d[100][100];


//移動方向のベクトル
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

//汎用
ll ans = 0;
pair<int, int> red[101], blue[101];
ll BIG = 10000000000;

//累乗
ll POW(ll a, ll b) {
ll c = 1;
for (int i = 0; i < b; ++i) {
c *= a;
}
return c;
}

//階乗
int Kaijou(int a) {
if (a < 2) return 1;
return a * Kaijou(a - 1);
}


int A[200000];
int kinds[200001];


int main() 
{
	int n;
	while(1){
		cin >> n;
		if (n == 0) break;

		vector<int> s(n);
		rep(i, n) cin >> s[i];
		sort(s.begin(), s.end());
		int sum = 0;
		for (int i = 1; i < n - 1; ++i)
			sum +=s[i];
		int ave = sum / (n - 2);
		cout << ave << endl;
	}
	cin >> qqq;
}

