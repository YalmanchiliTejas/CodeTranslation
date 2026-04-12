#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, i, j;
	int prev = -1;
	
	cin>>n>>m;
	
	for (i = 0; i < n; ++i)
	{
		string s;
		cin>>s;
		
		int beg = s.find('#'), fin = s.rfind('#');
		
		if (i && beg != prev)
		{
			cout<<"Impossible\n";
			return 0;
		}
		
		for (j = beg; j <= fin; ++j) if (s[j] != '#')
		{
			cout<<"Impossible\n";
			return 0;
		}
		
		prev = fin;
	}
	cout<<"Possible\n";
}
