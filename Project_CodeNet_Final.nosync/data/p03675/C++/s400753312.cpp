#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<cstdlib>
#include<deque>
#include<queue>
#include<bitset>
#include<functional>
#include<utility>
#include<list>
#include<iomanip>
#include<ctime>
#include<cassert>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
const int INF=1e9+1;
int a[200005];
vector<int> ans;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int i=n;
	while(i>=2)
	{
		ans.push_back(a[i]);
		i-=2;
	}
	ans.push_back(a[1]);
	if(n%2==0) i=3;
	else i=2;
	while(i<=n)
	{
		ans.push_back(a[i]);
		i+=2;
	}
	for(int j=0;j<ans.size();j++)
	{
		cout<<ans[j]<<" ";
	}
	cout<<endl;
	return 0;
}