#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	vector<string> a(n);
	for(int i = 0; i < n;i++)
		cin >> a[i] ;
	vector<vector<int> > b(n, vector<int>(m,0));
	vector<vector<int> > c(n, vector<int>(m,0));

	for(int i = 0;i < n;i++)
	{
		for(int j=0;j<m;++j)
		{
			if(a[i][j] == '.')
			{
				c[i][j] = 1,b[i][j] = 1;
			}
		}
	}
	set<int> delr, delc;
	for(int i = 0;i < n;i++)
	{
		for(int j =1;j<m;j++)
		{
			b[i][j] += b[i][j-1];
		}
		if(b[i][m-1] == m)
			delr.insert(i);
	}

	for(int j=0;j < m;++j)
	{
		for(int i = 1;i < n; ++i)
		{
			c[i][j] += c[i-1][j];
		}
		if(c[n-1][j] == n)
			delc.insert(j);
	}

	// for(auto r : delr)
	// 	cout << r << endl;
	// cout << "col : " << endl;
	// for(auto c : delc)
	// 	cout << c << endl;
	// cout << endl;
	for(int i = 0;i < n;i++)
	{
		int flag = 0;
		for(int j =0;j<m;j++)
		{
			if(delr.find(i) == delr.end() and delc.find(j) == delc.end())
				flag = 1,cout << a[i][j];
		}
		if(flag)cout << endl;
	}
	return 0;
}