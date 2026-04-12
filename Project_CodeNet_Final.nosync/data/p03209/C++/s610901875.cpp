#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define inv(n, a) for(int i = 0; i < n; i++) cin >> a[i]
#define MOD 1000000007
#define INF 1e7
#define LINF 1e15
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
// 'a' = 97 'z' = 122 => 'a' = 0 'z' = 25

vector<ll> a, p;

ll f(int n, ll x){
//    if(x == 1) return 0;
//    else if(x <= 1+a[n-1]) return f(n-1, x-1);
//    else if(x <= 2+a[n-1]) return p[n-1]+1;
//    else if(x <= 2+2*a[n-1]) return 1 + p[n-1] + f(n-1, x-2-a[n-1]);
//    else return 2*p[n-1]+1;
    if(n == 0){
        if(x <= 0) return 0;
        else return 1;
    }else if(x <= 1 + a[n-1]) return f(n-1, x-1);
    else return p[n-1] + 1 + f(n-1, x-2-a[n-1]);
}

int main() {
    int n;
    ll x;
    cin >> n >> x;
    a.resize(n); p.resize(n);
    
    rep(i, n){
        if(i == 0){
            a[0] = 1;
            p[0] = 1;
        }else{
            a[i] = a[i-1]*2+3;
            p[i] = p[i-1]*2+1;
        }
    }
    
    cout << f(n, x) << endl;
}


