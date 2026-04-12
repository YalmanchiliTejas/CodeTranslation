#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) FOR(i,0,n)
#define repr(i,n) for(int i=(n)-1;0<=i;--i)
#define each(e,v) for(auto&& e:(v))
#define all(v) begin(v),end(v)
#define dump(x) cerr<<#x<<": "<<(x)<<endl
#define INF 100000000
#define IINF 9999999999999;
using vint = vector<int>;
using ll = long long;
using vll = vector<ll>;
template <class T> void chmin(T& a, const T& b) { a = min(a, b); }
template <class T> void chmax(T& a, const T& b) { a = max(a, b); }

int n;
vector<int> d;

bool func(){
    int t = n - 1;
    for(int i = n - 2; i >= 0; i--){
        if(d[i] + i >= t) t = i;
    }
    reverse(d.begin(), d.end());
    return t == 0;
}

int main(){
    cin >> n;
    d = vector<int>(n);

    for(int i = 0; i < n; i++){
        cin >> d[i];
        d[i] /= 10;
    }

    if(func() && func()) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}
