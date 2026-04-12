#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-10
#define equals(a,b) (fabs( (a) - (b) )< EPS )
// c++ 11,14
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0

typedef struct point{
	double x,y;
	point(){};
	point(double x ,double y):x(x),y(y){};
	point operator + (point &p){ return point(x+p.x,y+p.y);	}
	point operator - (point &p){ return point(x-p.x,y-p.y);	}
	point operator * (point &p){ return point(x*p.x-y*p.y,x*p.y+y*p.x) ;}
	point operator * (double a){ return point(x*a,y*a);	}
	point operator / (double a){ return point(x/a,y/a);	}
	
	double abs() { return sqrt(norm()); }
	double norm() { return x*x+y*y; }
	void make(){ cin>>x>>y;}
	bool operator < (const point &p) const { return x!=p.x ? x<p.x : y<p.y; }
	bool operator == (const point &p) const { return fabs(x-p.x)<EPS && fabs(y-p.y)<EPS; }
}point;
double abs(point a){return a.abs();}
double norm(point a){return a.norm();}

typedef complex<double> C;
typedef struct { 
	point s,e;
	void make(){ s.make(); e.make();}
} line;

C convert(point a){ return C(a.x,a.y); }
point convert( C a){ return point(a.real(),a.imag() );}
double dot(point a,point b){ return a.x*b.x+a.y*b.y ; } //内積　a・b
double cross(point a,point b){ return a.x*b.y - a.y*b.x ; }//外積(z成分)　a×b
point vec(line l){return l.e-l.s;}
line make(point s,point e){
	line res; res.s=s; res.e=e;
	return res;
}
point make(){ 
	double x,y; cin>>x>>y;
       	return point(x,y);
}
line lmake(){
	point p0=make();
	point p1=make();
	return make(p0,p1);
}
//直交
bool isorthogonal(point a,point b){ return equals(dot(a,b), 0.0); }
bool isorthogonal(line l1,line l2){ return isorthogonal(vec(l1),vec(l2)); }
//平行
bool isparallel(point a,point b){ return equals(cross(a,b),0.0); }
bool isparallel(line l1,line l2){ return isparallel(vec(l1),vec(l2)); }
//射影
point project(line s,point p){
	point base = vec(s);
	double r=dot(p-s.s,base)/base.norm();
	base = base*r;
	return s.s+base;
}
//反射
point reflect(line l,point p){
	point tmp=project(l,p)-p;
	tmp= tmp*2.0;
	return p+tmp;

}
//交差判定

int ccw(point p0,point p1,point p2){
	point a = p1-p0;
	point b = p2-p0;
if(cross(a,b)>EPS) return 1;//counter_clockwise
if(cross(a,b)<-EPS) return -1;//clockwise
if(dot(a,b)<-EPS)return 2;//online_back
if(a.norm()<b.norm() ) return -2;//online_front
return 0;//on_segment
}
// line p1-p2 line p3-p4
bool intersect(point p1,point p2,point p3,point p4){
	return (ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0 && ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0 ); 
}
// line l1,l2
bool intersect(line l1,line l2){ return intersect(l1.s,l1.e,l2.s,l2.e); }


//距離
//point-point
double distance(point a,point b){ return abs(a-b); }
//point-line(直線）
double distance2(line l,point p){
	return abs(cross(vec(l),p-l.s)/abs(l.e-l.s));
}
//point-line(線分)
double distance(line l,point p){
	if( dot(vec(l),p-l.s) <0.0 ) return abs(p-l.s);
	if( dot(l.s-l.e,p-l.e) <0.0 ) return abs(p-l.e);
	return distance2(l,p);
}
//line-line
double distance(line l1,line l2){
	if(intersect(l1,l2))	return 0.0;
	return min(min(distance(l1,l2.s),distance(l1,l2.e) ), min(distance(l2,l1.s),distance(l2,l1.e) ) );
}

