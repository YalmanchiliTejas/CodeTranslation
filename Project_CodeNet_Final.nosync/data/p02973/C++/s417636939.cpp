#include<bits/stdc++.h>
#define N 100005
#define Ms(a,b) memset(a,b,sizeof a);
#define db(x) cout<<#x<<"="<<x<<endl;
using namespace std;
int n,a[N],b[N];
int t[N],ans;
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+1+n);
	int len=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(b+1,b+1+len,a[i])-b;
		int l=1,r=i-1,res=0;
		while(l<=r){
			int mid=l+r>>1;
			if(t[mid]<a[i])r=mid-1;
			else l=mid+1,res=mid;
		}
		t[res+1]=a[i];
		ans=max(ans,res+1);
	}
	printf("%d\n",ans);
	return 0;
}
