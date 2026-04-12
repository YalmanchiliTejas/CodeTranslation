#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
#define N 2000005
#define ll long long
#define db double
#define dbg1(x) cout<<#x<<"="<<x<<" "
#define dbg2(x) cout<<#x<<"="<<x<<"\n"
int n,A[N],id[N],ans[N];
bool cmp(int t1,int t2) {return A[t1]<A[t2];}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]),id[i]=i;
	sort(id+1,id+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(i<=n/2) ans[id[i]]=A[id[n/2+1]];
		else ans[id[i]]=A[id[n/2]];
	}
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}