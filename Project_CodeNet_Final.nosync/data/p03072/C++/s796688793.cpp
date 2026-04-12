#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> vi;
	for(int i=0;i<n;i++)
	{
		int a;cin>>a;vi.push_back(a);
	}
	int sum = 1;
	for(int i=1;i<n;i++)
	{
		int k = vi[i];bool isok = true;
		for(int j=0;j<i;j++)
		{
			if(vi[j]>k)isok = false;
		}
		sum+=isok;
	}
	cout<<sum<<endl;
	return 0;
}