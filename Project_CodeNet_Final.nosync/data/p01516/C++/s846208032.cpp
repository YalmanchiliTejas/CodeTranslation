#include <bits/stdc++.h>

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> inline T sqr(T x) {return x*x;}

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;

#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define each(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define exist(s,e) ((s).find(e)!=(s).end())
#define range(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  range(i,0,n)
#define clr(a,b) memset((a), (b) ,sizeof(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;


const double eps = 1e-10;
const double pi  = acos(-1.0);
const ll INF =1LL << 62;
const int inf =1 << 30;


// ?????\??????????????´???????????
template<class T> bool operator==(T a, T b){return abs(a-b)< eps;}
template<class T> bool operator< (T a, T b){return a < b-eps;}
template<class T> bool operator<=(T a, T b){return a < b+eps;}
template<class T> int sig(T r) {return (r==0||r==-0) ? 0 : r > 0 ? 1 : -1;}
#define X real()
#define Y imag()
#define mp make_pair

typedef bool B;
typedef long double D;
typedef complex<D> P;
typedef vector<P> VP;
typedef pair <P,P> L;
typedef vector<L> VL;
typedef struct {P c;D r;} C;
typedef struct {P c;D a,b;} E; // ???????????§?????????????£°?????\??????
typedef vector <P> Pol;

// ??§????????????????????§?????????
inline B cmp_x(const P &a,const P &b){ return (abs(a.X-b.X)<eps ) ?  a.Y<b.Y : a.X<b.X;}  // base x
inline B cmp_y(const P &a,const P &b){ return (abs(a.Y-b.Y)<eps ) ?  a.X<b.X : a.Y<b.Y;}  // base y
inline B cmp_a(const P &a,const P &b){ return (abs(arg(a)-arg(b))<eps ) ?  norm(a) < norm(b) : arg(a)<arg(b);} // base arg


// ???????????¬?¬??????????
// verify
D ip(P a, P b) {return a.X * b.X + a.Y * b.Y;}
D ep(P a, P b) {return a.X * b.Y - a.Y * b.X;}
D sr(D a) {return sqrt(max(a, (D)0));}
P vec(L l){return l.second-l.first;}


// ??????
D toRagian(D degree){ return degree*pi/180.0;}
D ang (P p){return arg(p);}
D ang (P base, P a, P b) {return arg( (b - base) / (a - base) );} // base ????????¢???
P rot (P base, P a, D theta){return base+polar( abs(a-base), arg(a-base)+theta );}

// verify AOJ 2514
P proj(P b,P p){ return b*ip(b,p)/norm(b);} 
P proj(L l,P p){ return l.first+proj(vec(l),p-l.first);}
P refl(L l,P p){ return proj(l,p)*D(2.0)-p; }

// ccw 
enum CCW{FRONT = 1, RIGHT = 2, BACK = 4, LEFT = 8, MID = 16, ON=FRONT|BACK|MID };

inline int ccw(P base, P a, P b) {              //??????a?????¨??????b???????????±??´??§??¨?????????????????????
  a -= base; b -= base;
  if (ep(a, b) > eps)   	 return LEFT;    // counter clockwise
  if (ep(a, b) < -eps)      return RIGHT;   // clockwise
  if (ip(a, b) < -eps)      return BACK;    // b--base--a on line
  if (norm(a) < norm(b)) return FRONT;   // base--a--b on line
  						 return MID;      // base--b--a on line  a?????¨b????????±?£??????????????£?????????????
}

// ??±?£???? ??¶??´??±???
	// ???????????¨??¶??´??±?£???????????±¬
	// ???????????¨??±?£?????????????????±¬
	// ??¶??´??±?£??????¶??´??±?£???????????±¬
	

B iver(L a, L b) {return ip(vec(a),vec(b) )== 0.0;}
B ipar(L a, L b) {return ep(vec(a),vec(b) )== 0.0;}


// ????????????
P pLL(L a,L b){ return a.first+vec(a)*ep(vec(b),b.first-a.first)/ep(vec(b), vec(a));}


// ???????????¨??¶??´??±?£??????±?£??????¢??¢?¨???£??????????????????????????????

