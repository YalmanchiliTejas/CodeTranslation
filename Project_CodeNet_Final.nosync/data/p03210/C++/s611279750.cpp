#include "bits/stdc++.h"

#define REP(i, n, N) for(ll i=(n); i<(N); i++)
#define RREP(i, n, N) for(ll i=(N-1); i>=n; i--)
#define CK(n, a, b) ((a)<=(n)&&(n)<(b))
#define ALL(v) (v).begin(),(v).end()
#define MCP(a, b) memcpy(b,a,sizeof(b))
#define p(s) cout<<(s)<<endl
#define p2(a, b) cout<<(a)<<" "<<(b)<<endl
#define v2(T) vector<vector<T>>
typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;
const ll inf = 1e18;


ll a, b, c;

int main() {
    cin>>a;

    if(a==3||a==5||a==7){
        p("YES");
    }else{
        p("NO");
    }


    return 0;
}
