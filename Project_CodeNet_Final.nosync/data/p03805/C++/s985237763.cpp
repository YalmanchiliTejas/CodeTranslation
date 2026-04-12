#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<ctime>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
ll inf = (1 << 29);
template<typename T>
T GCD(T a, T b) {
	while (max(a, b) % min(a, b)) {
		if (a > b)a = a % b;
		else b = b % a;
	}
	return min(a, b);
}
template<typename T>
T LCM(T a, T b) {
	return a / GCD(a, b)*b;
}
bool prime(ll a) {
	for (int i = 2; i <= sqrt(a); i++) {
		if (!(a%i))return false;
	}
	return true;
}
bool f[10][10];
int n, m, a, b, v[10], answer = 0;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)v[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		f[a][b] = true;
		f[b][a] = true;
	}
	do {
		bool ans = true;
		for (int i = 2; i <= n; i++) {
			if (!f[v[i - 1]][v[i]])ans = false;
		}
		if (ans)answer++;
	} while (next_permutation(v + 2, v + n + 1));
	cout << answer << endl;
	return 0;
}
