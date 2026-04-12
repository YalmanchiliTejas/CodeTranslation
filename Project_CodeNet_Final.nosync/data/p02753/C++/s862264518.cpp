#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i,n) for (int i = 0; i < (n); i++)
#define ru(a,b) (((a)+((b)-1)) / (b))   //切り上げ(a/b)
#define dump(x)  cout << #x << " = " << (x) << endl;

int main()
{
	string s;
	cin >> s;

	if (s[0] == s[1] && s[0] == s[2] && s[1] == s[2])
		cout << "No" << endl;
	else
		cout << "Yes" << endl;



	return 0;
}

