#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;i<(n);i++)
#define REP(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define INF INT_MAX
#define MOD 1000000007
#define fcout cout << fixed << setprecision(15)
#define int long long
#define yorn(f) puts((f)?"Yes":"No")
#define YORN(f) puts((f)?"YES":"NO")
#define sec second
#define fir first
typedef long long ll;
typedef pair<int, int> P;
typedef priority_queue<int> pque;
typedef vector<int> Vec;
int gcd(int a,int b){return b?gcd(b,a%b):a;};
int lcm(int a,int b){return a/gcd(a,b)*b;};
int mod(int a,int b){return (a+b-1)/b;};
template<typename A, size_t N, typename T>
void Fill(A(&array)[N],const T &val){std::fill((T*)array,(T*)(array+N),val);}
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;};
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;};



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    string k;
    int d;
    cin >> k >> d;
    vector<vector<int>> dp(d, vector<int>(2));
    dp[0][true] = 1;

    rep(i, k.size()) {
        int here = k[i] - '0';
        vector<vector<int>> after(d, vector<int>(2));

        for(int prevmod = 0; prevmod < d; prevmod++) {
            for(int now = 0; now < 10; now++) {
                int nowmod = (prevmod + now) % d;
                if(now < here) {
                    after[nowmod][false] += dp[prevmod][true];
                    after[nowmod][true] %= MOD;
                } else if(now == here) {
                    after[nowmod][true] += dp[prevmod][true];
                    after[nowmod][true] %= MOD;
                }
                after[nowmod][false] += dp[prevmod][false];
                after[nowmod][false] %= MOD;
            }
        }
        dp = after;
    }

    cout << (dp[0][true] + dp[0][false] - 1 + MOD) % MOD << endl;
    return 0;
}