#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;

template<typename T>
void input(T &x) {
	x=0; T a=1;
	register char c=getchar();
	for(;c<48||c>57;c=getchar())
		if(c==45) a=-1;
	for(;c>=48&&c<=57;c=getchar())
		x=x*10+c-48;
	x*=a;
	return;
}

#define MAXN 200010

struct Ball {
	
	int x,y;

	void Input() {
		input(x),input(y);
		if(x>y) swap(x,y);
		return;
	}

	bool operator < (const Ball &q) const {
		if(x!=q.x) return x<q.x;
		return y<q.y;
	}

};

Ball a[MAXN];

#define inf 2147483647

int main() {
	int n;
	input(n);
	if(n==1) {
		puts("0");
//		fclose(stdin),fclose(stdout);
		return 0;
    }
	for(int i=1;i<=n;i++) a[i].Input();
	sort(a+1,a+n+1);
	int Max=0,Min=inf,pos_Max,pos_Min;
	for(int i=1;i<=n;i++) {
		if(a[i].x<Min) Min=a[pos_Min=i].x;
		if(a[i].y>Max) Max=a[pos_Max=i].y;
	}
	int Rmax=Max,Rmin=inf,Bmin=Min,Bmax=0;
	for(int i=1;i<=n;i++) {
		Rmin=min(Rmin,a[i].y),
		Bmax=max(Bmax,a[i].x);
	}
	ll ans=(ll)(Rmax-Rmin)*(Bmax-Bmin);
	if(pos_Max!=pos_Min) {
		Bmax=Max,Bmin=Min,Rmax=a[n].x;
		ll Ans=inf;
		for(int i=1,j=a[1].y;i<n;i++) {
			Rmax=max(a[i].y,Rmax),
			Rmin=min(min(j,a[i].y),a[i+1].x),
			j=min(j,a[i].y),
			Ans=min(Ans,1ll*Rmax-Rmin);
		}
		ans=min(ans,Ans*(Bmax-Bmin));
	}
	printf("%lld\n",ans);
	return 0;
}
