#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <functional>
#include <complex>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl;
typedef double D;
typedef complex<D> P;
typedef pair<P,P> L;
D eps=1e-9,pi=3.14159265358979,inf=1e100;
P rot(int rad){
	double rd=(double)rad*pi/180;
	return P(cos(rd),sin(rd));
}
D dot(P a,P b){
	return real(conj(a)*b);
}
D cro(P a,P b){
	return imag(conj(a)*b);
}
int ccw(P a,P b,P c){
	if(cro(b-a,c-a)>eps) return 1;
	if(cro(b-a,c-a)<-eps) return -1;
	if(abs(abs(a-c)+abs(c-b)-abs(a-b))<eps) return 0;
	if(abs(abs(a-b)+abs(c-b)-abs(a-c))<eps) return -2;
	if(abs(abs(a-c)+abs(a-b)-abs(c-b))<eps) return 2;
}
P perp(L l,P p){
	D t=dot(p-l.fs,l.fs-l.sc)/norm(l.fs-l.sc);
	return l.fs+t*(l.fs-l.sc);
}
bool iSS(L a,L b){
	return ccw(a.fs,a.sc,b.fs)*ccw(a.fs,a.sc,b.sc)<=0 && ccw(b.fs,b.sc,a.fs)*ccw(b.fs,b.sc,a.sc)<=0;
}
bool iSP(L s,P p){
	return ccw(s.fs,s.sc,p)==0;
}
D dSP(L s,P p){
	P q=perp(s,p);
	return iSP(s,q) ? abs(p-q) : min(abs(p-s.fs),abs(p-s.sc));
}
D dSS(L a,L b){
	if(iSS(a,b)) return 0;
	return min(min(dSP(a,b.fs),dSP(a,b.sc)),min(dSP(b,a.fs),dSP(b,a.sc)));
}
vector<L> lines[100];
D d[100][100];
int main(){
	while(true){
		int n,m,l;
		cin>>n>>m>>l;
		if(n==0) break;
		rep(i,n){
			int x,y,a,r;
			cin>>x>>y>>a>>r;
			P p=P(0,r),o=P(x,y);
			P v=p*rot(a),nv;
			lines[i].clear();
			rep(j,5){
				nv=v*rot(144);
				lines[i].pb(L(o+v,o+nv));
				v=nv;
			}
		}
		rep(i,n) rep(j,n) if(i!=j){
			d[i][j]=inf;
			rep(k,5) rep(h,5) d[i][j]=min(d[i][j],dSS(lines[i][k],lines[j][h]));
		}
		rep(i,n) rep(j,n) rep(k,n) d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
		printf("%.9f\n",d[m-1][l-1]);
	}
}