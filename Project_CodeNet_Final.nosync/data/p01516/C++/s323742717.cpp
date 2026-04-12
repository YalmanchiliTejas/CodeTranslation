#include <algorithm> 
#include <bitset> 
#include <cctype> 
#include <complex> 
#include <cmath> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <deque> 
#include <functional> 
#include <iomanip> 
#include <iostream> 
#include <list> 
#include <map> 
#include <numeric> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <stack> 
#include <string> 
#include <utility> 
#include <vector> 
   
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
   
   
// テ、ツサツ・テ、ツクツ?テ・ツケツセテ、ツスツ陛ゥツδィテ・ツ按?
template<class T> bool operator==(T a, T b){return abs(a-b) < eps;} 
template<class T> int sig(T r) {return (r==0||r==-0) ? 0 : r > 0 ? 1 : -1;} 
#define x real() 
#define y imag() 
#define mp make_pair 
   
typedef bool B; 
typedef long double D; 
typedef complex<D> P; 
typedef pair <P,P> L; 
typedef struct {P c;D r;} C; 
typedef struct {P c;D a,b;} E; // テヲツ・ツ陛・ツ??」ツつづィツソツステ・ツ環?、ツコツ暗・ツョツ?
typedef vector <P>Pol; 
   
// テ」ツつステ」ツδシテ」ツδ暗」ツ?ョテ」ツつュテ」ツδシ 
B cmp_x(const P &a,const P &b){ return (abs(a.x-b.x)<eps ) ?  a.y<b.y : a.x<b.x;}  // base x 
B cmp_y(const P &a,const P &b){ return (abs(a.y-b.y)<eps ) ?  a.x<b.x : a.y<b.y;}  // base y 
B cmp_a(const P &a,const P &b){ return (abs(arg(a)-arg(b))<eps ) ?  norm(a) < norm(b) : arg(a)<arg(b);} // base arg 
   
   
// テ・ツ淞コテヲツ慊ャテヲツ督催、ツスツ?
// verify 
D ip(P a, P b) {return a.x * b.x + a.y * b.y;} 
D ep(P a, P b) {return a.x * b.y - a.y * b.x;} 
D sr(D a) {return sqrt(max(a, (D)0));} 
P vec(L l){return l.second-l.first;} 
   
   
// テァツつケ 
D ang (P p){return arg(p);} 
D ang (P base, P a, P b) {return arg( (b - base) / (a - base) );} // base テ、ツクツュテ・ツソツ?
P rot (P base, P a, D theta){return base+polar( abs(a-base), arg(a-base)+theta );} 
   
   
// ccw  
enum CCW{FRONT = 1, RIGHT = 2, BACK = 4, LEFT = 8, MID = 16, ON=FRONT|BACK|MID }; 
   
int ccw(P base, P a, P b) {              //テァツつケaテ」ツ?ィテァツつケbテ」ツ?古、ツクツ偲」ツ?暗」ツつ嘉」ツつ古」ツ?淌・ツ閉湘」ツ??」ツ?ォ 
  a -= base; b -= base; 
  if (ep(a, b) > 0)       return LEFT;    // counter clockwise 
  if (ep(a, b) < 0)      return RIGHT;   // clockwise 
  if (ip(a, b) < 0)      return BACK;    // b--base--a on line 
  if (norm(a) < norm(b)) return FRONT;   // base--a--b on line 
                         return MID;      // base--b--a on line  aテ」ツ?ィbテ」ツ?ョテァツキツ堙・ツ按?・ツ按、テ・ツョツ堙」ツ?ッテ」ツ?禿」ツつ?
} 
   
   
   
B iver(L a, L b) {return ip(vec(a),vec(b) )== 0.0;} 
B ipar(L a, L b) {return ep(vec(a),vec(b) )== 0.0;} 
   
   
// テ、ツコツ、テァツつケ 
P pLL(L a,L b){ return a.first+vec(a)*ep(vec(b),b.first-a.first)/ep(vec(b), vec(a));} 
   
   
// テァツつケテ」ツ?ィテァツ崢エテァツキツ堙」ツ?ィテァツキツ堙・ツ按?ゥツ鳴「テゥツ?」テ」ツ?ョテ、ツコツ、テ・ツキツョテ・ツ按、テ・ツョツ?
   
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
   
// テァツつケテ」ツ?ィテァツ崢エテァツキツ堙」ツ?ィテァツキツ堙・ツ按?ゥツ鳴「テゥツ?」テ」ツ?ョティツキツ敕ゥツ崢「 
   
D dLP(L l,P p){ return abs(ep(vec(l),p-l.first))/abs(vec(l));} 
D dSP(L s,P p){ 
    if (sig( ip( vec(s), p - s.first)) <= 0) return abs(p - s.first); 
    if (sig( ip(-vec(s), p - s.second)) <= 0) return abs(p - s.second); 
    return dLP(s,p); 
} 
D dLL(L a,L b){ return iLL(a,b) ? 0 : dLP(a,b.first);} 
D dLS(L a,L b){ return iLS(a,b) ? 0 : min(dLP(a, b.first), dLP(a, b.second));} 
D dSS(L a,L b){ return iSS(a,b) ? 0 : min( min(dSP(a,b.first),dSP(a,b.second)),min(dSP(b,a.first),dSP(b,a.second)));} 
   
 
int main(void){
    int n,s,t;
    while(cin >> n,n){

        cin >> s >> t;
		s--;t--;
        
		D graph[110][110];
		D X[110],Y[110],a[110],r[110];
		L star[110][5];

		rep(i,n) cin >> X[i] >> Y[i] >> a[i] >> r[i]; 
		rep(i,n) a[i]=a[i]/180.0*pi;
		
		rep(i,n)rep(j,5){
			P base=P(X[i],Y[i]);
			D theta=a[i]+j*(2.0/5.0*pi)+pi/2;
			P p1=base+P(r[i],0);
			p1=rot(base,p1,theta);
			theta=a[i]+(j+2)*(2.0/5.0*pi)+pi/2;
			P p2=base+P(r[i],0);
			p2=rot(base,p2,theta);
			//dump(base)dump(p1) dump(p2)
			star[i][j]=L(p1,p2);
		}
        
		rep(i,n)rep(j,n){
			D res = INF;
 			rep (k,5)rep(l,5){
    			res = min(res,dSS(star[i][k], star[j][l]));
			}
  			graph[i][j] = res;
		}

 		
        rep(k,n)rep(i,n)rep(j,n){
            graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
        }
 
        cout.precision(9);
        cout << fixed << graph[s][t] << endl;
    }
    return 0; 
}