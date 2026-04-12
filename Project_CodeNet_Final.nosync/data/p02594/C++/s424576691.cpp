#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int MAX = 1e5 + 1;
ll a[MAX];

int main()
{
	IOS
	int t = 1;
	//cin >> t;
	while(t--)
	{
		int x;
		cin >> x;
		if(x >= 30) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
