#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

bool is_ok4(int n){
	return (n % 4 == 0);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int r, g, b; cin >> r >> g >> b;
	
	bool ok = is_ok4(10*g + b);

	cout << (ok ? "YES" : "NO") << endl;
	
	return 0;
}