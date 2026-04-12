#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <stack>
#include <climits>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef complex<double> P;
double EPS=1e-10;
double EQ(double a,double b){
	return abs(a-b)<EPS;
}
const double PI=atan(1.0)*4;
int N,M,L;
double xs[101];
double ys[101];
double as[101];
double rs[101];
P starP[101][101];
pair<P,P> starEdges[101][101];
struct edge{
	int to;
	double cost;
};
vector<edge>G[10001];
P roundPoint(P p,double a){
	return P(cos(a)*p.real()-sin(a)*p.imag(),sin(a)*p.real()+cos(a)*p.imag());
}
double dot(P a,P b){
	return (a.real()*b.real()+a.imag()*b.imag());
}
double cross(P a,P b){
	return (a.real()*b.imag()-a.imag()*b.real());
}
double distance_ls_p(P a,P b,P c){
	if(dot(b-a,c-a)<EPS)return abs(c-a);
	if(dot(a-b,c-b)<EPS)return abs(c-b);
	return abs(cross(b-a,c-a))/abs(b-a);
}
bool is_intersected_ls(P a1,P a2,P b1,P b2){
	if(abs(cross(a2-a1,b2-b1)<EPS))return false;
	return (cross(a2-a1,b1-a1)*cross(a2-a1,b2-a1)<EPS)&&
		(cross(b2-b1,a1-b1)*cross(b2-b1,a2-b1)<EPS);
}
typedef pair<double,pii> pdi;
double d[101][101];
const double INF=(1LL<<30);
double dijkstra(){
	priority_queue<pdi,vector<pdi>,greater<pdi> > pq;
	for(int i=0;i<101;i++)
		for(int j=0;j<101;j++)
			d[i][j]=INF;
	for(int i=0;i<5;i++){
		d[M][i]=0;
		pq.push(pdi(0,pii(M,i)));
	}
	while(pq.size()){
		pdi p=pq.top();pq.pop();
		double ccost=p.first;
		int cnode=p.second.first;
		int cedge=p.second.second;
		if(!EQ(d[cnode][cedge],ccost)&&d[cnode][cedge]<ccost)continue;
		for(int i=0;i<G[cnode*5+cedge].size();i++){
			edge &e=G[cnode*5+cedge][i];
			int tnode=(e.to)/5;
			int tedge=(e.to)%5;
			if(!EQ(d[tnode][tedge],ccost+e.cost)&&d[tnode][tedge]>ccost+e.cost){
				d[tnode][tedge]=ccost+e.cost;
				pq.push(pdi(d[tnode][tedge],pii(tnode,tedge)));
			}
		}
	}
	double res=INF;
	for(int i=0;i<5;i++){
		res=min(res,d[L][i]);
	}
	return res;
}

void solve(){
	while(cin>>N>>M>>L&&(N|M|L)){
		M--;L--;
		for(int i=0;i<10001;i++)
			G[i].clear();
		for(int i=0;i<N;i++)
			cin>>xs[i]>>ys[i]>>as[i]>>rs[i];
		for(int i=0;i<N;i++){
			for(int j=0;j<4;j++){
				edge e;
				e.cost=0;
				int from=i*5+j;
				int to=i*5+(j+1);
				e.to=to;
				G[from].push_back(e);
				e.to=from;
				G[to].push_back(e);
			}
		}
		for(int i=0;i<N;i++){
			P cp=P(xs[i],ys[i]);
			P up=P(xs[i],ys[i]+rs[i]);
			P base=P(0,rs[i]);
			P roundP=roundPoint(base,(1.0*as[i]/180)*PI);
			starP[i][0]=roundP+cp;
			for(int j=1;j<5;j++){
				roundP=roundPoint(roundP,(72.0/180)*PI);
				starP[i][j]=roundP+cp;
			}
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<5;j++){
				starEdges[i][j]=make_pair(starP[i][j],starP[i][(j+2)%5]);
			}
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<5;j++){
				for(int k=0;k<N;k++){
					if(i==k)continue;
					for(int l=0;l<5;l++){
						pair<P,P> &e1=starEdges[i][j];
						pair<P,P> &e2=starEdges[k][l];
						// クロスしてる場合
						if(is_intersected_ls(e1.first,e1.second,e2.first,e2.second)){
							int from=i*5+j;
							int to=k*5+l;
							edge e;
							e.cost=0;
							e.to=to;
							G[from].push_back(e);
							e.to=from;
							G[to].push_back(e);
						}
						//e1.first
						{
							double dist=distance_ls_p(e2.first,e2.second,e1.first);
							edge e;
							e.cost=dist;
							e.to=k*5+l;
							int from=i*5+j;
							int to=k*5+l;
							G[from].push_back(e);
							e.to=from;
							G[to].push_back(e);
						}
						// e1.second
						{
							double dist=distance_ls_p(e2.first,e2.second,e1.second);
							edge e;
							e.cost=dist;
							e.to=k*5+l;
							int from=i*5+j;
							int to=k*5+l;
							G[from].push_back(e);
							e.to=from;
							G[to].push_back(e);
						}
					}
				}
			}
		}
		double res=dijkstra();
		printf("%.10f\n",res);
	}
}

int main(){

	solve();

	return 0;
}