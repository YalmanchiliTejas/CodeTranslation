#include <iostream>
using namespace std;

void solve()
{
	int n, m;
	cin >> n >> m;
	
	if(n == m)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}