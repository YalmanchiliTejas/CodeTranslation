#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>
using namespace std;
int n,cnt,a[101010];
vector<int>b;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]*=-1;
	}
	for(int i=0;i<n;i++)
	{
		if(!b.size())
		{
			b.push_back(a[i]);
		}
		else
		{
			int id=upper_bound(b.begin(),b.end(),a[i])-b.begin();
			if(id==b.size())
			{
				b.push_back(a[i]);
			}
			else
			{
				b[id]=a[i];
			}
		}
	}
	cout<<b.size()<<endl;
	return 0;
}