B iLL(L l1,L l2){ return !ipar(l1,l2);}
B eqL(L a, L b) {return !iLL(a, b) && ep(vec(a), b.first - a.first)==0;}
B iLS(L a, L b)  {return sig(ep(vec(a), b.first - a.first)) * sig(ep(vec(a), b.second - a.first)) <= 0;}
B iLSs(L a, L b) {return sig(ep(vec(a), b.first - a.first)) * sig(ep(vec(a), b.second - a.first)) <  0;}
B iSS(L a, L b) {
	int cwa = ccw(a.first,a.second, b.first) | ccw(a.first,a.second, b.second);
	int cwb = ccw(b.first,b.second, a.first) | ccw(b.first,b.second, a.second);
	return ((cwa | cwb) & MID) || ((cwa & cwb) == (LEFT | RIGHT));
}
B iSSs(L a, L b) {
	int cwa = ccw(a.first,a.second, b.first) | ccw(a.first,a.second, b.second);
	int cwb = ccw(b.first,b.second, a.first) | ccw(b.first,b.second, a.second);
	return (cwa & cwb) == (LEFT | RIGHT);
}

// ???????????¨??¶??´??±?£??????±?£??????¢??¢?¨???£?????????????±¬

D dLP(L l,P p){ return abs( ep(vec(l),p-l.first) )/abs(vec(l));}
D dSP(L s,P p){
	if (sig( ip( vec(s), p - s.first)) <= 0) return abs(p - s.first);
	if (sig( ip(-vec(s), p - s.second)) <= 0) return abs(p - s.second);
	return dLP(s,p);
}
D dLL(L a,L b){ return iLL(a,b) ? 0 : dLP(a,b.first);}
D dLS(L a,L b){ return iLS(a,b) ? 0 : min(dLP(a, b.first), dLP(a, b.second));}
D dSS(L a,L b){ return iSS(a,b) ? 0 : min( min(dSP(a,b.first),dSP(a,b.second)),min(dSP(b,a.first),dSP(b,a.second)));}


// ??????
// Verify AOJ 1183

enum RCC{A_IN_B=1,B_IN_A=2,A_ON_B=4,B_ON_A=8,ISC=16,ON_OUT=32,OUT=64,SAME=12,ONS=48 };


int rCC(C a,C b){
	D d=abs(a.c-b.c);
	int res=0;
	if(a.r+b.r< d) res|=OUT;
	if(a.r+b.r==d) res|=ON_OUT;
	if(abs(a.r-b.r) < d && d < a.r+b.r) res|=ISC;
	if(d==b.r-a.r) res|=A_ON_B;
	if(d< b.r-a.r) res|=A_IN_B;
	if(d==a.r-b.r) res|=B_ON_A;
	if(d< a.r-b.r) res|=B_IN_A;
	return res;
}

//2?????????????????????????????????
// Verify AOJ 1183

VP pCC(C a,C b){
	VP res;
	int rel=rCC(a,b);
	if(rel==SAME){   // Same
		res.pb(a.c+P(a.r,0));
		res.pb(a.c+P(-a.r,0));
		res.pb(a.c+P(0,a.r));
		res.pb(a.c+P(0,-a.r));
	}else if(rel==ISC){         // 2points
		D d = abs(b.c - a.c);
		D x = (d * d + a.r * a.r - b.r * b.r) / (2 * d);
		P e = (b.c - a.c) / abs(b.c - a.c), w = e * P(0, 1) * sqrt(max(a.r * a.r - x * x, (D)0));
		res.pb(a.c + e * x - w);
		res.pb(a.c + e * x + w);	
	}else if(rel&ONS){ // 1points
		D d = abs(b.c - a.c);
 		D x = (d * d + a.r * a.r - b.r * b.r) / (2 * d);
 		P e = (b.c - a.c) / abs(b.c - a.c);
  		res.pb(a.c + e * x);
	}
	return res;
}


VP pCL(C c, L l) {
	VP res;
	P h = proj(l, c.c);
	P e = vec(l) / abs(vec(l)) * sr(c.r * c.r - norm(h - c.c));
	res.pb(h - e);
	res.pb(h + e);
	return res;
}


// ??????????¬???\??±???
// Verify AOJ 2001

L tanC(C c,D t){
	P p=c.c+polar(c.r,t);
	P d=polar(c.r,t)*P(0,1);
	return L(p-d,p+d);
}


// ??????????????±?¨??£??£???±???
// Verify AOJ 2001

VL common_tan(C a,C b){
	VL res;
	D d=ang(b.c-a.c);
	D i=acos((a.r+b.r)/abs(b.c-a.c));
	D o=acos((a.r-b.r)/abs(b.c-a.c));
	int r=rCC(a,b);

	if(r==OUT){		//?????±?¨??£?????¬???\??±???
		res.pb(tanC(a,d+i));
		res.pb(tanC(a,d-i));
	}

	if(r>=ISC){		// ?????±?¨??£????????£???±???
		res.pb(tanC(a,d+o));
		res.pb(tanC(a,d-o));
	}

	if(r&ONS)		//?¬???\????????§???????????¨?????§????£???±???
		res.pb(tanC(a,d));

	if(r==SAME){
		rep(i,5)
			res.pb(tanC(a,i));
	}
	return res;
}


