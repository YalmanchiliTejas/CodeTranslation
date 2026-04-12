#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)
#define mp make_pair

int64 a(int32 l){
    if(l == 0)return 1;
    return a(l-1) * 2 + 3;
}

int64 f(int32 l, int64 x){
    if(l == 0 && x == 1)return 1;
    if(x <= 1)return 0;
    if(2 <= x && x <= a(l-1) + 1){
        return f(l-1, x - 1);
    }
    if(x == a(l-1) + 2){
        return f(l-1, x-2) + 1;
    }
    if(a(l-1) + 3 <= x && x <= a(l-1) * 2 + 2){
        return f(l-1,a(l-1)) + f(l-1, x - a(l-1) - 2) + 1;
    }
    if(x == a(l)){
        return f(l-1,a(l-1)) * 2 + 1;
    }
    return -1;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int32 n;
    int64 x;
    cin >> n >> x;
    ANS(f(n, x));
    return 0;
}