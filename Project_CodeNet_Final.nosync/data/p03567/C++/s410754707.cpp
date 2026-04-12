// In the name of Allah

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define X first
#define Y second
#define mp make_pair
#define pb push_back

const ll MAX = 1e5 + 5, mod = 1e9 + 7, inf = 1e17 + 100;

ll n, m, seg[MAX * 4], carry[MAX * 4];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	string s;
	cin >> s;
	bool f=  0;
	for (int i = 0; i < s.size()-1; i++)
		if (s[i] == 'A' && s[i+1] == 'C')
			f = 1;
	if (f)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}