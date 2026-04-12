#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	vector<int> d;
	cin >> n;
	for( int i = 0; i < n; i++ )
	{
		int tmp;
		cin >> tmp;
		d.push_back(tmp);
	}
	bool check = true;
	int ju = d[0];
	for( int i = 1; i < n - 1; i++ )
	{
		if( i * 10 <= ju )ju = max(ju, i * 10 + d[i]);
	}
	if( ju < ( n - 1 ) * 10 )check = false;
	reverse(d.begin(), d.end());
	ju = d[0];
	for( int i = 1; i < n - 1; i++ )
	{
		if( i * 10 <= ju )ju = max(ju, i * 10 + d[i]);
	}
	if( ju < ( n - 1 ) * 10 || !check )cout << "no" << endl;
	else cout << "yes" << endl;

	return 0;
}

