#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long int llint;
#define pub push_back
#define mp make_pair
#define fir first
#define sec second
const llint big=((llint)(1<<30)<<30);
//赤が最大と最小両方持つパターンと
//赤が最小　青が最大で場合分け
int main(void){
	llint ans,rmin=big,rmax=0,bmin=big,bsmin=big,bmax=0,rsa;
	llint i,n,q,w;
	vector<pair<llint,llint>> ball;
	scanf("%lld",&n);
	for(i=0;i<n;i++){
		scanf("%lld %lld",&q,&w);
		if(q>w){ swap(q,w); }
		ball.pub(mp(q,w));
	}
	sort(ball.begin(),ball.end());
	//赤が最小　青が最大
	for(i=0;i<n;i++){
		rmin=min(rmin,ball[i].fir);
		rmax=max(rmax,ball[i].first);
		bmin=min(bmin,ball[i].sec);
		bmax=max(bmax,ball[i].sec);
	}
	ans=(rmax-rmin)*(bmax-bmin);
	//ここから赤が最大最小両方持つ
	rsa=(bmax-rmin);
	bmin=ball[0].first;
	bmax=ball[n-1].first;
	bsmin=big;
	for(i=0;i<n-1;i++){
		bmin=ball[i+1].first;
		bsmin=min(bsmin,ball[i].sec);
		bmax=max(bmax,ball[i].sec);
		ans=min(ans,rsa*(bmax-min(bmin,bsmin)));
	}
	printf("%lld\n",ans);
	return 0;
}