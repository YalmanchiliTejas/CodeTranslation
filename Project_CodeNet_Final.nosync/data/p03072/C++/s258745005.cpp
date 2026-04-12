#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N; cin >> N;
	vector<int> H(N, 0);
	rep (i, N){
		cin >> H[i];
	} // end rep

	int res = 1, currH = H[0];
	for (int i = 1; i < N; ++i){
		if (currH <= H[i]){
			++res;
			currH = H[i];
		} // end if
	} // end for

	cout << res << endl;

	return 0;
}