#include<iostream>
#include<functional>
#include<utility>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;
const auto MOD = 1000000007;
const int INF = 1e9;
const long long LINF = 1e18;
#define rep(i,n) for(int i = 0; i < (n);i++)
typedef pair<int, int> PII;
typedef pair<long, long> PLL;
typedef vector<int> VI;
typedef vector<long long> VLL;

// index が条件を満たすかどうか vector<>maeに検索したいvectorを入れる keyを超える最小の要素番号を返す
bool isOK(int index, long long key, vector<long long>&mae) {
	if (mae[index] >= key) return true;
	else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(long long key, vector<long long>&mae) {
	int left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
	int right = (int)mae.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

	/* どんな二分探索でもここの書き方を変えずにできる！ */
	while (right - left > 1) {
		int mid = left + (right - left) / 2;

		if (isOK(mid, key, mae)) right = mid;
		else left = mid;
	}

	/* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
	return right;
}

int n, m;
string s;

int main() {
	VLL squ(1);
	cin >> n;
	VLL a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	squ[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		int b=binary_search(a[i], squ);
		if (b == 0) {
			squ.insert(squ.begin(), a[i]);
		}
		else {
			squ[b - 1] = a[i];
		}
	}
	cout << squ.size() << endl;
}