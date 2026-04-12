#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define repp(i, m, n) for(int i = m, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
#define clr(ar, val) memset(ar, val, sizeof(ar))
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

int main(void)
{
	int n, k;
	char s[11], x;
	cin >> n;
	cin >> s;
	cin >> k;
	x = s[k - 1];
	rep(i, strlen(s)){
		if(s[i] != x) cout << '*';
		else cout << x;
	}
	cout << endl;
	return 0;
}