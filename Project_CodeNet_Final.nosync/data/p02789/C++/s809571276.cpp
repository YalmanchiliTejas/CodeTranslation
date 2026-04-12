#include<bits/stdc++.h>
typedef long long ll;
#define sz(x) int(x.size())
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
#define MOD 1000000007
 
ll gcd(ll a, ll b){
    if(b == 0) return a;
 
    return gcd(b, a%b);
}
ll lcm(ll a, ll b){
    return a * b / gcd(a,b);
}

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main(void){
    int N,M; cin >> N >> M;
    if(N == M) cout << "Yes" << endl;
    else cout << "No" << endl;
}