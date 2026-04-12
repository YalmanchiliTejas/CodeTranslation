#include<bits/stdc++.h>
using namespace std;
#define INF 1e10
#define EPS (1e-10)    //誤差
typedef complex<double> P;

struct star{
    P point[5];    
};

//実数同士の比較
bool EQ(double a, double b){
    return (abs(a - b) < EPS);
}

//二つのベクトルが等しいかどうか
bool EQV(P a, P b){
    return (EQ(a.real(), b.real()) && EQ(a.imag(), b.imag()));
}

//内積
double dot(P a, P b){
    return (a.real() * b.real() + a.imag() * b.imag());
}

//外積
double cross(P a, P b){
    return (a.real() * b.imag() - a.imag() * b.real());
}

// 点a,bを通る直線と点cとの距離
double distance_l_p(P a, P b, P c) {
  return abs(cross(b-a, c-a)) / abs(b-a);
}

// 点cが線分a,b上にあるかないか(3)
int is_point_on_line(P a, P b, P c) {
  // |a-c| + |c-b| <= |a-b| なら線分上
  return (abs(a-c) + abs(c-b) < abs(a-b) + EPS);
}

// 点a,bを端点とする線分と点cとの距離
double distance_ls_p(P a, P b, P c) {
  if ( dot(b-a, c-a) < EPS ) return abs(c-a);
  if ( dot(a-b, c-b) < EPS ) return abs(c-b);
  return abs(cross(b-a, c-a)) / abs(b-a);
}

//図を思い出す
int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if( cross(b,c) > EPS ) return +1;
    if( cross(b,c) < -EPS ) return -1;
    if( dot(b,c) < 0 ) return +2;
    if( norm(b) < norm(c) ) return -2;
    return 0;
}

// a1,a2を端点とする線分とb1,b2を端点とする線分の交差判定
int is_intersected_ls(P a1, P a2, P b1, P b2) {
  return ( ccw(a1,a2,b1) * ccw(a1,a2,b2) <= 0 ) &&
           ( ccw(b1,b2,a1) * ccw(b1,b2,a2) <= 0 );
}

// a1,a2を通る直線とb1,b2を通る直線の交点計算
P intersection_l(P a1, P a2, P b1, P b2) {
  P a = a2 - a1; P b = b2 - b1;
  return a1 + a * cross(b, b1-a1) / cross(b, a);
}



star ch(double x, double y, double a, double r){
    
    star res;
    res.point[0] = P(0, r);    
    
    //a度左に回転
    res.point[0] *= exp(P(0.0, a*M_PI/180.0));

    //P(cos(), sin())

    //72度回転　→　回収を五回繰り返す
    for(int i = 1; i < 5; i++){
        res.point[i] = res.point[i - 1] * exp(P(0.0, 2.0*M_PI/5.0));        
    }

    for(int i = 0; i < 5; i++){
        res.point[i] += P(x, y);        
    }

    return res;
}

double Distance(P p11, P p12, P p21, P p22){

    if(is_intersected_ls(p11, p12, p21, p22)) return 0.0;
    double ans = INF;
    ans = min(ans, distance_ls_p(p11, p12, p21));
    ans = min(ans, distance_ls_p(p11, p12, p22));
    ans = min(ans, distance_ls_p(p21, p22, p11));
    ans = min(ans, distance_ls_p(p21, p22, p12));
    return ans;
}

//星間の距離を返す
double make_dis(star st1, star st2){
    
    double res = INF;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            P p11, p12, p21, p22;
            p11 = st1.point[i];
            p12 = st1.point[(i + 2) % 5];

            p21= st2.point[j];
            p22 = st2.point[(j + 2) % 5];
            res = min(res, Distance(p11, p12, p21, p22));
        }
    }

    return res;
}

//幾何入門
int main(){
    
    while(1){

        int n, m, l; cin >> n >> m >> l;
        if(!n) break;
        m--;
        l--;

        //星の構造体
        vector<star> st(n);

        for(int i = 0; i < n; i++){
            double x, y, a, r; cin >> x >> y >> a >> r;
            //入力から星の構造体を返す
            st[i] = ch(x, y, a, r);
        }

        vector<vector<double> > dis(n, vector<double> (n, INF));

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(i == j) dis[i][j] = dis[j][i] = 0.0;
                else dis[i][j] = dis[j][i] = make_dis(st[i], st[j]);
            }
        }

        //ワーシャルフロイド
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        /*for(int i = 0; i < n; i++){
            cerr << "star " << i << endl;
            for(int j = 0; j < 5; j++){
                cerr << st[i].point[j].real() << " " << st[i].point[j].imag() << endl;
            }
        }*/

        printf("%.10f\n", dis[m][l]);

    }

    return 0;
}
