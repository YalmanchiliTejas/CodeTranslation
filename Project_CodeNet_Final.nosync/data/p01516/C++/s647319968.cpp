#include<iostream>
#include<cstdio>
#define _USE_MATH_DEFINES
#include<cmath>
#include<vector>
#include<map>
using namespace std;


#define INF 1e+10
#define EPS 1e-10
#define EQ(a,b) (abs(a-b)<EPS)

//誤差を考慮して足し算
double add(double a,double b){
	if(abs(a+b) < EPS*(abs(a)+abs(b)))return 0;
	return a+b;
}
struct P{//2次元ベクトル
	double x,y;
	P(){}
	P(double x,double y):x(x),y(y){}
	P operator + (P p){
		return P(add(x,p.x),add(y,p.y));
	}
	P operator - (P p){
		return P(add(x,-p.x),add(y,-p.y));
	}
	P operator * (double d){
		return P(x*d,y*d);
	}
	P operator / (double d){
		return P(x/d,y/d);
	}
	double dot(P p){//内積
		return add(x*p.x,y*p.y);
	}
	double det(P p){//外積
		return add(x*p.y,-y*p.x);
	}
	bool equal(P p){
		return (x-p.x)*(x-p.x)+(y-p.y)*(y-p.y) < EPS*EPS;
	}
};
//typedef pair<P,P> Line;

//線分p1-p2上に点qがあるか判定
bool on_seg(P p1,P p2,P q){
	return (p1-q).det(p2-q)==0 && (p1-q).dot(p2-q)<=0;
}
//直線p1-p2と直線q1-q2の交点
P intersection(P p1,P p2,P q1,P q2){
	return p1+(p2-p1)*( (q2-q1).det(q1-p1)/(q2-q1).det(p2-p1) );
}


//線分p1-p2と線分q1-q2が交差するか
bool intersecting(P p1,P p2,P q1,P q2){
	if(on_seg(p1,p2,q1)||on_seg(p1,p2,q2)||on_seg(q1,q2,p1)||on_seg(q1,q2,p2))return true;
	if((p1-p2).det(q1-q2)==0 )return false;//平行
	P a=intersection(p1,p2,q1,q2);
	return on_seg(p1,p2,a) && on_seg(q1,q2,a);
}
//原点中心回転
P rotate(P p,double rad){
	double s=sin(rad),c=cos(rad);
	return P(c*p.x-s*p.y, s*p.x+c*p.y);
}
//originを中心回転
P rotate(P p,double rad,P origin){
	return origin + rotate(p - origin,rad);
}
//二点間の距離
double dist(P p,P q){
	p = p-q;
	return sqrt(p.x*p.x+p.y*p.y);
}
//単位ベクトルに変換
P to_unit(P p){
	double d = sqrt(p.x*p.x+p.y*p.y);
	return p/d;
}
//円同士の交点を計算
pair<P,P> circle_intersection(double x1,double y1,double r1,double x2,double y2,double r2){
	double rad = atan2(y2-y1,x2-x1);
	x2 -= x1;
	y2 -= y1;
	P tmp = rotate(P(x2,y2),-rad);
	x2 = tmp.x;
	y2 = tmp.y;
	double x = (r1*r1-r2*r2+x2*x2)/(2*x2);
	if(abs(r1) < abs(x))return make_pair(P(0,0),P(0,0));//交点なし
	double y = sqrt(r1*r1-x*x);
	return make_pair( P(x1,y1)+rotate(P(x,y),rad) ,  P(x1,y1)+rotate(P(x,-y),rad) );
}
//線分と点の距離
double dist_lp(P p1,P p2,P q){
	double dx,dy;
	dx = p1.x-p2.x;
	dy = p1.y-p2.y;
	double d = min(dist(p1,q) ,dist(p2,q));
	pair<P,P> normal= make_pair(q+to_unit(P(-dy,dx))*d ,q+to_unit(P(dy,-dx))*d);//法線ベクトル
	if(intersecting(p1,p2,normal.first,normal.second)){
		return dist(q, intersection(p1,p2,normal.first,normal.second));
	}
	return d;
}
//線分同士の距離
double dist_ll(P p1,P p2,P q1,P q2){
	if(intersecting(p1,p2,q1,q2))return 0;
	return min( min(dist_lp(p1,p2,q1),dist_lp(p1,p2,q2))
		,min(dist_lp(q1,q2,p1),dist_lp(q1,q2,p2)) );
}
//ラジアンに変換
double radian(double angle){
	return angle/180.0*M_PI;
}

vector<pair<P,P> > create_star(double x,double y,double a,double r){
	vector<pair<P,P> > res;
	vector<P> p;
	for(int i=0;i<5;i++){
		double rad = radian(18+i*72);
		p.push_back( P(x,y) +rotate(P(r*cos(rad),r*sin(rad)) ,a) );
	}
	for(int i=0;i<5;i++){
		res.push_back( make_pair(p[i],p[(i+2)%5]) );
	}
	return res;
}
double dist_star(vector<pair<P,P> > &a,vector<pair<P,P> > &b){
	double res=INF;
	for(int i=0;i<a.size();i++){
		for(int j=0;j<b.size();j++){
			res = min(res, 
				dist_ll(a[i].first,a[i].second,b[j].first,b[j].second) );
		}
	}
	return res;
}
int main(){
	double d[100][100];
	vector<vector<pair<P,P> > > stars;
	int N,M,L;
	double x,y,a,r;
	while(cin>>N>>M>>L, N||M||L){
		M--;
		L--;
		stars.clear();
		for(int i=0;i<N;i++){
			cin>>x>>y>>a>>r;
			stars.push_back(create_star(x,y,radian(a),r));
		}
		for(int i=0;i<N;i++){
			for(int j=i;j<N;j++){
				d[i][j]=d[j][i] = dist_star(stars[i],stars[j]);
			}
		}
		for(int k=0;k<N;k++)
			for(int i=0;i<N;i++)
				for(int j=0;j<N;j++)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		printf("%.20f\n",d[M][L]);
	}
	return 0;
}