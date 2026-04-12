#include<iostream>
#include<algorithm>
using namespace std;
long long maxn1,maxn2,minn1=1e18,minn2=1e18,ans=1e18,minn3=1e18,maxn3;
struct node
{
	long long a,b;
	bool operator < (const node &s)const
	{
		return a<s.a;
	}
};
node tree[10000001];
int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		cin>>tree[i].a>>tree[i].b;
		if (tree[i].a>tree[i].b)
			swap(tree[i].a,tree[i].b);
		minn1=min(minn1,tree[i].a);
		maxn1=max(maxn1,tree[i].a);
		minn2=min(minn2,tree[i].b);
		maxn2=max(maxn2,tree[i].b);
	}
	ans=(maxn2-minn2)*(maxn1-minn1);
	sort(tree+1,tree+n+1); 
	for (int i=1;i<=n;++i)
	{
		minn3=min(minn3,tree[i].b);
		maxn3=max(maxn3,tree[i].b);
		if (i!=1&&i!=n)
			ans=min(ans,(max(maxn3,tree[n].a)-min(minn3,tree[i+1].a))*(maxn2-minn1));
	}
	cout<<ans<<endl;
	return 0;
}