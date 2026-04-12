#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	while(cin >> n,n!=0)
	{
		vector<int> s(n);
		for(int i=0;i<n;i++)
			cin >> s[i];
		sort(s.begin(),s.end());
		long long ans=0;
		for(int i=1;i<n-1;i++)
			ans+=s[i];
		ans/=(n-2);
		cout << ans << endl;
	}






}

