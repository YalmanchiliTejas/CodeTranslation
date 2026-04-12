#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

struct Point{double x,y;};
struct Segment{Point p1,p2;};
double norm(Point p){
	return p.x*p.x+p.y*p.y;
}
bool operator==(Point a,Point b){
	return a.x==b.x&&a.y==b.y;
}
Point operator+(Point a,Point b){
	return (Point){a.x+b.x,a.y+b.y};
}
Point operator-(Point a,Point b){
	return (Point){a.x-b.x,a.y-b.y};
}
Point operator*(Point a,double k){
	return (Point){a.x*k,a.y*k};
}
bool operator<(Point a,Point b){
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}
double dot(Point a,Point b){
	return a.x*b.x+a.y*b.y;
}
double cross(Point a,Point b){
	return a.x*b.y-a.y*b.x;
}
Point project(Segment s,Point p){
	Point base=s.p2-s.p1;
	double r=dot(p-s.p1,base)/norm(base);
	return s.p1+base*r;
}
Point reflect(Segment s,Point p){
	return p+(project(s,p)-p)*2.0;
}
Point crossPoint(Segment s1,Segment s2){
	Point base=s2.p2-s2.p1;
	double d1=abs(cross(base,s1.p1-s2.p1));
	double d2=abs(cross(base,s1.p2-s2.p1));
	double t=d1/(d1+d2);
	return s1.p1+(s1.p2-s1.p1)*t;
}
typedef vector<Point>Polygon;

int COUNTER_CLOCKWISE=1;
int CLOCKWISE=-1;
int ONLINE_BACK=2;
int ONLINE_FRONT=-2;
int ON_SEGMENT=0;

const double EPS=1e-9;
int ccw(Point p0,Point p1,Point p2){
	Point a=p1-p0,b=p2-p0;
	if(cross(a,b)>EPS)return COUNTER_CLOCKWISE;
	if(cross(a,b)<-EPS)return CLOCKWISE;
	if(dot(a,b)<0)return ONLINE_BACK;
	if(norm(a)<norm(b))return ONLINE_FRONT;
	return ON_SEGMENT;
}

bool intersect(Point p1,Point p2,Point p3,Point p4){
	return (ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0&&ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0);
}
bool intersect(Segment s1,Segment s2){
	return intersect(s1.p1,s1.p2,s2.p1,s2.p2);
}

Polygon andrewScan(Polygon s){
	Polygon u,l;
	if(s.size()<3)return s;
	sort(s.begin(),s.end());
	u.push_back(s[0]);
	u.push_back(s[1]);

	l.push_back(s[s.size()-1]);
	l.push_back(s[s.size()-2]);

	for(int i=2;i<s.size();i++){
		for(int n=u.size();n>=2&&ccw(u[n-2],u[n-1],s[i])!=CLOCKWISE;n--){
			u.pop_back();
		}
		u.push_back(s[i]);
	}
	for(int i=s.size()-3;i>=0;i--){
		for(int n=l.size();n>=2&&ccw(l[n-2],l[n-1],s[i])!=CLOCKWISE;n--){
			l.pop_back();
		}
		l.push_back(s[i]);
	}
	reverse(l.begin(),l.end());
	for(int i=u.size()-2;i>=1;i--)l.push_back(u[i]);
	return l;
}

int main(){
	Point s,g;
	cin>>s.x>>s.y;
	cin>>g.x>>g.y;
	int n;cin>>n;
	Polygon p(n);
	rep(i,n){
		cin>>p[i].x>>p[i].y;
	}
	Segment s1={s,g};
	bool flag=true;
	rep(i,n){
		Point p1=p[i],p2=p[(i+1)%n];
		Segment s2={p1,p2};
		if(intersect(s1,s2)){
			flag=false;break;
		}
	}
	if(!flag){
		Polygon q=p;
		q.push_back(s);
		q.push_back(g);
		Polygon res=andrewScan(q);
	
		double sum=0,cnt=0;
		int b=0;
		rep(i,res.size()){
			Point p1=res[i],p2=res[(i+1)%res.size()];
			if(b==0&&(p1==s||p1==g))b=1;
			double dist=sqrt(norm(p2-p1));
			sum+=dist;
			if(b==1)cnt+=dist;
			if(b==1&&(p2==s||p2==g))b=2;
		}
		printf("%.7lf\n",min(cnt,sum-cnt));
		return 0;
	}
	vector<Point>vs;
	rep(i,p.size()){
		vs.push_back(p[i]);
		Point p1=p[i],p2=p[(i+1)%p.size()];
		Segment seg={p1,p2};
		auto g2=reflect(seg,g);
		Segment seg2={s,g2};
		if(intersect(seg,seg2)){
			vs.push_back(crossPoint(seg,seg2));
		}
	}
	double Min=INFINITY;
	for(auto r:vs){
		Segment s1={s,r},s2={r,g};
		Min=min(Min,sqrt(norm(s1.p2-s1.p1))+sqrt(norm(s2.p2-s2.p1)));
	}
	printf("%.7lf\n",Min);
}

