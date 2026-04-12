#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n, x;

int main(void){
    cin >> n >> x;
    vector<lli> a(n+1), p(n+1);
    a[0] = 1;
    p[0] = 1;
    for(int i = 1; i <= n; i++){
        a[i] = 2*a[i-1]+3;
        p[i] = 2*p[i-1]+1;
    }
    //cout << a[n] << " " << p[n] << endl;
    function<lli(lli N, lli X)> f = [&](lli N, lli X){
        if(N == 0){
            if(X > 0) return 1LL;
            else return 0LL;
        }
        if(X <= 1+a[N-1]) return f(N-1, X-1);
        else return p[N-1]+1LL+f(N-1, X-a[N-1]-2LL);
    };
    cout << f(n, x) << endl;
    return 0;
}
