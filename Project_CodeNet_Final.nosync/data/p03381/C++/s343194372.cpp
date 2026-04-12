#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=2e5+5;
int a[N],q[N],ans[N];
bool a_xiao(int x,int y)
{
	return a[x]<a[y];
}

int main()
{
	int n;
	cin>>n;
	rep(i,1,n)scanf("%d",a+i);
	rep(i,1,n)q[i]=i;
	sort(q+1,q+n+1,a_xiao);
	rep(i,1,n)ans[q[i]]=a[q[n/2+(i<=n/2)]];
	rep(i,1,n)printf("%d\n",ans[i]);
}