#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < 3; ++i)
		cnt += (s[i] == 'A' ? 1 : 0);
	cout << (cnt % 3 ? "Yes\n" : "No\n");
}
