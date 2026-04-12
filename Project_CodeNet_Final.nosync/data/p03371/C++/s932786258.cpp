#include <bits/stdc++.h>
using namespace std;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

typedef long long LL;
const LL mod=1000000007;
#define MAX 10000
#define NIL -1
const double PI  = acos(-1.0);
const int INF = 1e9 + 7;
//-------------------------------------------


int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int a,b,c;
    cin >> a >> b>> c;

    int x,y;
    cin >> x >> y;

    int mini = min( x, y);

    int sum = 0;

    if( a + b > 2* c){
        sum = mini * 2 * c;

        if( x > y){
            cout << sum + (x - y )* min( a, 2 * c) << endl;
        }
        else if( x < y){
            cout << sum + (y - x )* min( b, 2 * c) << endl;
        }
        else{
            cout << sum << endl;
        }
    }

    else{

        cout << a * x +b * y << endl;
    }

    return 0;
}
