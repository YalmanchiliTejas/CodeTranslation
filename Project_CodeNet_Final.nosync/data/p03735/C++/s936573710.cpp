#include<bits/stdc++.h>
#define fi first
#define se second

using namespace std;
typedef pair<int,int> pi;
typedef long long ll;

const int N=4e5+5;

int n,m,vi[N],cnt,mx,mn;
pi b[N];
ll ans=1e18;

int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<=n;i++)scanf("%d%d",&u,&v),b[++m]={u,i},b[++m]={v,i};
	sort(b+1,b+m+1);
	mn=b[1].fi,mx=b[m].fi;
	int l,r;
	for(l=r=1;l<=m;cnt-=--vi[b[l++].se]==0){
		while(r<=m&&cnt<n)cnt+=vi[b[r++].se]++==0;
		if(cnt!=n)break;
		if(l!=1&&r!=m+1)ans=min(ans,(ll)(b[r-1].fi-b[l].fi)*(mx-mn));
	}
	for(int i=1;i<=n;i++)vi[i]=0;cnt=0;
	for(l=1;cnt<n;cnt+=vi[b[l++].se]++==0);l--;
	for(int i=1;i<=n;i++)vi[i]=0;cnt=0;
	for(r=m;cnt<n;cnt+=vi[b[r--].se]++==0);r++;
	ans=min(ans,(ll)(b[l].fi-mn)*(mx-b[r].fi));
	printf("%lld\n",ans);
	return 0;
}