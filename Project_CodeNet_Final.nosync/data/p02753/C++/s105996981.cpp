#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i<(int)n; ++i)
#define rfor(i, n) for (int i = n-1; i>=0; --i)
#define rmod(x, y) (((x%y)+y)%y)
#define pb(x) push_back(x)
using namespace std;
typedef vector<int>::iterator vit;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef long long ll;
const int MAXN = 1024;

//OPERATORS


//GLOBALS


//FUNCTIONS


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s; cin >> s;
	bool bn = false;
	for(int i = 0; i < s.size()-1; i++){
		if(s[i+1] != s[i]) bn = true;
	}
	if(bn) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
