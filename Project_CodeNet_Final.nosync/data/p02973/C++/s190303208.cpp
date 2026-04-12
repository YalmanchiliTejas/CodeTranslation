#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;

//typedef
typedef long long LL;
typedef vector<LL> VL;
typedef vector<VL> VVL;
typedef vector<string> VS;
typedef pair<LL, LL> PLL;

//conversion
inline LL toLong(string s) {LL v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) LL((a).size())
#define EACH(i,c) for(auto i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define UNTIL(p) while(!(p))

//constant
const double EPS = 1e-5;
const double PI  = acos(-1.0);

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

#define PUTS(x) cout << (x) << endl;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    LL n;
    cin>>n;
    VL a(n);
    REP(i,n)cin>>a[i];
    multiset<LL> mset;
    LL max_val = a[0];
    mset.insert(a[0]);
    FOR(i,1,n){
        LL val = a[i];
        //if(val > max_val){
        //    mset.erase(mset.find(max_val));
        //    max_val = val;
        //    mset.insert(val);
        //    continue;
        //}
        auto lower = mset.lower_bound(val);
        //auto upper = mset.upper_bound(val);
        //if(upper == mset.end()){
        //    auto last = mset.end();
        //    mset.insert(val);
        //    continue;
        //}
        //else{
        //    mset.erase(itr);
        //    mset.insert(val);
        //}
        if(lower != mset.begin()){
            mset.erase(--lower);
        }
        mset.insert(val);
    }
    PUTS(mset.size());
}