#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	for(int i = 0;i<n-1;i++)
	{
		if(s.substr(i,2)=="AC")
		{
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	return 0;
}