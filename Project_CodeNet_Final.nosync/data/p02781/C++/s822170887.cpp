#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < n; i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
#define repran(i, a,b) for (int i = a; i<b;i++)
#define all(x) (x).begin(), (x).end()
#define v(T) vector<T>
#define vv(T) vector<v(T)>
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
template<class T>bool chmax(T &a, const T &b){
    if (a < b) {a = b; return true;}
    return false;
}
template<class T>bool chmin(T &a, const T &b){
    if (a > b) {a = b; return true;}
    return false;
}

int comb(int n, int k){
    if (n<k or k < 0) return 0;
    int ret = 1;
    for (int i = n; i> n-k; i--){
        ret *= i;
    }
    for (int i = 1;i<k+1;i++){
        ret /= i;
    }
    return ret;
}

int dp[1000][4][2];
int main()
{
    string s;
    cin >> s;
    int N = s.size();
    int K; cin >> K;
    dp[0][0][0] = 1;
    rep(i, N){
        int num = s[i]-'0';
        rep(j, K+1) rep(k, 2){
            rep(d, 10){
                int nj = j, nk = k;
                if (d!= 0) nj++;
                if (nj > K) continue;
                if (k==0) {
                    if (d > num) continue;
                    else if (d < num) nk++;
                }
                dp[i+1][nj][nk] += dp[i][j][k];
            }

        }
    }
    cout << dp[N][K][0]+dp[N][K][1] << endl;
}

