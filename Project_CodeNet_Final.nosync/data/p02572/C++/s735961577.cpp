#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>
#include <iomanip>
#include <unordered_map>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>

#define MOD 1000000007
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
typedef long double ld;
const char sp = ' ';



using namespace boost::multiprecision;
using namespace std;

int main(void){
    ll N;
    cin>>N;
    ll x=0, xbar=0;
    ll A;
    rep(i, N){
        cin>>A;
        xbar+=A;
        x+=A*A;
        xbar%=MOD;
        x%=MOD;
    }
    //cout<<x<<sp<<xbar<<endl;
    ll val=(xbar*xbar%MOD-x)%MOD+MOD;
    val%=MOD;
    if(val%2==0) cout<<val/2<<endl;
    else cout<<(val+MOD)/2<<endl;
    
    return 0;


}
