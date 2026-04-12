#include <bits/stdc++.h>
using namespace std ;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll ;
typedef unsigned long long ull ;
typedef long double ld ;

const ll MOD = 1E9 + 7, INF = 2E18 + 5 ;
const double PI = 2 * acos(0.0) ;
const long double EPS = 1.0E-14 ;

map <ll, ll> mp ;
vector <ll> vec ;

int main()
{
    ll n, x, m, ans = 0, cur = 0, val, rep, repVal = 0, need, vx, vy = 0 ;
    cin >> n >> x >> m ;

    for (int i = 0; i < n; i++, cur++) {
        if (mp[x] != 0) {
            val = x ;
            rep = (i + 1) - mp[x] ;
            break ;
        }
        vec.push_back(x) ;
        mp[x] = i + 1 ;
        ans += x ;
        x *= x ;
        x %= m ;
    }
    need = n - cur ;
    if (need <= 0) {
        cout << ans ;
    }
    else {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == val) {
                break ;
            }
            repVal += vec[i] ;
        }
        repVal = ans - repVal ;
        vx = need / rep ;
        ans += (repVal * vx) ;
        vx = need % rep ;

        for (int i = 0; i < vec.size(); i++) {
            if (vx <= 0)    break ;
            if (vec[i] == val) {
                vy = 1 ;
            }
            if (vy) {
                ans += vec[i] ;
                vx-- ;
            }
        }
        cout << ans ;
    }

    return 0 ;
}
