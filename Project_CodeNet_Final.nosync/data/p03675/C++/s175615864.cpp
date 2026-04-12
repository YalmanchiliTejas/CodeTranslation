#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring> 
#include<cassert>
#include<cmath>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
using namespace std;
deque<int> d;
int a[200005];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
//	cout<<1;
	for(int i=0;i<n;i++)
	{
		if((i+n)%2==0) d.push_back(a[i]); else d.push_front(a[i]);
//		cout<<a[i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<d.front()<<" ";
		d.pop_front();
	}
	return 0;
}