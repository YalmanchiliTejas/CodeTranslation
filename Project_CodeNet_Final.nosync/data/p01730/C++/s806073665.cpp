#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <numeric>
#include <queue>
#include <map>
#include <math.h>
using namespace std;
typedef long long int ll;

double dist(double a,double b,double c,double d){
	if(floor(b/10)==floor(d/10)){
		swap(a,b); swap(c,d);
	}
	if(floor(a/10)==floor(c/10)){
		if(b==d)return abs(a-c);
		a-=floor(a/10)*10,c-=floor(c/10)*10;
		return abs(b-d)+min(a+c,20-a-c);
	}
	return abs(a-c)+abs(b-d);
}

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> x(n),y(n);
	int xi=1e9,xa=-1e9;
	int yi=1e9,ya=-1e9;
	for(int i=0;i<n;i++){
		cin >> x[i] >> y[i];
		xi=min(xi,x[i]+y[i]);
		xa=max(xa,x[i]+y[i]);
		yi=min(yi,x[i]-y[i]);
		ya=max(ya,x[i]-y[i]);
	}
	double res=1e9;
	xi=(xi+xa)/2,yi=(yi+ya)/2;
	int xx=(xi+yi)/2,yy=(xi-yi)/2;
	xx-=xx%10,yy-=yy%10;
	for(int X=xx-50;X<=xx+50;X+=10){
		for(double Y=yy-50;Y<=yy+50;Y+=0.5){
			double d=0;
			for(int i=0;i<n;i++){
				d=max(d,dist(x[i],y[i],X,Y));
			}
			res=min(res,d);
		}
	}
	for(int Y=yy-30;Y<=yy+30;Y+=10){
		for(double X=xx-30;X<=xx+30;X+=0.5){
			double d=0;
			for(int i=0;i<n;i++){
				d=max(d,dist(x[i],y[i],X,Y));
			}
			res=min(res,d);
		}
	}
	printf("%.9f\n",res);
}

