#include <bits/stdc++.h>
using namespace std;

int mp[10];

int main()
{
	mp[7] = mp[5] = mp[3] = 1;
	int x; cin >> x;
	puts(mp[x] ? "YES" : "NO");
}
