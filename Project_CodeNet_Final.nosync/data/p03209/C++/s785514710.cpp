#include <bits/stdc++.h>

using namespace std;


//repetition
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define euc_dis(x, y) sqrt(x*x + y*y)

#define MOD 1e9+7
#define sp ' '


using ll = long long;


ll mod(ll a, ll b){return (a%b+b)%b;}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
void Yes(){cout << "Yes" << endl;}
void No(){cout << "No" << endl;}
void Judge(bool b){b?Yes():No();}
void YES(){cout << "YES" << endl;}
void NO(){cout << "NO" << endl;}
void JUDGE(bool b){b?YES():NO();}
ll powMod(ll b, ll e, ll m){ll r=1;while(e>0){if(e&1)r=(r%m)*(b%m)%m;b=(b%m)*(b%m)%m;e>>=1;}return r;}
double distance(ll x1, ll y1, ll x2, ll y2){return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));}

template<typename T>
void ppp(T n){cout << n << endl;}

ll paty(ll l){
    return pow(2, l+1)-1;
}
ll layer(ll l){
    return pow(2, l+2)-3;
}


ll f(ll n, ll x){

    if(n == 0){
        return x<=0 ? 0 : 1;
    }
    else if(x <= 1+layer(n-1)){
        return f(n-1, x-1);
    }
    else{
        return paty(n-1) + 1 + f(n-1, x-2-layer(n-1));
    }
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, x;
    cin >> n >> x;


    ppp(f(n, x));




    return 0;
}
