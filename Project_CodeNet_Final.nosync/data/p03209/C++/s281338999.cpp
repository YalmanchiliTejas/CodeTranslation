#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) (a).begin(),(a).end()
#define SORT(a) sort(all(a))
#define rSORT(a, i) sort(all(a),(i))

using ll = long long;
constexpr ll INF = 10000000000;
constexpr ll MOD = 1000000007;
const int MAX_N = 110000; 
constexpr double EPS = 1E-11;

using namespace std;

//fixed << setprecision(10)


//レベルがnのバーガーの下からx枚に含まれるパティの数
//xの値に応じてレベルn-1のバーガーに関する問題にする
ll rec(int n, ll x) {
	if (n == 0)return 1;
	//レベルn - 1のバーガーの長さ
	ll len = (1LL << (n + 1)) - 3;
	//レベルn - 1のバーガーに含まれるパティ
	ll cnt = (1LL << n) - 1;

	if (x == 1)return 0;
	else if (x <= len + 1)return rec(n - 1, x - 1);
	else if (x == len + 2)return cnt + 1;
	else if (x <= (len + 1) * 2)return cnt + 1 + rec(n - 1, x - len - 2);
	else return cnt * 2 + 1;
}


int main() {
	int n; ll x;
	cin >> n >> x;
	cout << rec(n, x) << endl;
}