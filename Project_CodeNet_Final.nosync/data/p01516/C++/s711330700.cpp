#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<cmath>
#include<complex>
#define INF 10000000
#define pb push_back
using namespace std;
typedef complex<double> Point;
typedef pair<double,int> P;
const double PI=4*atan(1);
vector<vector<Point> > p;
int n,s,g;
double dot(Point a, Point b){
    return real(conj(a)*b);
}
double cross(Point a, Point b){
    return imag(conj(a)*b);
}
double dlp(Point a, Point b, Point c) {
  if(dot(b-a,c-a)<=0 )return abs(c-a);
  if(dot(a-b,c-b)<=0 )return abs(c-b);
  return abs(cross(b-a,c-a))/abs(b-a);
}
int iil(Point a1,Point a2,Point b1,Point b2){
	return (cross(a2-a1,b1-a1)*cross(a2-a1,b2-a1)<=0)&&(cross(b2-b1,a1-b1)*cross(b2-b1,a2-b1)<=0);
}
double dll(Point a1,Point a2,Point a3,Point a4){
    if(iil(a1,a2,a3,a4))
        return 0.0;
	return min(min(dlp(a1,a2,a3),dlp(a1,a2,a4)),min(dlp(a3,a4,a1),dlp(a3,a4,a2)));
}
double cal(int a,int b){
    double ret=INF;
    for(int i=0;i<5;i++)
        for(int j=2;j<4&&i+j<5;j++)
            for(int k=0;k<5;k++)
                for(int l=2;l<4&&k+l<5;l++)
                	ret=min(dll(p[a][i],p[a][i+j],p[b][k],p[b][k+l]),ret);
    return ret;
}
int main(){
    while(cin>>n>>s>>g,n||s||g){
        p.clear();
        p.resize(n);
        for(int i=0;i<n;i++){
            double x,y,a,r;
            cin>>x>>y>>a>>r;
            Point c=Point(x,y);
            for(int j=0;j<5;j++){
            	p[i].pb(c+polar(r,(a+72.0*j+90)*PI/180.0));
            }
        }
        vector<vector<double> > cost(n,vector<double>(n,INF));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
            	if(i==j){
            		cost[i][j]=0;
            		continue;
            	}
                cost[i][j]=cost[j][i]=cal(i,j);
            }
        }
    	for(int k=0;k<n;k++){
    		for(int i=0;i<n;i++){
    			for(int j=0;j<n;j++){
    				cost[i][j]=min(cost[i][k]+cost[k][j],cost[i][j]);
    			}
    		}
    	}
    	printf("%.8lf\n",cost[s-1][g-1]);
    }
    return 0;
}