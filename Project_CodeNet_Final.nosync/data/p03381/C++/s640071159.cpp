#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
int n;
vector<int>all;
int l;
int a[200010];
int gtid(int x)
{
	return lower_bound(all.begin(),all.end(),x)-all.begin()+1;
}
int sum[200010];
void add(int x,int v)
{
	for(int i=x;i<=l;i+=i&-i)sum[i]+=v; 
}
int query(int x)
{
	int res=0;
	for(int i=x;i;i-=i&-i)res+=sum[i];
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),all.push_back(a[i]);
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	l=all.size();
	for(int i=1;i<=n;i++)add(gtid(a[i]),1);
	for(int i=1;i<=n;i++)
	{
		int pos=gtid(a[i]);
		add(pos,-1);
		int le=0,ri=l+1;
		while(le+1<ri)
		{
			int mi=(le+ri)>>1;
			if(query(mi)>=n/2)ri=mi;else le=mi;
		}
		printf("%d\n",all[ri-1]);
		add(pos,1);
	}
	return 0;
} 