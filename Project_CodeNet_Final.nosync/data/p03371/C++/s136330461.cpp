#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
typedef long long ll;
using namespace std;

int main() {
    ll a,b,c,x,y, ans=0, more_pizza,buy_pizza,cost;
    scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&x,&y);
    if(c*2<=a+b){
        buy_pizza = min(x,y);
        ans += c * buy_pizza * 2;
        more_pizza = max(x,y) - buy_pizza;
        if(max(x,y) == x){// aの方がたくさん買いたい
            cost = min(a,2*c);
            if(cost == a) ans += a*more_pizza;
            else ans += c* 2* more_pizza;
        }
        else{
            cost = min(b,2*c);
            if(cost == b) ans += b*more_pizza;
            else ans += c* 2* more_pizza;
        }
    }
    else{
        ans = a*x+b*y;
    }
    printf("%lld", ans);

    return 0;
}