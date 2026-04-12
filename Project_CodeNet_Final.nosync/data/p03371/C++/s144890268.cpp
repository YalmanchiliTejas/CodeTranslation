#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define VIN(v) for(auto&elem_: (v) )cin>>elem_
#define VOUT(v, sep) for(_loop_int idx=0; idx<(_loop_int)v.size(); idx++) {cout<<v[idx]; if(idx<(_loop_int)v.size()-1) cout<<sep;} cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG2(x,y) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(debugidx,v.size())cout<<" "<<v[debugidx];cout<<endl
#define DEBUG_ARR(v,n) cout<<#v<<":";REP(debugidx,n)cout<<" "<<v[debugidx];cout<<endl

const ll MOD = 1000000007ll;
const int IINF = numeric_limits<int>::max()/2-1;
const ll LINF = numeric_limits<ll>::max()/2-1;

template<class T> inline bool chmin(T& a, const T b) { if (a>b) { a=b; return true; } return false; }
template<class T> inline bool chmax(T& a, const T b) { if (a<b) { a=b; return true; } return false; }


int a,b,c,x,y;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>a>>b>>c>>x>>y;

    ll ans = 0;
    int price = 0;
    if(c*2 >= a+b){
        price = a+b;
    }else{
        price = c*2;
    }
    while(x>0 && y>0){
        ans += price;
        x--;
        y--;
    }
    //DEBUG(ans);

    //aのみ
    if(c*2 >= a){
        price = a;
    }else{
        price = c*2;
    }
    while(x>0){
        ans += price;
        x--;
    }

    //bのみ
    if(c*2 >= b){
        price = b;
    }else{
        price = c*2;
    }
    while(y>0){
        ans += price;
        y--;
    }
    cout << ans << endl;
    return 0;
}