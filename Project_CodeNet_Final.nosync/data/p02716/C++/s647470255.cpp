// skip until line 65
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <istream>
#include <iterator>
#include <sstream>
#include <list>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
using namespace std;

#define BR "\n"
#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define ALL(cont) begin(cont),end(cont)
#define AS_MOD(a, b) ((((a) % (b) ) + (b)) % (b))
#define MO(a) AS_MOD(a,mod)
#define FEACH(it, cont) for(auto (it) = begin(cont); it!=end(cont);++it)
#define FEACHR(it, cont) for(auto (it) = rbegin(cont); it!=rend(cont);++it)
#define pb push_back
#define pob pop_back
#define fi first
#define se second
#define getll() ([](){ll s;scanf("%lld", &s);return s;})()
#define getld() ([](){ld s;scanf("%Lf", &s);return s;})()
#define prl(P) printf("%lld", P)
#define prd(P) printf("%.10Lf", P)
#define pr(P) printf(P)
#define MAX(V, T) V=max(V,T)
#define MIN(V, T) V=min(V,T)

#define DumpArray(cont, from, to) for(int __i=from;__i<to;++__i) {cout<<"(" <<__i<<": " << cont[__i]<<")";} cout<<endl;

/*
 * ***_bound(6)
 * 5 6 6 6 6 6 7 7 7
 *   ^lower    ^upper
 * void reverse(c.begin(), c.end())
 *
 * graph
 * seg tree
 * dp
 * brute force
 */
struct Comparator{
    int operator()(int l, int r) const {
        return r<l;
    }
};
struct Vec;
//set<int, Comparator> S;

// solution below
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
ll N;
vector<ll> A(2*100000+10);
map<ll,ll> MA[2*100000+10];
ll INF=(1000*1000*1000ll)*(1000*1000ll)*10;
ll do_dp(ll i, ll j) {
    if (j*2-1>N-i+1  )return -INF;
    if (N/2-j>(i-2+1)/2  )return -INF;
    if (i>=N+1 && j>0) return -INF;
    if (i>=N+1) return 0;
    if (j==0) return 0;
    if (MA[i].count(j)>0)return MA[i][j];
    return MA[i][j]=max(do_dp(i+2,j-1)+A[i-1],do_dp(i+1,j));
}
int main() {
    cout.precision(10);
    cout << fixed;
    cin >> N;
    REP(i,N)
        cin>>A[i];
    cout<<do_dp(1,N/2)<<endl;
}
