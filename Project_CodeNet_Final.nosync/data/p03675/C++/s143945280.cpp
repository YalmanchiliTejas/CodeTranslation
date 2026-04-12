#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<deque>
#define sqr(x) (x)*(x)
using namespace std;
int n,i,x;
deque<int> arr;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>x;
		if (i&1) arr.push_back(x); else arr.push_front(x);
	}
	for (i=1;i<=n;i++)
	{
		if (n&1)
		{
			cout<<arr.back()<<' ';
			arr.pop_back();
		}
		else
		{
			cout<<arr.front()<<' ';
			arr.pop_front();
		}
	}
	return 0;
}