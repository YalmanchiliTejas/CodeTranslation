#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,valmn[N],valmx[N];
struct item{int x,y;}A[N];
int cmp(const item&A,const item&B) {return A.x>B.x;}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&A[i].x,&A[i].y);
		if(A[i].y>A[i].x) swap(A[i].x,A[i].y);
	}
	sort(A+1,A+n+1,cmp);
	int mn=1e9,mx=0,fl=0;
	for(int i=1;i<=n;i++)
		mn=min(mn,A[i].y),mx=max(mx,A[i].y);
	ll Ans=1ll*(A[1].x-A[n].x)*(mx-mn);
	for(int i=2;i<=n;i++) if(mn==A[i].y) fl=1;
	if(!fl) return printf("%lld\n",Ans),0;
	valmn[0]=1e9;
	for(int i=1;i<=n;i++)
	{
		valmn[i]=min(valmn[i-1],A[i].y);
		valmx[i]=max(valmx[i-1],A[i].y);
		ll res=1ll*(A[1].x-mn)*
			(max(A[i].x,valmx[i-1])-min(A[n].x,valmn[i-1]));
		Ans=min(Ans,res);
	}
	cout<<Ans<<endl;
}
