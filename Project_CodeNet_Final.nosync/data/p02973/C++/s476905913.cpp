#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<"### "<<x<<endl;
#define For(a,b,c) for(int a=b;a<=c;++a)
#define Dor(a,b,c) for(int a=b;a>=c;--a)
inline int read(){
    int x=0;char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x;
}
const int N=1e5+10;
int a[N],b[N],n,c[N];
void add(int x,int d){
	for(;x<N;x|=x+1)c[x]=max(c[x],d);
}
int sum(int x){
	int res=0;
	for(;x>=0;x=(x&(x+1))-1)res=max(c[x],res);
	return res;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	int num=unique(b+1,b+n+1)-b-1;
	
	for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+num+1,a[i])-b,a[i]=n-a[i]+1;
	
	int ans=0,ma=0,lst=0;
	for(int i=1;i<=n;i++){
		int all=sum(a[i]);
	//	cout<<i<<" "<<all<<endl;
		ans=max(ans,all+1);
		add(a[i],all+1);
	}
	cout<<ans;
}