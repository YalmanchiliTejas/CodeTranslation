#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



struct Point{
	Point(double arg_x,double arg_y){
		x = arg_x;
		y = arg_y;
	}

	Point(){
		x = y = 0.0;
	}

	Point operator + (Point p){ return Point(x+p.x,y+p.y); }
	Point operator - (Point p){ return Point(x-p.x,y-p.y);}
	Point operator * (double a){ return Point(a*x,a*y); }
	Point operator / (double a){ return Point(x/a,y/a); }

	double abs(){ return sqrt(norm()); }
	double norm(){ return x*x + y*y; }

	bool operator<(const Point &p) const{
		return x != p.x? x < p.x: y < p.y;
	}

	bool operator == (const Point &p) const{
		return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
	}

	double x,y;
};

typedef Point Vector;
typedef vector<Point> Polygon;

struct Line{
	Line(){

	}
	Line(Point a,Point b){
		p[0] = a;
		p[1] = b;
	}
	/*void outPut(){

		printf("(%.3lf,%.3lf)-(%.3lf,%.3lf)\n",p[0].x,p[0].y,p[1].x,p[1].y);
	}*/
	Point p[2];
};

int num_line;
Line line[105];


double norm(Vector a){
	return a.x*a.x+a.y*a.y;
}

double abs(Vector a){
	return sqrt(norm(a));
}

double cross(Vector a,Vector b){
    return a.x*b.y-a.y*b.x;
}

double dot(Vector a,Vector b){
    return a.x*b.x + a.y*b.y;
}

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -1;
static const int ON_SEGMENT = 0;

int ccw(Point p0,Point p1,Point p2){

	Vector a = p1 - p0;
	Vector b = p2 - p0;

	if(cross(a,b) > EPS)return COUNTER_CLOCKWISE;
	if(cross(a,b) < -EPS)return CLOCKWISE;
	if(dot(a,b) < -EPS)return ONLINE_BACK;
	if(a.norm() < b.norm())return ONLINE_FRONT;

	return ON_SEGMENT;
}

double calc_dist(Point A,Point B){

	return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}


double func_ConvexHull(Polygon V,Point start,Point goal){

	sort(V.begin(),V.end());

	vector<Point> UP,DOWN;

	UP.push_back(V[0]);
	DOWN.push_back(V[0]);

	for(int i = 1; i < V.size(); i++){

		while(UP.size() > 1 && ccw(UP[UP.size()-2],UP[UP.size()-1],V[i]) == COUNTER_CLOCKWISE){

			UP.pop_back();
		}

		while(DOWN.size() > 1 && ccw(DOWN[DOWN.size()-2],DOWN[DOWN.size()-1],V[i]) ==  CLOCKWISE){

			DOWN.pop_back();
		}

		UP.push_back(V[i]);
		DOWN.push_back(V[i]);
	}

	Polygon ret;

	for(int i = 0; i < UP.size(); i++){

		ret.push_back(UP[i]);
	}

	for(int i = DOWN.size()-1; i >= 0; i--){

		ret.push_back(DOWN[i]);
	}

	double sum = 0;
	for(int i = 0; i < ret.size(); i++){

		sum += calc_dist(ret[i],ret[(i+1)%ret.size()]);
	}

	bool FLG = false;
	double work = 0;

	for(int i = 0; i < ret.size(); i++){

		if((fabs(ret[i].x-start.x) < EPS && fabs(ret[i].y-start.y) < EPS) ||
				(fabs(ret[i].x-goal.x) < EPS && fabs(ret[i].y-goal.y) < EPS)){

			if(!FLG){

				FLG = true;
				work += calc_dist(ret[i],ret[(i+1)%ret.size()]);
			}else{

				break;
			}
		}else{

			if(FLG){

				work += calc_dist(ret[i],ret[(i+1)%ret.size()]);
			}
		}
	}

	return min(work,sum-work);
}

int func(double x1,double y1,double x2, double y2, double xp, double yp){
	double naiseki,norm1,norm2,gaiseki;
	norm1 = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	norm2 = sqrt((xp-x1)*(xp-x1)+(yp-y1)*(yp-y1));
	naiseki = (xp-x1)*(x2-x1)+(yp-y1)*(y2-y1);
	gaiseki = (x2-x1)*(yp-y1)-(xp-x1)*(y2-y1);
	if(gaiseki > EPS){
		return 1;
	}else if(gaiseki < -EPS){
		return -1;
	}
	if(naiseki < -EPS){
		return 2;
	}

	if(norm1 < norm2){
		return -2;
	}
	return 0;
}


