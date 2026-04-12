#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
using namespace std;
typedef long long ll;
const ll P = 1e9+7;
int N,A,B,C,D;
ll fact[1010];
ll dp[1010][1010];

ll ext_gcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll nx, ny;
    ll g = ext_gcd(b, a%b, nx, ny);
    x = ny;
    y = nx - a/b*ny;
    return g;
}

ll inv(ll a){
    ll x, y;
    ext_gcd(a, P, x, y);
    while(x < 0) x += P;
    return x%P;
}

ll pow(ll a, int n){
    if(n == 0) return 1;
    if(n == 1) return a;
    if(n%2==1){
        return a*pow(a,n-1)%P;
    }
    else{
        ll b = pow(a,n/2);
        return b*b%P;
    }
}


int main(){
    cin >> N >> A >> B >> C >> D;
    fact[0] = fact[1] = 1;
    for(int i=2; i<1010; i++){
        fact[i] = fact[i-1]*i%P;
    }

    for(int x=0; x<=B-A; x++) dp[0][x] = 1;
    for(int m=0; m<=N; m++) {
        if(m%A == 0 && C <= m/A && m/A <= D){
            dp[m][0] = fact[m]*inv(pow(fact[A], m/A)*fact[m/A]%P)%P;
        }
    }
    for(int m=1; m<=N; m++){
        for(int x=1; x<=B-A; x++){
            dp[m][x] = dp[m][x-1];
            for(int y=C; y<=D; y++){
                if((A+x)*y > m) break;
                ll t = fact[m]*inv((fact[m-y*(A+x)]*pow(fact[A+x],y)%P)*fact[y]%P)%P;
                dp[m][x] += dp[m-y*(A+x)][x-1]*t%P;
                dp[m][x] %= P;
            }
        }
    }

/*
    for(int m=0; m<=N; m++){
        for(int x=0; x<=B-A; x++){
            cout << dp[m][x] << " ";
        }
        cout << endl;
    }
    */

    cout << dp[N][B-A] << endl;

    return 0;
}
