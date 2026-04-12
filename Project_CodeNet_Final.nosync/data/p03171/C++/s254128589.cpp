#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>

#define rep(i,n) for(int i=0;i<(n);i++)
#define EPS (1e-7)
#define INF (2e9)

using namespace std;
typedef long long int ll;

const int MOD = 1000000007;
struct mint { int n; mint(int n_ = 0) : n(n_) {} };
mint operator-(mint a) { return -a.n + MOD * (a.n != 0); }
mint operator+(mint a, mint b) { int x = a.n + b.n; return x - (x >= MOD) * MOD; }
mint operator-(mint a, mint b) { int x = a.n - b.n; return x + (x < 0) * MOD; }
mint operator*(mint a, mint b) { return (long long)a.n * b.n % MOD; }
mint &operator+=(mint &a, mint b) { return a = a + b; }
mint &operator-=(mint &a, mint b) { return a = a - b; }
mint &operator*=(mint &a, mint b) { return a = a * b; }
istream &operator>>(istream &i, mint &a) { return i >> a.n; }
ostream &operator<<(ostream &o, mint a) { return o << a.n; }

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int N;
ll a[3000];
ll dp[3001][3001];

int main(void){
    cin >> N;
    rep(i,N) cin >> a[i];

    for(int len=1;len <= N;len++)
        for(int i = 0;i+len<=N;i++){
        int j = i + len;
        if((N-len)%2 == 0) dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1]);
        else dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
    }

    cout << dp[0][N] << endl;
    return 0;
}

