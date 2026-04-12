#include<bits/stdc++.h>
using namespace std;
int n,a[100050],b[100050];
bool cmp(int x,int y)
{
	return a[x]==a[y]?x>y:a[x]<a[y];
}
set<int>st;
set<int>::iterator it;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=i;
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int x=b[i];
		if(st.size())
		{
			it=st.lower_bound(x);
			if(it!=st.begin())
			{
				it--;
				st.erase(it);
			}
		}
		st.insert(x);
	}
	cout<<st.size();
}