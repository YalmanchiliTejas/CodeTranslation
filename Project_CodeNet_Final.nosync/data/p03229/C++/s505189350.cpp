#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=1e5;

int N,A[Maxn+5];
long long ans=0;

inline long long Abs(long long x) {
	if(x<0)return -x;
	return x;
}

int main() {
	#ifdef LOACL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&A[i]);
	sort(A+1,A+N+1);
	int l=A[1],r=A[N];
	ans=r-l;
	for(int i=2;i+i<=N;i++) {
		ans+=A[N-i+1]-l;
		ans+=r-A[i];
		l=A[i],r=A[N-i+1];
	}
	if(N&1)ans+=max(r-A[N/2+1],A[N/2+1]-l);
	printf("%lld\n",ans);
	return 0;
}