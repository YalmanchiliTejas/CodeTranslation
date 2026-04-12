#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll MOD = 1e9+7;
const ll D = 1e4+9;
const ll R = 1e2+9;

ll mod(ll n, ll m) {
    n %= m;
    if(n < 0)  n += m;
    return n;
}

ll mod(ll n) {
    return mod(n, MOD);
}

void modadd(ll &a, ll b) {
    a = mod( mod(a) + mod(b) );
}

string s;
int d, r;
ll eq[D][R];
ll lt[D][R];

int main() {
    cin >> s >> r;
    d = s.size();

    for(int i = 0; i <= 9; i++) {
        modadd(eq[0][mod(i, r)], i == s[0]-'0');
        modadd(lt[0][mod(i, r)], i < s[0]-'0');
    }

    for(int di = 1; di < d; di++) {
        for(int ri = 0; ri < r; ri++) {
            int num = s[di] - '0';
            eq[di][ri] = eq[di-1][mod(ri-num, r)];
            for(int i = 0; i <= 9; i++)
                modadd(lt[di][ri], lt[di-1][mod(ri-i, r)]);
            for(int i = 0; i < num; i++)
                modadd(lt[di][ri], eq[di-1][mod(ri-i, r)]);
        }
    }

    ll ans = 0;
    modadd(ans, lt[d-1][0]);
    modadd(ans, eq[d-1][0]);
    modadd(ans, -1);
    cout << ans << endl;
}