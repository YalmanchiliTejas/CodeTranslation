#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int M=1e5+5;
int a[M];

vector<int> ans;

int main()
{
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	{
		int p=upper_bound(ans.begin(),ans.end(),a[i],greater<int>())-ans.begin();
		if(p==(int)ans.size())
			ans.push_back(a[i]);
		else
			ans[p]=a[i];
	}
	printf("%d\n",ans.size());
	return 0;
}