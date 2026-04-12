#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void cldflm()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w" , stdout);
#endif
}

int main()
{

	cldflm();

	int t;
	cin >> t;

	if (t >= 30)
		cout << "Yes";
	else
		cout << "No";



	return 0;
}

