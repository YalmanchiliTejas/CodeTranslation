#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	vector<int> v;
	int n;
	cin>>n;
	int count = 0;
	for(int i = 0;i < n; ++i)
	{
		int cur;
		cin>>cur;
		if(i < n - 2)
		{
			//printf("hi2\n");
			int cur2;
			cin>>cur2;
			v.push_back(cur);
			v.insert(v.begin(),cur2);
			++i;
		}
		else
		{
			//printf("hi1\n");
			v.push_back(cur);
			reverse(v.begin(),v.end());
		}
	}
	for(int i = 0;i < n; ++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}