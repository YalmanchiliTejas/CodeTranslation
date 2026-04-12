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
const double PI  = acos(-1.0);

//-------------------------------------------

int n,k;
LL ans = 0;


int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>k;

    for(int b=1;b<=n;b++){
    ans+= (n/b)*max(0,b-k);
    ans+= max(0,n%b-k+1);
    }
    if(k==0)
    ans-=n;

    cout<<ans<<endl;

    return 0;
}