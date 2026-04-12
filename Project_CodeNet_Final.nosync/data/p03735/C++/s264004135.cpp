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
	int Max=a[1].y,Min=a[1].x,_max=1,_min=1;
	for(int i=2;i<=n;i++) {
		if(a[i].x<=Min&&a[i].y>=Max){
			Min=a[i].x;Max=a[i].y;
			_max=i;_min=i;
		} else if(a[i].x<Min) {
			Min=a[i].x;
			_min=i;
		} else if(a[i].y>Max){
			Max=a[i].y;
			_max=i;
		}
	}
	int Rmax=Max,Bmin=Min,Rmin=a[_min].y,Bmax=a[_max].x;
	for(int i=1;i<=n;i++){
		Rmin=min(Rmin,a[i].y);
		Bmax=max(Bmax,a[i].x);
	}
	ll ans=(ll)(Rmax-Rmin)*(Bmax-Bmin);
	if(_max!=_min) {
		Bmax=Max;
		Bmin=Min;
		Rmax=max(a[n].x,a[1].y);
		int premin=a[1].y;
		Rmin=min(a[1].y,a[2].x);
		ll ans0=Rmax-Rmin;
		for(int i=2;i<n;i++) {
			Rmax=max(a[i].y,Rmax);
			Rmin=min(min(premin,a[i].y),a[i+1].x);
			premin=min(premin,a[i].y);
			if(Rmax-Rmin<ans0)ans0=Rmax-Rmin;
		}
		ans0*=Bmax-Bmin;
		ans=min(ans,ans0);
	}
	printf("%lld\n",ans);
	return 0;
}
