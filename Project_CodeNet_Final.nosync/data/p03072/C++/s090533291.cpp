#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

// mod
const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

// floating
typedef double Real;
const Real EPS = 1e-11;
#define EQ0(x) (abs(x)<EPS)
#define EQ(a,b) (abs(a-b)<EPS)
typedef complex<Real> P;

int N;
int H,W,h,w;

int main(){
    cin >> N;
    vector<int> H(N);

    REP(i, N) cin >> H.at(i);

    int nowTopHeight = H.at(0);
    int ans = 1;
    FOR(i, 1, N){
        if(nowTopHeight <= H.at(i)) {
            nowTopHeight = H.at(i);
            ans++;
        }
    }
    cout << ans;


//    REP(i,5)cin>>v[i];
//    cin>>k;
//    bool ok = true;
//    REP(i,5){
//        REP(j,i){
//            int d = v[i]-v[j];
//            if(d>k)ok=false;
//        }
//    }
//    puts(ok ? "Yay!" : ":(");
//    return 0;
}