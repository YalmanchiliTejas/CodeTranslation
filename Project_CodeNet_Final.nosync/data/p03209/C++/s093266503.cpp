#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>  
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = 1e+14;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

ll burger(int x) {
    if(x == 0) return 1;
    return 2 * burger(x - 1) + 3;
}
ll paty(int x) {
    if(x == 0) return 1;
    return 2 * paty(x - 1) + 1;
}
ll f(int N, ll X) {
    if(N == 0) return 1;
    if(X == 1) return 0;
    if(X >= 2 && X <= 1 + burger(N - 1)) return f(N - 1, X - 1);
    if(X == burger(N - 1) + 2) return paty(N - 1) + 1;
    if(X >= burger(N - 1) + 3 && X <= 2 * burger(N - 1) + 2) return paty(N - 1) + 1 + f(N - 1, X - burger(N - 1) - 2);
    if(X == burger(N)) return paty(N);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    ll X; cin >> X;

    cout << f(N, X) << "\n";

    return 0;
}