        #include <bits/stdc++.h>

        using namespace std;

        #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        #define FOR(i,a,b) for(int i = (a); i < (b); i++)
        #define rep(i,n) FOR(i,0,n)
        #define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
        #define ITER(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
        #define FILL(a,value) memset(a, value, sizeof(a))

        #define SZ(a) (int)a.size()
        #define ALL(a) a.begin(),a.end()
        #define PB push_back
        #define MP make_pair
        #define in insert
        #define er erase
        #define fs first
        #define sc second


        typedef long long LL;
        typedef vector<int> VI;

        typedef vector<bool> VB;
        typedef vector<LL> VL;
        typedef pair<int,int> PII;
        typedef pair<LL,LL> PLL;
        typedef vector<PII> VPI;
        typedef vector<VL>VVL;
        typedef vector<VI>VVI;
        typedef vector<string>VS;

        typedef vector<vector<PII>> VVPI;
        typedef vector<vector<PLL>> VVPL;



        const double PI = acos(-1.0);
        const int INF = 1000 * 1000 * 1000 + 7;
        const LL LINF = INF * (LL)INF;

        const int MAX = 305;

        const int MAS = 1e5 + 10 ;
        const int MOD = 1000 * 1000 * 1000 + 7;
        const double EPS = 1e-8;



        int main() {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            //  freopen("skateboard.in","r",stdin);
            //  freopen("skateboard.out","w",stdout);
               string   k ;
               cin >> k ;
               int len =SZ(k);
               int d;
               cin >> d;
               vector<vector<int >> dp(d,vector<int> (2));

               dp[0][0] = 1;
               FOR(i,0,len)
                {
                   vector<vector<int >>new_dp(d,vector<int > (2));
                   rep(rem,d) {
                       for (bool ws : {false, true})
                       {
                           rep(digit,10)
                           {
                               if(digit > k[i] - '0' && !ws) {
                                   break;
                               }
                               new_dp[(rem + digit)%d][ws || (digit < k[i] - '0')] +=dp[rem][ws];
                               new_dp[(rem + digit)%d][ws || (digit < k[i] - '0')]%=MOD;
                           }
                       }

                   }
                   dp = new_dp;
               }
               int ans = (dp[0][0] + dp[0][1])%MOD;
               ans--;
               if(ans == -1 )
               {
                   ans = MOD-1;
               }
               cout << ans << endl;
        }