// ?????????

// ????????§????????¢

// ????????§????????¢?????????????????????????£?????(??????????????§????????¢??§??????)
//verify AOJ CGL_3-C
int in_polygon(Pol pol,P p){
    int n=pol.size();
    int res=0;
    rep(i,n){
        if(ccw(pol[i],pol[(i+1)%n],p)==MID)
            return 1;
        if ((pol[i].Y <= p.Y) && (pol[(i+1)%n].Y>p.Y)){
            D vt=(p.Y-pol[i].Y)/(pol[(i+1)%n].Y-pol[i].Y);
            D dx=pol[(i+1)%n].X-pol[i].X;
            if(p.X < pol[i].X + vt*dx)
                    res++;
        }else if ((pol[i].Y>p.Y)&&(pol[(i+1)%n].Y<=p.Y)){
            D vt=(p.Y - pol[i].Y)/(pol[(i+1)%n].Y-pol[i].Y);
            D dx=pol[(i+1)%n].X-pol[i].X;
            if(p.X <pol[i].X+vt*dx)
                res--;
        }
    }
    return res?2:0;
}


// ????????§????????¢?????????????????????????£?????(??????????????§????????¢??§??????)
// Verify AOJ 2514

bool in_polygon(Pol pol,L s){
	VP check;
	int n=pol.size();

	rep(i,n){
		L tar=L(pol[i],pol[(i+1)%n]);
		if(iSS(s,tar))
			check.pb(pLL(s,tar));
	}

	check.pb(s.first);
	check.pb(s.second);
	sort(check.begin(),check.end(),cmp_x);
	n=check.size();
	bool res=true;
	rep(i,n-1){
		P m=(check[i]+check[i+1])/P(2.0,0.0);
		if(!in_polygon(pol,m))
			res=false;
	}
	return res;
}


// Area
// Verify AOJ 1100
D area(Pol pol){
	int n=pol.size();
	D xx,yy,sum=0.0;
	rep(i,n){
		xx=pol[i%n].X-pol[(i+1)%n].X;
		yy=pol[i%n].Y+pol[(i+1)%n].Y;
		sum+=xx*yy;
	}
	return abs(sum/2.0);
}

// hough T
// ??§??¢????????????????????????



// Convex_hull
// Verify AOJ 0063
Pol convex_hull(Pol pol){
	int n=pol.size();
	sort(pol.begin(),pol.end(),cmp_x);
	Pol res(2*n);
	int k=0;
	
	// down
	rep(i,n){
		while( k>1 && ep(res[k-1]-res[k-2],pol[i]-res[k-1])<=0) k--;
		res[k++]=pol[i];
	}
	// up
	for(int i=n-2,t=k;i>=0;i--){
		while( k>t && ep(res[k-1]-res[k-2],pol[i]-res[k-1])<=0) k--;
		res[k++]=pol[i];
	}
	res.resize(k-1);
	return res;
}

/*

// now developing
vector<L> merge_L(vector<L>){

}



Pol normalize_polygon(Pol pol){
	int n=pol.size();
	rep(i,n){
		if(ccw(pol[i],pol[(i+2)%n],pol[(i+1)%n])==MID)
			// remove pol[(i+1)%n]
			n--;
	}
}
*/

typedef pair<P, pii> Star;
#define F first
#define S second

int main(void){
    for(int n, s, z; cin >> n >> s >> z, n;){
        s--, z--;

        vector<Star> stars(n);
        for(auto && ss : stars){
            int x, y;
            cin >> x >> y >> ss.S.F >> ss.S.S;
            ss.F = P(x, y);
        }

        vector<VP> p;
        for(auto && ss : stars){
            VP cur(5);

            D a = ss.S.F;
            int r = ss.S.S;
            P root(0, r);

            rep(i, 5){
                cur[i] = rot(P(0, 0), root, (a + 72 * i) / 180.0 * pi);

                cur[i] += ss.F;
            }

            p.pb(cur);
        }

        vector<vector<D>> minDist(n, vector<D>(n, inf));
        rep(i, n){
            rep(j, n){
                rep(ii, 5){
                    rep(jj, 5){
                        L li(p[i][ii], p[i][(ii + 2) % 5]);
                        L lj(p[j][jj], p[j][(jj + 2) % 5]);

                        minDist[i][j] = min(minDist[i][j], dSS(li, lj));
                    }
                }
            }
        }

        rep(k, n){
            rep(i, n){
                rep(j, n){
                    minDist[i][j] = min(minDist[i][j], minDist[i][k] + minDist[k][j]);
                }
            }
        }

        printf("%.15Lf\n", minDist[s][z]);
    }

	return 0;
}