#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,n) for(int i = (a); i < (n); ++i)
using namespace std;
typedef long long ll;

void Main()
{
	int N; cin >> N;
	vector<int> H(N);
	rep(i,N) cin >> H[i];
	int res = 0;
	rep(i,N) {
		rep(j,i) {
			if (H[j] > H[i]) {
				--res;
				break;
			}
		}
		++res;
	}
	cout << res << endl;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
}
