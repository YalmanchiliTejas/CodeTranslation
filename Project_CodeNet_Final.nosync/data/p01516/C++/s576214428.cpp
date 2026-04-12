#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

struct Info{
	double x,y;
};

struct Point{
	double x,y;
};

typedef Point Vector;

struct Segment{
	void set(double x1,double y1,double x2,double y2){
		p1.x = x1;
		p1.y = y1;
		p2.x = x2;
		p2.y = y2;
	}
	Point p1,p2;
};

typedef Segment Line;

int N,start,goal;
double dist[101][101];

Info info[101][5];
Segment segment[101][5];

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

double cross(Vector a,Vector b){
	return a.x*b.y-a.y*b.x;
}

double dot(Vector a,Vector b){
	return a.x*b.x + a.y*b.y;
}

Point calc_minus(Point a,Point b){
	Point ret;

	ret.x = a.x-b.x;
	ret.y = a.y-b.y;

	return ret;
}

double calc_len(Vector a){
	return sqrt(a.x*a.x+a.y*a.y);
}

double getDistanceLP(Line l,Point p){
	return fabs(cross(calc_minus(l.p2,l.p1),calc_minus(p,l.p1))/calc_len(calc_minus(l.p2,l.p1)));
}

double getDistanceSP(Segment s,Point p){
	if(dot(calc_minus(s.p2,s.p1),calc_minus(p,s.p1)) < 0.0)return calc_len(calc_minus(p,s.p1));
	if(dot(calc_minus(s.p1,s.p2),calc_minus(p,s.p2)) < 0.0)return calc_len(calc_minus(p,s.p2));
	return getDistanceLP(s,p);
}

double getDistance(Segment s1,Segment s2){
	return min(min(getDistanceSP(s1,s2.p1),getDistanceSP(s1,s2.p2)),
			min(getDistanceSP(s2,s1.p1),getDistanceSP(s2,s1.p2)));
}

Info roll(double x, double y, double rad)
{
	Info ret;

	ret.x = x*cos(rad)-y*sin(rad);
	ret.y = x*sin(rad)+y*cos(rad);

	return ret;
}

void func(){

	double x,y,degree,r;

	Info tmp;

	for(int i = 1; i <= N; i++){
		scanf("%lf %lf %lf %lf",&x,&y,&degree,&r);

		tmp = roll(0.0,r,degree*M_PI/180.0);

		info[i][0].x = x+tmp.x;
		info[i][0].y = y+tmp.y;

		for(int k = 1; k <= 4; k++){
			tmp = roll(info[i][k-1].x-x,info[i][k-1].y-y,(2.0*M_PI/5.0));
			info[i][k].x = x+tmp.x;
			info[i][k].y = y+tmp.y;
		}

		for(int k = 0; k < 5; k++){
			segment[i][k].set(info[i][k%5].x,info[i][k%5].y,info[i][(k+2)%5].x,info[i][(k+2)%5].y);
		}
	}

	double tmp_min,tmp_dist;

	bool isCross;

	for(int i = 1; i <= N; i++){
		for(int k = i; k <= N; k++){
			if(i != k){
				tmp_min = DBL_MAX;

				isCross = false;
				for(int a = 0; a < 5; a++){
					for(int b = 0; b < 5; b++){
						if(func(segment[i][a].p1.x,segment[i][a].p1.y,segment[i][a].p2.x,segment[i][a].p2.y,segment[k][b].p1.x,segment[k][b].p1.y)*
								func(segment[i][a].p1.x,segment[i][a].p1.y,segment[i][a].p2.x,segment[i][a].p2.y,segment[k][b].p2.x,segment[k][b].p2.y) <= 0 &&
										func(segment[k][b].p1.x,segment[k][b].p1.y,segment[k][b].p2.x,segment[k][b].p2.y,segment[i][a].p1.x,segment[i][a].p1.y)*
											func(segment[k][b].p1.x,segment[k][b].p1.y,segment[k][b].p2.x,segment[k][b].p2.y,segment[i][a].p2.x,segment[i][a].p2.y) <= 0){
							isCross = true;
							tmp_min = 0;
							break;
						}

					}
					if(isCross)	break;

				}

				if(!isCross){
					for(int a = 0; a < 5; a++){
						for(int b = 0; b < 5; b++){
							tmp_dist = getDistance(segment[i][a],segment[k][b]);
							tmp_min = min(tmp_min,tmp_dist);
						}
					}
				}

				dist[i][k] = tmp_min;
				dist[k][i] = tmp_min;

			}else{
				dist[i][k] = 0;
			}
		}
	}

	for(int mid = 1; mid <= N; mid++){
		for(int st = 1; st <= N; st++){
			for(int gl = 1; gl <= N; gl++){
				dist[st][gl] = min(dist[st][gl],dist[st][mid]+dist[mid][gl]);
			}
		}
	}

	printf("%.20lf\n",dist[start][goal]);

}

int main(){

	while(true){
		scanf("%d %d %d",&N,&start,&goal);
		if(N == 0 && start == 0 && goal == 0)break;

		func();
	}

	return 0;
}