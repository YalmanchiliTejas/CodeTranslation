#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long

typedef pair<ll, ll> P;

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main(){
    int a, b, c, x, y, ans = 0;
    cin >> a >> b >> c >> x >> y;

    if(a+b > 2*c) {
        if(x>y) {
            ans += 2*c*y;
            x -= y;
            if(a > 2*c) {
                ans += 2*x*c;
            } else {
                ans += x*a;
            }
        } else {
            ans += 2*c*x;
            y -= x;
            if(b > 2*c) {
                ans += 2*y*c;
            } else {
                ans += y*b;
            }
        }

    } else {
        ans =  a*x + b*y;
    }

    cout << ans << endl;

    return 0;
}
