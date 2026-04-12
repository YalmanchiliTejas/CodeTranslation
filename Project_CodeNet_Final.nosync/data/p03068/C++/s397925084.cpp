#include <bits/stdc++.h>

using namespace std;

#define Rep(i,a,b)  for (int i=(a);i<(b);i++)
#define rep(i,n)    for (int i=0;i<(n);i++)
#define all(x)      (x).begin(), (x).end()

#define ll long long

int main()
{
	int n, k;
	string s;
	cin >> n;
	cin >> s;
	cin >> k;
	rep (i, s.length()) {
		if (s[i] != s[k-1])
			s[i] = '*';
	}
	cout << s << endl;
}

