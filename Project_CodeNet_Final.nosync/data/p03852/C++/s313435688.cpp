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
	char c; cin >> c;
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
		cout << "vowel" << endl;
	}else{
		cout << "consonant" << endl;
	} // end if

	return 0;
}