//交点
point crosspoint(line l1,line l2){
	point base = vec(l2);
	double d1 = abs(cross(base,l1.s-l2.s) );
	double d2 = abs(cross(base,l1.e-l2.s) );
	double t = d1/(d1+d2);
	point tmp = vec(l1)*t;
	return l1.s+tmp;
}
//面積
double area(vector<point> &p,int n){
	double ans=0.0;
	for(int i=0;i<n-2;i++){
	ans+=cross(p[i+2]-p[0],p[i+1]-p[0]);
	}
	return abs(ans)/2;
}
double area(vector<point> p){
	return area(p,p.size());
}
//内包
int contains(vector<point> &g,point p){
int n=g.size();
bool flag=false;
	for(int i=0;i<n;i++){
		point a=g[i]-p, b=g[(i+1)%n]-p;
		if(abs(cross(a,b) )<EPS && dot(a,b) <EPS)return 1;
		if(a.y>b.y) swap(a,b);
		if(a.y<EPS&&EPS<b.y&&cross(a,b)>EPS) flag=!flag;
	}
	return (flag? 2:0);
}
//凸包
vector<point> andrewscan(vector<point> &s){
	vector<point> u,l;
	if(s.size() <3) return s;
	sort(s.begin(),s.end());
	u.push_back(s[0]);
	u.push_back(s[1]);
	l.push_back(s[s.size()-1]);
	l.push_back(s[s.size()-2]);

	for(int i=2;i<s.size();i++){
			//凸包の辺上を含めない場合
		for(int n=u.size();n>=2&&ccw(u[n-2],u[n-1],s[i])!=CLOCKWISE;n--)
			//凸包の辺上を含める場合
		//for(int n=u.size();n>=2&&ccw(u[n-2],u[n-1],s[i])==COUNTER_CLOCKWISE;n--)
		{
			u.pop_back();
		}
		u.push_back(s[i]);
	}

	for(int i=s.size()-3;i>=0;i--){
			//凸包の辺上を含めない場合
		for(int n=l.size();n>=2&&ccw(l[n-2],l[n-1],s[i])!=CLOCKWISE;n--)
			//凸包の辺上を含める場合
		//for(int n=l.size();n>=2&&ccw(l[n-2],l[n-1],s[i])==COUNTER_CLOCKWISE;n--)
		{
			l.pop_back();
		}
		l.push_back(s[i]);
	}

	reverse(l.begin(),l.end());
	for(int i=u.size()-2;i>=1;i--)l.push_back(u[i]);
	return l;
}
//直径
double convex_diameter(vector<point> &g){
	int n=g.size();
	int is=0,js=0;
	for(int i=1;i<n;i++){
		if(g[is].y < g[i].y)is =i;
		if(g[i].y < g[js].y)js=i;
	}
	double maxd = abs((g[is]-g[js]));
	int i,mi,j,mj;
	i=mi=is;
	j=mj=js;
	do{
		if(cross(g[(i+1)%n]-g[i],g[(j+1)%n]-g[j])>=0)j=(j+1)%n;
		else i=(i+1)%n;
		if(abs(g[i]-g[j])>maxd){
			//cerr<<i<<' '<<j<<' '<<norm(g[i]-g[j])<<endl;
			maxd =abs(g[i]-g[j]);
			mi=i;mj=j;
		}
	}while(i!=is||j!=js);
	return maxd;
}

struct star{
	point p[5];
	line l[5];
	void make(){
	    	point pp;
		double a,r;
		pp.make();
		cin>>a>>r;
		for(int i=0;i<5;i++){
		    	double theta =   ( (a+90+72*i) /180.0) *M_PI  ;
			point add = point(r*cos(theta),r*sin(theta) );
			p[i] = pp + add;
		}
		for(int i=0;i<5;i++){
			l[i].s = p[i];
			l[i].e = p[(i+2)%5] ;
		}
	}
	
};
double distance(star s1,star s2){
	double res = 1e9;
	for(int i=0;i<5;i++){
		for(int j = 0;j<5;j++){
			res = min(res,distance(s1.l[i],s2.l[j]) );
		}
	}
	/*for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
		    	point dis = s1.p[i] - s2.p[j];
			res = min(res,dis.abs() );
		}
	}*/
	

	return res;
}

typedef pair<double,int> mp;
int main(){
	while(1){
		int n,m,l;
		cin>>n>>m>>l;
		if(n==0)break;
		m--,l--;
		vector<star> s(n);
		vector<vector<double> > g(n,vector<double>  (n,0.0) );
		vector<bool> used(n,false);
		for(int i=0;i<n;i++){
			s[i].make();
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
			    g[i][j] = distance(s[i],s[j]);
			}
		}
	/*	for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<g[i][j]<<' ';
			}
			cout<<endl;
		}*/
		priority_queue<mp,vector<mp>,greater<mp> > q;
		q.push(mp(0.0,m) );

		while(!q.empty()){
			mp now = q.top();
			q.pop();
			double nc = now.first;
			int nn = now.second;
			if(nn == l ) {
			    printf("%0.10lf\n",nc);
				break;
			}
			if(used[nn])continue;
			used[nn] = true;
			for(int i=0;i<n;i++){
				if(!used[i]){
					q.push(mp(nc+g[nn][i],i) );
				}
			}
		}
		
	}
	return 0;
}
