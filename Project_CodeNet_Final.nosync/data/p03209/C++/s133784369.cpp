#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<ll> num, pnum;

ll f(ll n, ll x){
    if (n == 0) return 1;
    if (x == 1) return 0;
    else if (1 < x && x <= num[n-1]+1) return f(n-1, x-1);
    else if (x == num[n-1]+2) return pnum[n-1]+1;
    else if (num[n-1]+2 < x && x < 2*num[n-1]+2) return pnum[n-1] + 1 + f(n-1, x-num[n-1]-2);
    else if (x == 2 * num[n-1] + 3) return 2 * pnum[n-1] + 1;
}

int main(){
    ll n, x;
    cin >> n >> x;
    num = vector<ll>(n+1);
    pnum = vector<ll>(n+1);
    num[0] = 1, pnum[0] = 1;
    for(int i = 1; i <= n; i++){
        num[i] = num[i-1]  * 2 + 3;
        pnum[i] = pnum[i-1] * 2 + 1;
    }
    f(n, x);
    ll ans = f(n, x);
    cout << ans << endl;
}