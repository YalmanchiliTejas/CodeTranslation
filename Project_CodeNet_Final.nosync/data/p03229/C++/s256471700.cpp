#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define REP(i, n, N) for(ll i=(n);i<(N);i++)
#define RREP(i, n, N) for(ll i=(N-1);i>=(n);i--)
#define CK(n, a, b) ((a)<=(n)&&(n)<(b))
#define ALL(v) (v).begin(), (v).end()
#define MCP(a, b) memcpy(b,a,sizeof(b))
#define p(s) cout<<(s)<<endl
#define p2(a, b) cout<<(a)<<" "<<(b)<<endl
typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

int N;
ll A[100010];

int main() {
    cin>>N;
    REP(i,0,N){
        cin>>A[i];
    }

    sort(A, A+N);

    vector<ll> conf;

    // 小,大,小,大,...
    if(N%2 == 0){
        REP(i,0,(N-2)/2) conf.push_back(-2);
        conf.push_back(-1);
        conf.push_back(1);
        REP(i,0,(N-2)/2) conf.push_back(2);
    }else{
        REP(i,0,(N-2)/2) conf.push_back(-2);
        conf.push_back(-1);
        conf.push_back(-1);
        REP(i,0,N/2) conf.push_back(2);

    }
    ll sum1 = 0;
    REP(i,0,N){
        sum1 += A[i]*conf[i];
    }

    conf.clear();

    // 大,小,大,小,...
    if(N%2 == 0){
        REP(i,0,(N-2)/2) conf.push_back(-2);
        conf.push_back(-1);
        conf.push_back(1);
        REP(i,0,(N-2)/2) conf.push_back(2);
    }else{
        REP(i,0,N/2) conf.push_back(-2);
        conf.push_back(1);
        conf.push_back(1);
        REP(i,0,(N-2)/2) conf.push_back(2);
    }
    ll sum2 = 0;
    REP(i,0,N){
        sum2 += A[i]*conf[i];
    }

    cout<<max(sum1, sum2)<<endl;

    return 0;
}
