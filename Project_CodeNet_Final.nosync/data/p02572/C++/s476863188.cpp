#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(a) a.begin(),a.end()
typedef long long ll;
#define D 1000000007
#define INF 1<<30

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

int main()
{
    int N;
    cin >> N;
    vector<ll> A(N);
    ll sum = 0;
    REP(i,N){
        cin >> A[i];
        sum += A[i];
        sum %= D;
    }
    ll square = 0;
    REP(i,N){
        square += (A[i]*A[i]);
        square %= D;
    }
    ll invtwo = modinv(2,D);
    ll sumsq = (sum*sum)%D;
    ll sumpro = (((sumsq-square)%D)*invtwo)%D;
    if(sumpro<0){
        sumpro += D;
    }
    cout << sumpro << endl;
    return 0;
}