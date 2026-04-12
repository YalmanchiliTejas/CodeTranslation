#include <iostream>
#include <ostream>
#include<cmath>
#include<cstdio>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
double x[101],y[101];
int a[101],r[101];
#define PI 3.14159265358979324

struct point{
	double x,y;
	point(double x,double y):x(x),y(y){}
	point operator-(point ano){
		return point(x-ano.x,y-ano.y);
	}
	double operator*(point ano){
		return x*ano.x+y*ano.y;
	}
	double abs(){
		return sqrt(x*x+y*y);
	}
	string to_str(){
		stringstream s;
		s<<"("<<x<<","<<y<<")";
		return s.str();
	}
};
double dist(point a,point b){
	return (a-b).abs();
}
struct line{
	point a,b;
	double A,B,C;
	line(point a,point b):a(a),b(b){
		A=(a.y-b.y);B=-(a.x-b.x);C=a.x*b.y-a.y*b.x;
	}
	point diff(){return b-a;}
	bool inc(double x,double y){
		return (a.x-x)*(b.x-x)<=0 && (a.y-y)*(b.y-y)<=0;
	}
	string to_str(){
		stringstream s;
		s<<a.to_str()<<"~";
		s<<b.to_str();
		return s.str();
	}
};
double dist_point_line(point x,line l){
	double xl1=(x-l.a)*l.diff();
	double xl2=(x-l.b)*l.diff();
	if(xl1*xl2>0){
		return min(dist(l.a,x),dist(l.b,x));
	}else{
		return abs(l.A*x.x+l.B*x.y+l.C)/sqrt(l.A*l.A+l.B*l.B);
	}
}
bool cross(line a,line b){
	double d=a.A*b.B-a.B*b.A;
	if(abs(d)<1e-8)return false;
	double x=-(b.B*a.C-a.B*b.C)/d;
	double y=-(a.A*b.C-b.A*a.C)/d;
	return a.inc(x,y)&&b.inc(x,y);

}
bool nonparalell(){return false;}
double dist_lines(line a,line b){
	//cross
	if(cross(a,b)){
		return 0;
	}
	double mind=10000000000;
	mind=min(mind,dist_point_line(a.a,b));
	mind=min(mind,dist_point_line(a.b,b));
	mind=min(mind,dist_point_line(b.a,a));
	mind=min(mind,dist_point_line(b.b,a));
	return mind;
}
class star{
public:
	double sx[5],sy[5];
	vector<line> l;
	int x,y,a,r;
	star(double X,double Y,int A,int R){
		x=X;y=Y;a=A;r=R;
		init();
	}
	void init(){
			for(int i=0;i<5;i++){
				sx[i]=(double)x-(double)r*sin(PI/180*(a+72*i));
				sy[i]=y+r*cos(PI/180*(a+72*i));
			}
			for(int i=0;i<5;i++){
				l.push_back(line(point(sx[i],sy[i]),point(sx[(i+2)%5],sy[(i+2)%5])));
			}
	}
	string to_str()const{
		stringstream s;
		s<<"[";
		for(int i=0;i<5;i++){
			s<<"(";
			s<<sx[i];
			s<<", ";
			s<<sy[i];
			s<<")";
		}
		s<<"]";
		return s.str();
	}
};
double dist(star a,star b){
	double s=1e+9;
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				s=min(s,dist_lines(a.l[i],b.l[j]));
			}
		}
		return s;
}

double mp[101][101];
int main(void){
	int n,m,l;
	vector<star> stars;
	while(cin>>n>>m>>l&&n){
		stars.clear();
		for(int i=0;i<n;i++){
			cin>>x[i]>>y[i]>>a[i]>>r[i];
			star st(x[i],y[i],a[i],r[i]);
			stars.push_back(st);
			//cout<<st.to_str()<<endl;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				double d=dist(stars[i],stars[j]);
				mp[i][j]=d;
				//cout<<"dist["<<i<<","<<j<<"]="<<d<<endl;
			}
		}
		for(int k=0;k<n;k++){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					double t=mp[i][k]+mp[k][j];
					if(t<mp[i][j]){
						mp[i][j]=t;
					}
				}
			}
		}
		printf("%.10f\n",mp[m-1][l-1]);
	}

}