#include <bits/stdc++.h>
using intl = long long;
using ld = long double;
using namespace std;
#define rep(i, n) for(intl i = 0; i < (intl)(n); i++)
#define repd(i, n) for(intl i = (intl)(n); i >= 0; i--)
#define repi(i, a, b) for(intl i = (intl)(a); i < (intl)(b); i++)
#define repid(i, a, b) for(intl i = (intl)(a); i >= (intl)(b); i--)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define all(x) (x).begin,(x).end()
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,1,sizeof(x))
#define fill(x,y) memset(x,y,sizeof(x))
#define alength(a) (sizeof(a) / sizeof(a[0]))
#define cin(i, a) rep(i, alength(a))cin >> a[i]
#define ccin(i, j, a) rep(i, alength(a))rep(j, alength(a[i]))cin >> a[i][j]
#define debug(x) cout << #x << ":" << x << endl
#define rdebug(i,x) rep(i, alength(x))cout << #x << "[" << i << "]:" << x[i] << endl
#define sqrt sqrtl
#define int intl
#define itn intl
#define double ld
#define pb push_back
#define mp make_pair
const intl INF = 1e9;
const intl MOD = 1e9+7;
const ld eps = 1.0e-14;//-9
void fp(bool f){cout << (f ? "Yes" : "No") << endl;}
void fp(bool f, string s, string t){cout << (f ? s : t) << endl;}
intl kai(intl k){
    intl a = 1;
    for(int i = 2; i <= k; i++){
        a *= i;
    }
    return a;
}
intl gcd(intl a, intl b){
    if(!b)return a;
    return gcd(b, a % b);
}
intl digit10(intl a){
    if(!a)return 1;
    intl b = 0;
    while(a){
        a /= 10;
        b++;
    }
    return b;
}
signed main(){
    cout << fixed << setprecision(10);
    intl a,b,c,d;
    cin >> a >> b >> c;
    d = a * 100 + b * 10 + c;
    fp(!(d%4),"YES","NO");
    return 0;
}