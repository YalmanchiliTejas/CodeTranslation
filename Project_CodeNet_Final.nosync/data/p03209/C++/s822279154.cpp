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
#define p2(a, b) cout<<(a)<<" "<<(b)<<endl
typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

ll N, X;
ll s[55], p[55];

ll f(ll n, ll x){   //レベルn, 下からx
    if(x == 1){
        return n == 0 ? 1 : 0;
    }else if(1 < x && x <= s[n-1] + 1){
        return f(n-1, x-1);
    }else if(x == s[n-1] + 2){
        return p[n-1] + 1;
    }else if(s[n-1] + 2 < x && x <= 2*s[n-1] + 2){
        return p[n-1] + 1 + f(n-1, x-(s[n-1]+2));
    }else{  //x == 2*s[n-1] + 3
        //return p[n];
        return 2*p[n-1] + 1;
    }
}

int main() {
    cin>>N>>X;

    s[0] = 1;
    p[0] = 1;
    REP(i,1,N+1) s[i] = 2*s[i-1] + 3;
    REP(i,1,N+1) p[i] = 2*p[i-1] + 1;

    cout<<f(N, X)<<endl;

    return 0;
}
