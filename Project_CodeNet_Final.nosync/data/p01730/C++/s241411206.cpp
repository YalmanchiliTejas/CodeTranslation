#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
double dist(double a,double b,double c,double d){
	if(floor(b/10)==floor(d/10)) swap(a,b),swap(c,d);
	if(floor(a/10)==floor(c/10)){
		if(b==d) return abs(a-c);
		a-=floor(a/10)*10,c-=floor(c/10)*10;
		return abs(b-d)+min(a+c,20-a-c);
	}
	return abs(a-c)+abs(b-d);
}
double inf=1e9;
int main(){
	int N,x[10000],y[10000];
	cin>>N;
	rep(i,N) cin>>x[i]>>y[i];
	int a=inf,b=-inf,c=inf,d=-inf;
	rep(i,N){
		chmin(a,x[i]+y[i]);
		chmax(b,x[i]+y[i]);
		chmin(c,x[i]-y[i]);
		chmax(d,x[i]-y[i]);
	}
	int A=(a+b)/2,C=(c+d)/2;
	int X=(A+C)/2,Y=(A-C)/2;
	X-=X%10,Y-=Y%10;
	double ans=inf;
	for(int p=X-50;p<=X+50;p+=10){
		for(double q=Y-50;q<=Y+50;q+=0.5){
			double tmp=0;
			rep(i,N) chmax(tmp,dist(x[i],y[i],p,q));
			chmin(ans,tmp);
		}
	}
	for(int q=Y-50;q<=Y+50;q+=10){
		for(double p=X-50;p<=X+50;p+=0.5){
			double tmp=0;
			rep(i,N) chmax(tmp,dist(x[i],y[i],p,q));
			chmin(ans,tmp);
		}
	}
	printf("%.5f\n",ans);
}