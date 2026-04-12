#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int main()
{
	int n[100],sol[100],point[31];
	vector<int> s;
	int count=0,p,q;
	while(1)
	{
		scanf("%d,%d",&p,&q);
		if(p==0&&q==0)break;
		n[count]=p;
		sol[count]=q;
		s.pb(q);
		count++;
	}
	sort(s.begin(),s.end(),greater<int>());
	count=1;
	for(int i=0;i<s.size();i++)
	{
		if(i==s.size()-1)
		{
			point[s[i]]=count;
			continue;
		}
		if(s[i]==s[i+1])
		{
			point[s[i]]=count;
		}
		else
		{
			point[s[i]]=count;
			count++;
		}
	}
	while(cin>>p)
	{
		for(int i=0;i<101;i++)
		{
			if(n[i]==p)
			{
				q=i;
				break;
			}
		}
		cout << point[sol[q]] << endl;
	}
	return 0;
}