#include <bits/stdc++.h>
using intl = long long;
using itnl = long long;
using itn = int;
using ld = long double;
using namespace std;
#define rep(i, n) for(intl i = 0; i < (intl)(n); i++)
#define rrep(i, n) for(intl i = (intl)(n) - 1; i >= 0; i--)
#define repi(i, a, b) for(intl i = (intl)(a); i < (intl)(b); i++)
#define rrepi(i, a, b) for(intl i = (intl)(a); i > (intl)(b); i--)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,1,sizeof(x))
#define fill(x,y) memset(x,y,sizeof(x))
#define alength(a) (sizeof(a) / sizeof(a[0]))
#define cin(i, a) rep(i, alength(a))cin >> a[i]
#define ccin(i, j, a) rep(i, alength(a))rep(j, alength(a[i]))cin >> a[i][j]
#define debug(x) cout << #x << ":" << x << endl
#define rdebug(i,x) rep(i, alength(x))cout << #x << "[" << i << "]:" << x[i] << endl
#define sqrt sqrtl
#define itn int
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
intl lcm(intl a,intl b){
    return a / gcd(a, b) * b;
}
intl digit10(intl a){
    intl b = 0;
    do{
        a /= 10;
        b++;
    }while(a);
    return b;
}
signed main(){
    cout << fixed << setprecision(10);
    intl h,w;
    cin >> h >> w;
    char c[h][w];
    ccin(i,j,c);
    bool f1[h];
    bool f2[w];
    rep(i,h){
        bool f = true;
        char a = '.';
        rep(j,w){
            if(a != c[i][j])f = false;
        }
        f1[i] = f;
    }
    rep(i,w){
        bool f = true;
        char a = '.';
        rep(j,h){
            if(a != c[j][i])f = false;
        }
        f2[i] = f;
    }
    rep(i,h){
        if(f1[i])continue;
        rep(j,w){
            if(f2[j])continue;
            cout << c[i][j];
        }
        cout << "\n";
    }
    return 0;
}