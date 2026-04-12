#include<bits/stdc++.h>

#define EQ(a,b) (abs((a)-(b)) < EPS)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define fs first
#define sc second
#define pb push_back
#define sz size()
#define all(a) (a).begin(),(a).end()

using namespace std;
typedef long double D;
typedef complex<D> P;
typedef pair<P,P> L;
typedef vector<D> P3;

const D EPS = 1e-8;
const D PI = acos(-1);

inline D dot(P x, P y){return real(conj(x)*y);}

inline D cross(P x, P y){return imag(conj(x)*y);}

inline D line_dis(L a,P x){return abs(cross(a.sc-a.fs,x-a.fs))/abs(a.sc-a.fs);}

inline P line_cp(L a,L b){
  return a.fs+(a.sc-a.fs)*cross(b.sc-b.fs,b.fs-a.fs)/cross(b.sc-b.fs,a.sc-a.fs);
}

inline D len3D(P3 a){
  return sqrt(a[0]*a[0] + a[1]*a[1] + a[2]*a[2]);
}

inline D cross3D(P3 a, P3 b){
  P3 res(3);
  res[0] = a[1]*b[2] - a[2]*b[1];
  res[1] = a[2]*b[0] - a[0]*b[2];
  res[2] = a[0]*b[1] - a[1]*b[0];
  return len3D(res);
}

int main(){
  P3 t(3),o(3),p(3);
  D R;

  rep(i,3)cin >> t[i];
  rep(i,3)cin >> o[i]; cin >> R;
  rep(i,3)cin >> p[i];

  rep(i,3)t[i] -= o[i], p[i] -= o[i], o[i] = 0;
  
  D H = len3D(t), disp = len3D(p);
  D cone_vol = PI/3*R*R*H;

  D px = cross3D(t,p)/H, py = sqrt(disp*disp - px*px);
  P pp(px,py), a(-R,0), b(R,0), h(0,H);
  P A = line_cp(L(a,h),L(b,pp)), B = line_cp(L(b,h),L(a,pp));
  P O = 0.5L*(A+B);
  D oR = R*(H-O.imag())/H;
  D oa = abs(A-B)/2, ob = sqrt(oR*oR - O.real()*O.real());
  D oh = line_dis(L(A,B),h);

  D up_cone = PI/3*oa*ob*oh, low_cone = cone_vol - up_cone;
  
  cout << fixed << setprecision(6) << up_cone << " " << low_cone << endl;
}