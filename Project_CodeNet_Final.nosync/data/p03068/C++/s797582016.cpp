#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,k;
	string s;
	cin>>n>>s>>k;--k;
	for (int i = 0; i < n; ++i)
	{
		if (s.at(i)!=s.at(k))
		{
			s.at(i)='*';
		}
	}
	cout<<s<<endl;
	return 0;
}
