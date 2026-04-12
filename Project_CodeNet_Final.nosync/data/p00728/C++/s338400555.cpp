#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
	while (true) {
		int n; cin >> n;
		if (n == 0) break;
		int score[100];
		rep(i, n) {
			cin >> score[i];
		}
		sort(score, score + n);
		int sum = 0;
		rep(i, n - 2) {
			sum += score[i + 1];
		}
		cout << sum / (n - 2) << endl;
	}

    return 0;
}

