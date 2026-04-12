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

	string S; cin >> S;

	bool ok = false;
	for (int i = 0; i < (int)S.length() - 1; ++i){
		string T = S.substr(i, 2);
		ok |= (T == "AC");
	} // end for

	cout << (ok ? "Yes" : "No") << endl;

	return 0;
}