//★★直線ではなく、線分の交差判定★★
bool is_Cross(Line a,Line b){

	if(func(a.p[0].x,a.p[0].y,a.p[1].x,a.p[1].y,b.p[0].x,b.p[0].y)*
			func(a.p[0].x,a.p[0].y,a.p[1].x,a.p[1].y,b.p[1].x,b.p[1].y) <= 0 &&
			func(b.p[0].x,b.p[0].y,b.p[1].x,b.p[1].y,a.p[0].x,a.p[0].y)*
			func(b.p[0].x,b.p[0].y,b.p[1].x,b.p[1].y,a.p[1].x,a.p[1].y) <= 0){
		return true;
	}
	return false;
}

double calc_slope(Line A){

	if(fabs(A.p[0].x-A.p[1].x) < EPS){

		return DBL_MAX;

	}else if(fabs(A.p[0].y-A.p[1].y) < EPS){

		return 0;

	}else{

		return (A.p[1].y-A.p[0].y)/(A.p[1].x-A.p[0].x);
	}
}


int main(){

	Point start,goal;

	scanf("%lf %lf",&start.x,&start.y);
	scanf("%lf %lf",&goal.x,&goal.y);

	Line base_line = Line(start,goal);

	int N;
	scanf("%d",&N);

	Polygon polygon;

	double x,y;

	for(int i = 0; i < N; i++){

		scanf("%lf %lf",&x,&y);
		polygon.push_back(Point(x,y));
	}

	num_line = 0;
	for(int i = 0; i < N; i++){

		line[num_line].p[0] = polygon[i];
		line[num_line++].p[1] = polygon[(i+1)%N];
	}

	bool FLG = false;

	for(int i = 0; i < num_line; i++){

		if(is_Cross(base_line,line[i])){
			FLG = true;
			break;
		}
	}

	if(FLG){

		//printf("交差する\n");

		polygon.push_back(start);
		polygon.push_back(goal);

		printf("%.10lf\n",func_ConvexHull(polygon,start,goal));

		return 0;
	}

	double ans = BIG_NUM;

	double X,Y;

	double L,R,mid1,mid2;
	double dist_1,dist_2;

	for(int i = 0; i < num_line; i++){

		double slope = calc_slope(line[i]);

		if(fabs(slope-DBL_MAX) < EPS){ //垂直

			X = line[i].p[0].x;

			L = min(line[i].p[0].y,line[i].p[1].y);
			R = max(line[i].p[0].y,line[i].p[1].y);

			for(int loop = 0; loop < 100; loop++){

				mid1 = (2.0*L+R)/3.0;
				mid2 = (L+2.0*R)/3.0;

				dist_1 = calc_dist(start,Point(X,mid1))+calc_dist(goal,Point(X,mid1));
				dist_2 = calc_dist(start,Point(X,mid2))+calc_dist(goal,Point(X,mid2));

				ans = min(ans,min(dist_1,dist_2));

				if(dist_1 <= dist_2){

					R = mid2;
				}else{

					L = mid1;
				}
			}

		}else if(fabs(slope) < EPS){ //水平

			Y = line[i].p[0].y;

			L = min(line[i].p[0].x,line[i].p[1].x);
			R = max(line[i].p[0].x,line[i].p[1].x);

			for(int loop = 0; loop < 100; loop++){

				mid1 = (2.0*L+R)/3.0;
				mid2 = (L+2.0*R)/3.0;

				dist_1 = calc_dist(start,Point(mid1,Y))+calc_dist(goal,Point(mid1,Y));
				dist_2 = calc_dist(start,Point(mid2,Y))+calc_dist(goal,Point(mid2,Y));

				ans = min(ans,min(dist_1,dist_2));

				if(dist_1 <= dist_2){

					R = mid2;
				}else{

					L = mid1;
				}
			}

		}else{

			double min_x = min(line[i].p[0].x,line[i].p[1].x);
			double L_y;
			if(line[i].p[0].x == min_x){

				L_y = line[i].p[0].y;

			}else{

				L_y = line[i].p[1].y;
			}

			L = min(line[i].p[0].x,line[i].p[1].x);
			R = max(line[i].p[0].x,line[i].p[1].x);

			for(int loop = 0; loop < 100; loop++){

				mid1 = (2.0*L+R)/3.0;
				mid2 = (L+2.0*R)/3.0;

				dist_1 = calc_dist(start,Point(mid1,L_y+slope*(mid1-min_x)))+calc_dist(goal,Point(mid1,L_y+slope*(mid1-min_x)));
				dist_2 = calc_dist(start,Point(mid2,L_y+slope*(mid2-min_x)))+calc_dist(goal,Point(mid2,L_y+slope*(mid2-min_x)));

				ans = min(ans,min(dist_1,dist_2));

				if(dist_1 <= dist_2){

					R = mid2;
				}else{

					L = mid1;
				}
			}
		}
	}

	printf("%.10lf\n",ans);

	return 0;
}

