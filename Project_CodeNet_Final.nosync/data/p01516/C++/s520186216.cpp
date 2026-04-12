#include <iostream>
#include <cmath>
#include <cstring>
#define EPS 1e-9
#define INF 1e10


using namespace std;

struct P{
	double x,y;
};
struct L{
	P p1,p2;
};
struct STAR{
	P p[5];
	L l[5];
};

STAR star[102];
double dp[102][102];

void setStar(STAR *star, int x, int y, int a, int r){
	int i;
	for(i=0;i<5;i++){
		star->p[i].x = x+r*cos((double)M_PI*(a+90+i*72)/180);
		star->p[i].y = y+r*sin((double)M_PI*(a+90+i*72)/180);
	}
	star->l[0].p1 = star->p[0];star->l[0].p2 = star->p[2];
	star->l[1].p1 = star->p[0];star->l[1].p2 = star->p[3];
	star->l[2].p1 = star->p[1];star->l[2].p2 = star->p[3];
	star->l[3].p1 = star->p[1];star->l[3].p2 = star->p[4];
	star->l[4].p1 = star->p[2];star->l[4].p2 = star->p[4];
}

int isIntersect(L l1, L l2){
if (((l1.p1.x - l1.p2.x) * (l2.p1.y - l1.p1.y) + (l1.p1.y - l1.p2.y) * (l1.p1.x - l2.p1.x)) * 
        ((l1.p1.x - l1.p2.x) * (l2.p2.y - l1.p1.y) + (l1.p1.y - l1.p2.y) * (l1.p1.x - l2.p2.x)) < 0){
        if (((l2.p1.x - l2.p2.x) * (l1.p1.y - l2.p1.y) + (l2.p1.y - l2.p2.y) * (l2.p1.x - l1.p1.x)) * 
            ((l2.p1.x - l2.p2.x) * (l1.p2.y - l2.p1.y) + (l2.p1.y - l2.p2.y) * (l2.p1.x - l1.p2.x)) < 0	){
            return 1;
        }
    }
    return 0;
}


double lpdistance(L l, P p){
    double dx = (l.p2.x - l.p1.x), dy = (l.p2.y - l.p1.y);
    double a = dx * dx + dy *dy, b = dx * (l.p1.x - p.x) + dy * (l.p1.y - p.y);
    double t = -b / a;
    if(t < 0) t = 0;
    if(t > 1) t = 1;
    double tx = l.p1.x + dx * t, ty = l.p1.y + dy * t;
    return sqrt((p.x - tx) * (p.x - tx) + (p.y - ty) * (p.y - ty));
}

double lldistance(L l1, L l2){
	if(isIntersect(l1, l2)) return 0;
	double     minl= lpdistance(l1, l2.p1);
	minl = min(minl, lpdistance(l1, l2.p2));
	minl = min(minl, lpdistance(l2, l1.p1));
	minl = min(minl, lpdistance(l2, l1.p2));
	return minl;
}

double ssdistance(STAR s1, STAR s2){
	double minl = INF;
	int i,j;
	for(i=0;i<5;i++)
	for(j=0;j<5;j++){
		minl = min(minl, lldistance(s1.l[i], s2.l[j]));
	}
	return minl;
}

main(){
	int n,m,l,i,j,k,x,y,a,r;
	while(cin>>n>>m>>l,n){
		memset(dp, 0, sizeof(dp));
		for(i=1;i<=n;i++){
			cin>>x>>y>>a>>r;
			setStar(star+i,x,y,a,r);
		}
		for(i=1;i<n;i++){
			dp[i][i]=0;
			for(j=i+1;j<=n;j++){
				dp[i][j]=dp[j][i]=ssdistance(star[i], star[j]);
			}
		}
		
		for(k=1;k<=n;k++){
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
		}
		printf("%.20lf\n", dp[m][l]);
	}
}