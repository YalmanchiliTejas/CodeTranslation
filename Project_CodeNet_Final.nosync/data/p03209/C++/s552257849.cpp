#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }

ll a[51] = {};
ll p[51] = {};

ll solve(ll N, ll X){
    if(X >= a[N] - 1){
        return p[N];
    }else if(a[N]-1 > X && X > a[N]/2 + 1){
        return p[N-1] + 1 + solve(N-1, X-a[N-1]-2);
    }else if(X == a[N]/2 + 1){
        return p[N-1] + 1;
    }else if(a[N]/2 + 1 > X && X > 1){
        return solve(N-1, X-1);
    }else if(X == 1 && N == 0){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    ll N,X;
    cin >> N >> X;
    a[0] = 1;
    p[0] = 1;
    rep(i,50){
        a[i+1] = 2*a[i] + 3;
        p[i+1] = 2*p[i] + 1;
    }
    cout << solve(N,X) << endl;

}
