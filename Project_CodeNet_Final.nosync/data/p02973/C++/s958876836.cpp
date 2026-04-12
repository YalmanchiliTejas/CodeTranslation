#include<bits/stdc++.h>
#define debug(x) cerr<<"\tDEBUG: "<<#x<<" = "<<(x)<<endl
#define debug2(a,b) cerr<<#a<<"\t"<<#b<<" = "<<(b)<<endl
using namespace std;
const int maxn=2e5+100;
bool cur1;
int n,A[maxn];
int q,C[maxn];
struct BIT{
	int C[maxn];
	void add(int x,int d){
		while(x){
			C[x]=max(C[x],d);
			x&=x-1;
		}
	}
	int sum(int x){
		int res=0;
		while(x<=n){
			res=max(res,C[x]);
			x+=x&-x;
		}
		return res;
	}
}bit;
bool cur2;
int main(){
//	double sz=&cur1-&cur2;
//	cout<<sz/1024/1024<<endl;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		C[i]=A[i];
	}
	sort(C+1,C+1+n);
	q=unique(C+1,C+1+n)-C-1;
	for(int i=1;i<=n;i++)
		A[i]=lower_bound(C+1,C+1+q,A[i])-C;
	int ans=0;
	for(int i=1;i<=n;i++){
		int x=bit.sum(A[i])+1;
		ans=max(ans,x);
		bit.add(A[i],x);
	}
	cout<<ans<<endl;
	return 0;
}