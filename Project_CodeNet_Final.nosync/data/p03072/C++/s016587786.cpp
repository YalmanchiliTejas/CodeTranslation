#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define putchar putchar_unlocked
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int kotae = 0;
	int N;
	cin >> N;
	int ima = 0;
	rep(i, N) {
		int h;
		cin >> h;
		if (h >= ima) kotae++;
		ima = max(ima, h);
	}
	co(kotae);

	Would you please return 0;
}