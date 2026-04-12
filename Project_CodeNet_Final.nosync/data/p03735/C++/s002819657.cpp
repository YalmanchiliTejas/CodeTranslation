#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 2e+5+5;

int n;
struct bag{
	int x,y;
}a[N];

bool cmp(bag a,bag b){return a.x<b.x;}

int main(){
	n=get();
	fo(i,1,n){
		a[i].x=get();a[i].y=get();
		if (a[i].x<a[i].y)swap(a[i].x,a[i].y);
	}
	sort(a+1,a+1+n,cmp);
	int Bmax=0,Bmin=1e+9,Rmax=0,Rmin=1e+9;
	fo(i,1,n){
		Bmax=max(Bmax,a[i].x),Bmin=min(Bmin,a[i].x);
		Rmax=max(Rmax,a[i].y),Rmin=min(Rmin,a[i].y);
	}
	LL ans=1ll*(Rmax-Rmin)*(Bmax-Bmin);
	int mx=max(Rmax,Bmax),mi=min(Rmin,Bmin);
	int Mx=0,Mi=1e+9;
	bool pdmax=0,pdmin=0;
	int wmax,wmin;
	fo(i,1,n)if (a[i].x==mx&&!pdmax){pdmax=1;wmax=i;Mx=max(Mx,a[i].y),Mi=min(Mi,a[i].y);}
	fd(i,n,1)if (a[i].y==mi&&!pdmin){pdmin=1;wmin=i;Mx=max(Mx,a[i].x),Mi=min(Mi,a[i].x);}
	if (wmax!=wmin){
		if (wmin>wmax)wmin--;
		fo(i,wmax,n-1)a[i]=a[i+1];
		n--;
		fo(i,wmin,n-1)a[i]=a[i+1];
		n--;
		fd(i,n,1){
			int tmpmx=Mx,tmpmi=Mi;
			tmpmx=max(tmpmx,a[i].x);
			tmpmi=min(tmpmi,a[i].x);
			if (i>1)tmpmi=min(tmpmi,a[1].x);
			LL tmp=1ll*(tmpmx-tmpmi)*(mx-mi);
			if (tmp<ans)ans=tmp;
			Mx=max(Mx,a[i].y);
			Mi=min(Mi,a[i].y);
		}
	}
	printf("%lld\n",ans);
	return 0;
}