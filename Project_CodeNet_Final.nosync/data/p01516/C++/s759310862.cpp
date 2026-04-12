#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;   // 許容誤差。問題によって変える
const double pi=M_PI;
const double INFD=1e+9;
typedef complex<double> P; // Point
#define rep(i,n) for(int i=0;i<n;i++)
//点の座標は複素数で持つ
#define X real()
#define Y imag()
namespace std
{
bool operator<(const P p1, const P p2)
{
    return p1.X != p2.X ? p1.X < p2.X : p1.Y < p2.Y;
}
P operator+(const P p1, const P p2) { return P(p1.X + p2.X, p1.Y + p2.Y); }
P operator-(const P p1, const P p2) { return P(p1.X - p2.X, p1.Y - p2.Y); }
P operator*(const P p, double k) { return P(p.X * k, p.Y * k); }
P operator/(const P p, double k) { return P(p.X / k, p.Y / k); }
} 
//Segment/L
struct Segment
{
    P p1, p2;
    Segment() {}
    Segment(P p1, P p2) : p1(p1), p2(p2) {}
};
typedef Segment L;


//ノルム
//二点a,bを投げるとノルムの2乗(a1-b1)^2+(a2-b2)^2を返す
double norm(P &p1, P &p2)
{
    return (p1.X - p2.X) * (p1.X - p2.X) + (p1.Y - p2.Y) * (p1.Y - p2.Y);
}

//外積cross(a,b) = |a||b|sinθ=a1b2-a2b1
//二点a,bを投げると外積を返す
double cross(const P &a, const P &b)
{
    return (conj(a) * b).Y;
}

//内積dot(a,b) = |a||b|cosθ=a1b1+a2b2
//二点a,bを投げると内積を返す
double dot(const P &a, const P &b)
{
    return (conj(a) * b).X;
}

//射影
//L(又はS)と点Pを投げるとLへPを射影した座標を返す
//依存:dot,norm
P Projection(L l, P p)
{
    P base = l.p2 - l.p1;                        //始点
    double r = dot(p - l.p1, base) / norm(base); //線分に対する倍率の計算
    return l.p1 + base * r;
}

//鏡映
//L(又はS)と点Pを投げるとLを軸としたPの鏡像座標を返す
//依存:Projection,dot,norm
P Reflection(L l, P p)
{
    return p + (Projection(l, p) - p) * 2.0;
}

//位置関係判定(線分abを軸にcがどちら側にあるか)
//三点a,b,cを投げることで，a-bを軸として
//時計回りの場合:1,反時計回りの場合:-1,c-a-bの並び:2,a-b-cの並び:-2
//その他（重なってる等）:0
//依存:cross,dot,norm
int ccw(P a, P b, P c)
{
    b -= a;
    c -= a; //aからの向きを考える
    if (cross(b, c) > EPS)
        return +1; //clockwise
    else if (cross(b, c) < -EPS)
        return -1; //counter clockwise
    else if (dot(b, c) < -EPS)
        return +2; //c-a-b
    else if (norm(b) < norm(c))
        return -2; //a-b-c
    else
        return 0; //他
}

//Intersection Determination
//L,S,Pそれぞれのペアの交差判定，PPは直接比較できるのでないです
//それぞれのペアを投げる,引数の順番は関数名に記載
//交差又は含まれている場合true,そうでない場合falseを返す

//依存:cross
bool intersectLL(const L &l, const L &m)
{
    return abs(cross(l.p2 - l.p1, m.p2 - m.p1)) > EPS || // non-parallel
           abs(cross(l.p2 - l.p1, m.p1 - l.p1)) < EPS;   // same L
}
//依存:cross
bool intersectLS(const L &l, const L &s)
{
    return cross(l.p2 - l.p1, s.p1 - l.p1) * // s.p1 is left of l
               cross(l.p2 - l.p1, s.p2 - l.p1) <
           EPS; // s.p2 is right of l
}
//依存:cross
bool intersectLP(const L &l, const P &p)
{
    return abs(cross(l.p2 - p, l.p1 - p)) < EPS;
}
//依存:ccw,cross,dot,norm
bool intersectSS(const L &s, const L &t)
{
    return ccw(s.p1, s.p2, t.p1) * ccw(s.p1, s.p2, t.p2) <= 0 &&
           ccw(t.p1, t.p2, s.p1) * ccw(t.p1, t.p2, s.p2) <= 0;
}

