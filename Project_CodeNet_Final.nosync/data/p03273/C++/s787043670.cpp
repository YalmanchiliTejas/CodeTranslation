#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <math.h>
#include <queue>

using namespace std;

typedef long long int ll;
typedef long double ld;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define vsort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())

const int MOD = 1000000007;
const int INF = INT_MAX;


// a,bの最小公倍数
ll LCM(ll a, ll b){ll lcm = a * b; ll r = a % b;while(r != 0){a = b; b = r; r = a % b;}return lcm /= b;}
// a,bの最大公約数
ll GCD(ll a, ll b){ll r = a % b;while(r != 0){a = b; b = r; r = a % b;}return b;}
// MOD
ll modadd(ll a, ll b){return (a%MOD+b%MOD+MOD)%MOD;}
ll modmul(ll a, ll b){return a%MOD*b%MOD%MOD;}
ll modexp(ll a, ll n){if(n==0)return 1; if(n%2==0){ll e=modexp(a,n/2); return modmul(e,e);} return modexp(a,n-1)*a%MOD;}
ll modinv(ll n){return modexp(n%MOD,MOD-2);}
ll modfact(ll n){ll res=1; for (int i=1; i <= n; ++i){res *= i; res %= MOD;} return res;}
ll modncr(ll n, ll r){ll numer=1;ll denom=1;for(int i=1;i<=r;++i){numer=modmul(numer,n-r+i);denom=modmul(denom,i);}return modmul(numer, modinv(denom));}


int main(){
    
    int h, w;
    cin >> h >> w;
    char cell[h][w];
    rep(i,h) {
        rep(j,w) {
            cin >> cell[i][j];
        }
    }

    bool flag_h[h];
    rep(i,h) flag_h[i] = true;
    bool flag_w[w];
    rep(i,w) flag_w[i] = true;

    rep(i,h) {
        bool line = true;
        rep(j,w) {
            if (cell[i][j] != '.') line = false;
        }
        if (line) flag_h[i] = false;
    }

    rep(j,w) {
        bool line = true;
        rep(i,h) {
            if (cell[i][j] != '.') line = false;
        }
        if (line) flag_w[j] = false;
    }

    rep(i,h) {
        if(flag_h[i]) {
            rep(j,w) {
                if (flag_w[j]) cout << cell[i][j];
            }
            cout << endl;
        }
    }


}





//              g++ -std=c++1z
