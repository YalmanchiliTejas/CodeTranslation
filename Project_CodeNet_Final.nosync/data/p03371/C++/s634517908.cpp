#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1010000000000000017LL;
const ll MOD = 1000000007LL;

#define REP(i, n) for(ll i = 0 ; i < n; i++)

#ifdef DEBUG
#define DBG(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)
#else
#define DBG(fmt, ...)
#endif

int main(){
    std::cout<<std::fixed<<std::setprecision(10);

    ll A,B,C,X,Y;

    cin >> A >> B >> C >> X >> Y;

    ll a,b,c;
    a = X;
    b = Y;
    c = 0;

    ll ans = INF;
    ll cost;
    while(true){
        cost = a*A + b*B + c*C;
        ans = min(ans, cost);
        if( a == 0 && b == 0 ){
            break;
        }

        a = max((ll)0, a-1);
        b = max((ll)0, b-1);
        c += 2;
    }

    cout << ans << endl;
}
