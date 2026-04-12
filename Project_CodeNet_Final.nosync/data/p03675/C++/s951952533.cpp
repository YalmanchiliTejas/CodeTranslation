#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<ctime>
#include<queue>
#include<vector>
#define debug(x) cerr<<#x<<"="<<x<<endl
#define fgx cerr<<"-------------"<<endl
#define rint register int
typedef long long ll;
using namespace std;
deque<int> q;
int a[200001];
int main()
{   //freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	bool b=true;
	int n;
	cin>>n;
	for(rint i=1;i<=n;i++) cin>>a[i];
	for(rint i=1;i<=n;i++)
	{	if(b) q.push_front(a[i]),b=false;
		else q.push_back(a[i]),b=true;
	}
	if(n%2==1)
	{	while(!q.empty())
		{	cout<<q.front()<<" ";
			q.pop_front();
		}
	}
	else
	{	while(!q.empty())
		{ cout<<q.back()<<" ";
			q.pop_back();
		}
	}
	return 0;
}
