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

	bool res = false;
	for (int i = 1; i < (int)S.length(); ++i){
		if (S[i-1] == 'A' && S[i] == 'C') res |= true;
	} // end for
	
	cout << (res ? "Yes" : "No") << endl;

	return 0;
}