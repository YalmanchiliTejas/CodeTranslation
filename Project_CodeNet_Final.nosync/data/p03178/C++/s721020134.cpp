#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define fi first
#define se second
#define mp make_pair
#define itrfor(itr,A) for(auto itr = A.begin(); itr !=A.end();itr++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
typedef long long llong;
char moji[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char moji2[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char moji3[10]={'0','1','2','3','4','5','6','7','8','9'};
#define Sort(a) sort(a.begin(),a.end());
#define Reverse(a) reverse(a.begin(),a.end());
#define print(a) cout << a << endl;
#define MOD llong(1e9+7)
#define MAX int(2 * 1e5 +5)
#define debug(x)  cout << #x << " = " << (x) << endl;
#define pi acos(-1.0)
#define int llong
#define INF llong(1e17)
template<class T> bool chmax(T &a,  T b) {if(a<b){a=b; return 1;} return 0;}
template<class T> bool chmin(T &a,  T b) {if(a>b){a=b; return 1;} return 0;}
void myprint(int* A,int A_num){
   REP(i,A_num) cout << A[i] << " ";
   cout << endl;
}

const int d_max = 105;
const int k_max = 100005; 

signed main(){
    string s;
    int d;
    cin >> s >> d;
    int n = s.size();

    int dp[k_max][d_max][2];
    REP(i,n+1) REP(j,d) REP(k,2) dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    REP(i,n){
        REP(j,d){
            REP(k,10){
                if(k < s[i] - '0') dp[i+1][(j + k) % d][1] += dp[i][j][0],dp[i+1][(j + k) % d][1]%= MOD;
                else if( k == s[i] - '0') dp[i+1][(j+k)%d][0] += dp[i][j][0],dp[i+1][(j+k)%d][0] %= MOD;
                else break;
            }
            REP(k,10) dp[i+1][(j+k) %d][1] += dp[i][j][1], dp[i+1][(j+k) %d][1]%= MOD;

        }
    }

    cout << (dp[n][0][0] + dp[n][0][1] + MOD - 1) % MOD << endl;

}