#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <stdio.h>
#include <list>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

int main()
{
	int  n; cin >> n;
	vector<int> a(n);
	rep(i,n)cin>>a[i];

	vector<int> ans;
	ans.push_back(a[0]);
	for(int i=1;i<n;++i)
	{
		int left = -1,right=ans.size();
		while(1)
		{
			ll mid = ((1LL)*left + (1LL)*right)/2;
			if(a[i]<=ans[mid])left=mid;
			else right = mid;
			if(right-left==1)
			{
				if(right==ans.size())
				{
					ans.push_back(a[i]);
				}
				else
				{
					ans[right]=a[i];
				}
				break;
			}
			
			
		}
		//rep(i,ans.size())cout<<ans[i]<<" ";cout<<endl;
	}
	
	cout<<ans.size()<<endl;

	return 0;
}