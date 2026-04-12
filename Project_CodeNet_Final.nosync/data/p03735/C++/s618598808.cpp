#include<cstdio>
#include<algorithm>
int N;
struct item{int i,x;bool operator<(item&it){return x<it.x;}}a[400010];
int cnt[200010],c2;
void cmin(long long&a,long long b){b<a?a=b:1;}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%d",&a[i*2].x,&a[i*2+1].x);
		a[i*2].i=a[i*2+1].i=i;
	}
	std::sort(a,a+N*2);
	for(int i=0;i<N;i++)cnt[i]=2;
	c2=N;
	long long ans=1ll<<62;
	for(int i=0,j=0;i<N*2;i++){
		while(c2&&j<N*2)--cnt[a[j++].i]==1?--c2:1;
		if(!c2)cmin(ans,1ll*(a[N*2-1].x-a[0].x)*(a[j-1].x-a[i].x));
		if(++cnt[a[i].i]==2)++c2;
	}
	int l=0,r=N*2;
	for(int i=0;i<N;i++)cnt[i]=0;
	while(++cnt[a[l].i]<2)l++;
	for(int i=0;i<N;i++)cnt[i]=0;
	while(++cnt[a[r-1].i]<2)r--;
	cmin(ans,1ll*(a[r-1].x-a[0].x)*(a[N*2-1].x-a[l].x));
	printf("%lld\n",ans);
}