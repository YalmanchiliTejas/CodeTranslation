#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <numeric>
using namespace std;
typedef long long int ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define EPS (1e-7)
#define INF (1e9 + 10)
#define PI (acos(-1))
#define MOD (1000000007)
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define ALL(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
template<class T>string watch(T &v){string res="";for(auto f:v)res+=(to_string(f)+" ");return res;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    ll N, K;cin >> N >> K;
    ll ans = 0;
    if (K==0) ans = N*N;
    else {
        REPS(i, N) {
            int group = (N+1)/i;
            if (i > K) ans += group*(i-K);
            int remain = (N+1)%i;
            if (remain-1 >= K) ans += remain-K;
        }
    }
    cout << ans << endl;
}