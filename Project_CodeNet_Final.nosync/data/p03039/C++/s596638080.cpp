#include <bits/stdc++.h>
using namespace std;
typedef long long int ll; 

// https://qiita.com/drken/items/b97ff231e43bce50199a
// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

ll f(ll a, ll b){
    return ((a+b-2)*a*b)/2;
}


int main(void){
    ll N, M,K;
    cin >> N >> M >> K ;
    ll P = 1000*1000*1000 + 7; 
    
    ll comb=1; 
    for(ll i=0; i<K-2; i++){
        comb= (comb*(N*M-2-i))%P;
        ll xx, yy;
        extGCD(K-i-2,P,xx,yy);
        if(xx<0){
            xx = (-xx)%P;
            xx = P-xx;
        } 
        comb =(comb*xx)%P;
    }
    
    ll S=0;
    
    for(ll i=1; i<=N; i++){
        for(ll j=1; j<=M; j++){
            S= S + f(i,j) + f(i,M+1-j) + f(N+1-i,j) + f(N+1-i,M+1-j);
            S= S - f(1,j) - f(1,M+1-j) - f(i,1) - f(N+1-i,1); 
            S= S%P;
        }
    }
    
    S= (S*comb)%P; 
    S= (S*((P+1)/2))%P;  
    
    cout<< S << endl; 
    
}