bool intersectSP(const L &s, const P &p)
{
    return abs(s.p1 - p) + abs(s.p2 - p) - abs(s.p2 - s.p1) < EPS; // triangle inequality
}

//distance
//L,S,Pについてペアを投げるとその距離を計算
//引数の順番は関数名参照

//依存:Projection,dot,norm
double distanceLP(const L &l, const P &p)
{
    return abs(p - Projection(l, p));
}
//依存:intersectLL,cross,distanceLP,Projection,dot,norm
double distanceLL(const L &l, const L &m)
{
    return intersectLL(l, m) ? 0 : distanceLP(l, m.p1);
}
//依存:intersectLS,cross,distanceLP,Projection,dot,norm
double distanceLS(const L &l, const L &s)
{
    if (intersectLS(l, s))
        return 0;
    return min(distanceLP(l, s.p1), distanceLP(l, s.p2));
}
//依存:intersectSP,Projection,dot,norm
double distanceSP(const L &s, const P &p)
{
    const P r = Projection(s, p);
    if (intersectSP(s, r))
        return abs(r - p);
    return min(abs(s.p1 - p), abs(s.p2 - p));
}
//依存:intersectSS,ccw,cross,dot,norm,distanceSP,intersectSP,Projection
double distanceSS(const L &s, const L &t)
{
    if (intersectSS(s, t))
        return 0;
    return min(min(distanceSP(s, t.p1), distanceSP(s, t.p2)),
               min(distanceSP(t, s.p1), distanceSP(t, s.p2)));
}

double distancePP(const P &p1, const P &p2)
{
    return abs(p1 - p2);
}
//二本のL(又はS)を投げると交点座標を返す
//一致している場合は一本目のp1を返します
//交わっていない場合はfalseを返します
//依存:cross
P crosspoint(const L &l, const L &m)
{
    double A = cross(l.p2 - l.p1, m.p2 - m.p1);
    double B = cross(l.p2 - l.p1, l.p2 - m.p1);
    if (abs(A) < EPS && abs(B) < EPS)
        return l.p1; // same line
    if (abs(A) < EPS)
        assert(false); // !!!PRECONDITION NOT SATISFIED!!!
    return m.p1 + B / A * (m.p2 - m.p1);
}

P top[103][5]={};
L star[103][5]={};
double dist[103][103]={};

signed main(){
    int n,m,l;
    while(cin>>n>>m>>l and n){
        m--;l--;
        rep(i,n){
            double x,y,a,r;cin>>x>>y>>a>>r;
            rep(j,5){
                top[i][j]=P(x-r*sin(a*pi/180),y+r*cos(a*pi/180));
                a+=72;
            }
            star[i][0]=L(top[i][0],top[i][2]);
            star[i][1]=L(top[i][0],top[i][3]);
            star[i][2]=L(top[i][1],top[i][3]);
            star[i][3]=L(top[i][1],top[i][4]);
            star[i][4]=L(top[i][2],top[i][4]);
            //rep(s,5){
            //    cout<<"startop"<<top[i][s]<<endl;
            //}
        }
        rep(i,n){
            for(int j=i+1;j<n;j++){
                double tmp=INFD;
                rep(k,5)rep(l,5){
                    tmp=min(tmp,distanceSS(star[i][k],star[j][l]));
                    //cout<<"distanceSS"<<distanceSS(star[i][k],star[j][l])<<endl;
                }
                dist[i][j]=tmp;
                dist[j][i]=tmp;
            }
        }
        rep(k,n){
            rep(i,n){
                rep(j,n){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    dist[j][i]=dist[i][j];
                }
            }
        }
        printf("%.10lf\n",dist[m][l]);
    }
    return 0;
}
