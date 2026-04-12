#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long
string N;
int K;
int ans = 0;
int choice(int N, int r) {
    int ret = 1;
    rep(i, r) ret *= N - i;
    //cout << N << " " << r << " " << ret << endl;
    rep(i, r) ret /= i + 1;
    //cout << N << " " << r << " " << ret << endl;
    rep(i, r) ret *= 9;
    //cout << N << " " << r << " " << ret << endl;
    return max(0LL, ret);
}
int f(int digit, int select, bool smaller) {
    if ((int)N.length() - digit  < K - select) return 0;
    if (select == K) return 1;
    if (smaller) {
        //cout << choice(N.length() - digit, K - select) << endl;
        return choice(N.length() - digit, K - select);
    }
    int ret = 0;
    if (N[digit] == '0')
        ret += f(digit + 1, select, false); // 0を選択
    else if (N[digit] != '0')
        ret += f(digit + 1, select, true); // 0を選択
    if (N[digit] >= '2')
        ret += max(0LL, f(digit + 1, select + 1, true) * (N[digit] - '0' - 1)); // 1~N-1を選択
    if (N[digit] >= '1')
        ret += f(digit + 1, select + 1, false); // Nを選択
    //cout << digit << " " << ret << endl;
    return ret;
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    cin >> K;
    int len = N.length();
    int ans = 0;
    cout << f(0, 0, false) << endl;


    return 0;
}
