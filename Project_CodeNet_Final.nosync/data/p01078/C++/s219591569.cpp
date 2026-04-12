#include <stdio.h>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <time.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


struct Point{
	void set(double arg_x,double arg_y){
		x = arg_x;
		y = arg_y;
	}
	double x,y;
};

Point point[1000000];

Point calc_Cross_Point(double x1,double x2,double x3,double x4,double y1,double y2,double y3,double y4){
	Point ret;
	ret.x = ((x2-x1)*(y3*(x4-x3)+x3*(y3-y4))-(x4-x3)*(y1*(x2-x1)+x1*(y1-y2)))/((y2-y1)*(x4-x3)-(y4-y3)*(x2-x1));
	if(x1 != x2){
		ret.y = ((y2-y1)*ret.x+y1*(x2-x1)+x1*(y1-y2))/(x2-x1);
	}else{
		ret.y = ((y4-y3)*ret.x+y3*(x4-x3)+x3*(y3-y4))/(x4-x3);
	}
	return ret;
}

double calc_S(Point a,Point b,Point c,Point d){
	return fabs((b.x*a.y - b.y*a.x)+(c.x*b.y - c.y*b.x)+(d.x*c.y - d.y*c.x)+(a.x*d.y - a.y*d.x))/2;
}


int main(){

	int N,K;
	scanf("%d %d",&N,&K);

	double base_degree = 360.0/(double)N;

	for(int i = 0; i < N; i++){
		point[i].x = cos((base_degree*i*M_PI)/180.0);
		point[i].y = sin((base_degree*i*M_PI)/180.0);
	}

	Point a,b,c,d,ret;
	a.set(point[0].x,point[0].y);

	ret = calc_Cross_Point(point[0].x,point[K].x,point[1].x,point[N+1-K].x,point[0].y,point[K].y,point[1].y,point[N+1-K].y);
	b.set(ret.x,ret.y);

	c.set(0,0);

	ret = calc_Cross_Point(point[0].x,point[N-K].x,point[N-1].x,point[(N-1+K)%N].x,point[0].y,point[N-K].y,point[N-1].y,point[(N-1+K)%N].y);
	d.set(ret.x,ret.y);

	printf("%.10lf\n",(double)N*calc_S(a,b,c,d));
}