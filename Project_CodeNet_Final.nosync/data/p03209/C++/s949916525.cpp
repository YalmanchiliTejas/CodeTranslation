#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

vector<ll> a, p;

ll f(int n, ll x){

    // レベル0のバーガーの場合
    if (n == 0){
        // xがあれば1
        if (x > 0) return 1;
        else return 0;
    }
    // バーガーが半分より下
    else if (x <= 1 + a[n-1]){
        return f(n-1, x-1);
    }
    // バーガーのちょうど半分
    else if (x == 2 + a[n-1]){
        return p[n-1] + 1;
    }
    // バーガーが半分より上
    else{
        return p[n-1] + 1 + f(n-1, x-(a[n-1]+2));  
    }
}


int main(){
    int N;
    ll X;
    cin >> N >> X;
    a.resize(N+1);
    p.resize(N+1);
    a[0] = p[0] = 1;
    rep(i,N){
        // バーガーの層
        a[i+1] = 2*a[i]+3;
        // パティの数
        p[i+1] = 2*p[i]+1;        
    }

    cout << f(N,X) << endl;

}