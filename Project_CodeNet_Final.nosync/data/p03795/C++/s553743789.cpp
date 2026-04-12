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

	int x = 800 * N;
	int y = 200 * (N / 15);

	cout << x - y << endl;

	return 0;
}