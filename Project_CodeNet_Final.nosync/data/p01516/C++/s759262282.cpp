#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
#define INF 1e8
#define EPS 1e-10
using namespace std;

struct edge{
	double cost;
	int t;
	edge(){}
	edge(int tt,double cc){
		t=tt;
		cost=cc;
	}
};

double add(double a,double b){
	if(fabs(a+b)<EPS*(fabs(a)+fabs(b)))return 0.0;
	return a+b;
}

struct P{
	double x,y;
	P(){}
	P(double xx,double yy){
		x=xx;
		y=yy;
	}
	P operator +(P p){
		return P(add(x,p.x),add(y,p.y));
	}
	P operator -(P p){
		return P(add(x,-p.x),add(y,-p.y));
	}
	P operator *(double d){
		return P(x*d,y*d);
	}
	P operator /(double d){
		return P(x/d,y/d);
	}
	double dot(P p){
		return add(x*p.x,y*p.y);
	}
	double cross(P p){
		return add(x*p.y,-y*p.x);
	}
};

bool on_seg(P p1,P p2,P q){
	return (p1-q).cross(p2-q)==0.0 && (p1-q).dot(p2-q)<=0;
}

P intersection(P p1,P p2,P q1,P q2){
	return p1+(p2-p1)*((q2-q1).cross(q1-p1)/(q2-q1).cross(p2-p1));
}

int n,S,T;
int x[101],y[101],a[101],r[101];
vector<edge> G[101];

double dist(P a,P b){
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

double check(P p1,P p2,P q1,P q2){
	if((p1-q1).dot(p2-q2)==0.0){
		if(on_seg(p1,p2,q1) || on_seg(p1,p2,q2) || on_seg(q1,q2,p1) || on_seg(q1,q2,p2))return 0.0;
	}else{
		P r=intersection(p1,p2,q1,q2);
		if(on_seg(p1,p2,r) && on_seg(q1,q2,r))return 0.0;
	}
	double res=INF;
	double d=(q1-p1).dot(p2-p1)/dist(p1,p2);
	if((q1-p1).dot(p2-p1)<=0.0){
		res=min(res,dist(p1,q1));
	}else if((q1-p1).dot(p2-p1)<(p2-p1).dot(p2-p1)){
		res=min(res,sqrt(pow(dist(p1,q1),2)-d*d));
	}else res=min(res,dist(p2,q1));

	d=(q2-p1).dot(p2-p1)/dist(p1,p2);
	if((q2-p1).dot(p2-p1)<=0.0){
		res=min(res,dist(p1,q2));
	}else if((q2-p1).dot(p2-p1)<(p2-p1).dot(p2-p1)){
		res=min(res,sqrt(pow(dist(p1,q2),2)-d*d));
	}else res=min(res,dist(p2,q2));

	swap(p1,q1);
	swap(p2,q2);

	d=(q1-p1).dot(p2-p1)/dist(p1,p2);
	if((q1-p1).dot(p2-p1)<=0.0){
		res=min(res,dist(p1,q1));
	}else if((q1-p1).dot(p2-p1)<(p2-p1).dot(p2-p1)){
		res=min(res,sqrt(pow(dist(p1,q1),2)-d*d));
	}else res=min(res,dist(p2,q1));

	d=(q2-p1).dot(p2-p1)/dist(p1,p2);
	if((q2-p1).dot(p2-p1)<=0.0){
		res=min(res,dist(p1,q2));
	}else if((q2-p1).dot(p2-p1)<(p2-p1).dot(p2-p1)){
		res=min(res,sqrt(pow(dist(p1,q2),2)-d*d));
	}else res=min(res,dist(p2,q2));
	return res;
}

struct data{
	int v;
	double cost;
	data(){}
	data(int vv,double cc){
		v=vv;
		cost=cc;
	}
	bool operator <(const data& d1)const{
		return cost>d1.cost;
	}
};

double dp[101];

double dijk(){
	priority_queue<data> que;
	for(int i=0;i<n;i++){
		dp[i]=INF;
	}
	que.push(data(S,0));
	dp[S]=0.0;
	while(que.size()){
		data q=que.top();
		que.pop();
		if(dp[q.v]<q.cost)continue;
		if(q.v==T)return q.cost;
		for(int i=0;i<G[q.v].size();i++){
			edge e=G[q.v][i];
			if(e.cost+dp[q.v]<dp[e.t]){
				dp[e.t]=dp[q.v]+e.cost;
				que.push(data(e.t,dp[e.t]));
			}
		}
	}
}

int main(void){
	while(1){
		scanf("%d %d %d",&n,&S,&T);
		if(n+S+T==0)break;
		for(int i=0;i<n;i++){
			G[i].clear();
		}
		S--;
		T--;
		for(int i=0;i<n;i++){
			scanf("%d %d %d %d",&x[i],&y[i],&a[i],&r[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<5;j++){
				P p1=P(x[i],y[i])+P((double)r[i]*cos((double)(a[i]+72.0*j+90.0)/180.0*M_PI),(double)r[i]*sin((double)(a[i]+72.0*j+90.0)/180.0*M_PI));
				P p2=P(x[i],y[i])+P((double)r[i]*cos((double)(a[i]+72.0*j+234.0)/180.0*M_PI),(double)r[i]*sin((double)(a[i]+72.0*j+234.0)/180.0*M_PI));
			}
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				double co=INF;
				for(int k=0;k<5;k++){
					for(int l=0;l<5;l++){
						P p1=P(x[i],y[i])+P((double)r[i]*cos((double)(a[i]+72.0*k+90.0)/180.0*M_PI),(double)r[i]*sin((double)(a[i]+72.0*k+90.0)/180.0*M_PI));
						P p2=P(x[i],y[i])+P((double)r[i]*cos((double)(a[i]+72.0*k+234.0)/180.0*M_PI),(double)r[i]*sin((double)(a[i]+72.0*k+234.0)/180.0*M_PI));
						P q1=P(x[j],y[j])+P((double)r[j]*cos((double)(a[j]+72.0*l+90.0)/180.0*M_PI),(double)r[j]*sin((double)(a[j]+72.0*l+90.0)/180.0*M_PI));
						P q2=P(x[j],y[j])+P((double)r[j]*cos((double)(a[j]+72.0*l+234.0)/180.0*M_PI),(double)r[j]*sin((double)(a[j]+72.0*l+234.0)/180.0*M_PI));
						co=min(co,check(p1,p2,q1,q2));
					}
				}
				G[i].push_back(edge(j,co));
				G[j].push_back(edge(i,co));
			}
		}
		printf("%.10f\n",dijk());
	}
	return 0;
}