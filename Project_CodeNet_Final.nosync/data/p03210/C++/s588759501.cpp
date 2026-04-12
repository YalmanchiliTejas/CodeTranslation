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

	int X; cin >> X;

	cout << (X == 3 || X == 5 || X == 7 ? "YES" : "NO") << endl;
	
	return 0;
}