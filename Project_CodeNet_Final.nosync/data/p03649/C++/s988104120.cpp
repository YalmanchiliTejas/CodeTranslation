#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define pr pair<int, int>
#define x first
#define y second
using namespace std;

template<typename T>
void read(T& n){
	char ch; int sign = 1;
	while (!isdigit(ch = getchar())) if (ch == '-') sign = -1;
	n = ch - '0';
	while (isdigit(ch = getchar())) n = n * 10 + ch - '0';
	n *= sign;
}
typedef long long ll;
const int INF = 1e9 + 7;
const int N = 122;
int n;
ll a[N];

int main(){
	read(n);
	rep(i, 1, n) read(a[i]);
	ll tag = 0;
	for (; ;){
		ll cnt = 0;
		rep(i, 1, n){
			ll cur = a[i] + tag;
			cnt += a[i] / n;
			rep(j, 1, n) if (i != j) a[j] += a[i] / n;
			a[i] = a[i] % n;
		}
		if (!cnt) break;
		tag += cnt;
	}
	printf("%lld\n", tag);
	return 0;
}