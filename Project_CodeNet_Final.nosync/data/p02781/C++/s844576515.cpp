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
    
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2)));
    dp[0][0][true] = 1;
    for(int index = 0; index < n; index++) {
        for(int count = 0; count <= k; count++) {
            for(int num = 0; num <= 9; num++) {
                if(num == 0) {
                    dp[index + 1][count][s[index] == '0'] += dp[index][count][true];
                    dp[index + 1][count][false] += dp[index][count][false];
                } else if(count + 1 <= k) {
                    if(s[index] - '0' > num) {
                        dp[index + 1][count + 1][false] += dp[index][count][true];
                    } else if(s[index] - '0' == num) {
                        dp[index + 1][count + 1][true] += dp[index][count][true];
                    }
                    dp[index + 1][count + 1][false] += dp[index][count][false];
                }
            }
        }
    }
    cout << dp[n][k][false] + dp[n][k][true] << endl;
    return 0;
}