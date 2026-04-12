#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, s, n) for (int i = (s); i < (n); i++)
#define RFOR(i, s, n) for (int i = (n)-1; i >= (s); i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define ALL(a) a.begin(),a.end()
#define IN(a,x,b) (a<=x && x<b)
//const long long MOD = 1e9+7, INF = 1e18;
template<class T>inline bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}

void warshall_floyd(int n,vector<vector<double>>&d){
  FOR(i,0,n)FOR(j,0,n)FOR(k,0,n){
    if(d[j][k]>d[j][i]+d[i][k])d[j][k]=d[j][i]+d[i][k];
  }
}

double EPS = 1e-6;
const double INF = 1LL<<60;  
const double PI = acos(-1.0);
double torad(int deg) {return (double)(deg) * PI / 180;}
double todeg(double ang) {return ang * 180 / PI;}

double add(double a,double b){
	if(abs(a+b)<EPS*(abs(a)+abs(b)))return 0;
	return a+b;
}

struct P{
	double x,y;
	P(){}
	P(double x,double y):x(x),y(y){}
	P operator +(P p){
		return P(add(x,p.x),add(y,p.y));
	}
	P operator -(P p){
		return P(add(x,-p.x),add(y,-p.y));
	}
	P operator *(double d){
		return P(x*d,y*d);
	}
	double dot(P p){//内積
		return add(x*p.x,y*p.y);
	}
	double det(P p){//外積
		return add(x*p.y,-y*p.x);
	}
};

//交差判定
bool on_seg(P p1,P p2,P q){
	return (p1-q).det(p2-q)==0&&(p1-q).dot(p2-q)<=0;
}

//交差座標
P intersection(P p1,P p2,P q1,P q2){
	return p1 + (p2-p1) * ((q2-q1).det(q1-p1)/(q2-q1).det(p2-p1));
}

//線分と線分の公差判定
bool crossLine(P A,P B,P C,P D){
	int flg = 0;
	if((A-B).det(C-D)==0){
		flg |= on_seg(A,B,C);
		flg |= on_seg(A,B,D);
		flg |= on_seg(C,D,A);
		flg |= on_seg(C,D,B);
	}else{
		P r = intersection(A,B,C,D);
		flg = on_seg(A,B,r) && on_seg(C,D,r);
	}
	return flg;
}

//点と線分の最も近い座標
P distanceLP(P A,P B,P p){
	P a,b;
	double r;
	a.x = B.x - A.x;
	a.y = B.y - A.y;
	b.x = p.x - A.x;
	b.y = p.y - A.y;
	r = (a.x*b.x + a.y*b.y) / (a.x*a.x + a.y*a.y);
	
	if( r<= 0 ){
		return A;
	}else if( r>=1 ){
		return B;
	}else{
		P result;
		result.x = A.x + r*a.x;
		result.y = A.y + r*a.y;
		return result;
	}
}

//二点間の距離
double distance(P A,P B){
	return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

//線分と線分の最短距離
double distanceLL(P A,P B,P C,P D){
	P a = distanceLP(C,D,A);
	P b = distanceLP(C,D,B);
	P c = distanceLP(A,B,C);
	P d = distanceLP(A,B,D);
	if(crossLine(A,B,C,D))return 0.0;
	return min({distance(C,c),distance(C,d),distance(A,b),distance(A,a)});
}

int N,M,R;

double solve(){
	vector<vector<P>>line(N,vector<P>(5));
	REP(i,N){
		double a,b,c,d;
		cin>>a>>b>>c>>d;
		REP(j,5){
			double kakudo = torad(90+c+j*72);
			line[i][j] = P(a+d*cos(kakudo),b+d*sin(kakudo));
		}
	}
	vector<vector<double>>d(N,vector<double>(N));
	REP(i,N){
		REP(j,N){
			double mi = INF;
			REP(k,5){
				REP(l,5){
					chmin(mi,distanceLL(line[i][k],line[i][(k+2)%5],line[j][l],line[j][(l+2)%5]));
				}
			}
			d[i][j] = mi;
		}
	}
	warshall_floyd(N,d);
	/*
	REP(i,N){
		REP(j,N){
			if(j)cout<<" ";
			cout<<d[i][j];
		}
		cout<<endl;
	}/*
	cout<<M<<" "<<R<<" "<<d[M-1][R-1]<<endl;*/
	return d[M-1][R-1];
}

signed main(){
	vector<double>ans;
	while(cin>>N>>M>>R,N||M||R)ans.push_back(solve());
	for(auto e:ans) cout << fixed << setprecision(20) << e << endl;
}
