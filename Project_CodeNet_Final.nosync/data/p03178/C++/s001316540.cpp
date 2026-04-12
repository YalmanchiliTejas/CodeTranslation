                            #include<bits/stdc++.h>
                            using namespace std;

                            #define FOR(i,a,b) for(int i = (a); i < (b); i++)
                            #define rep(i,n) FOR(i,0,n)
                            #define RFOR(i,b,a) for(int i = (b) - 1; i>= (a); i--)
                            #define ITER(it, a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
                            #define FILL(a, value) memset(a, value, sizeof(a)

                            #define SZ(a) (int)a.size()
                            #define ALL(a) a.begin(), a.end()
                            #define PB push_back
                            #define MP make_pair
                            #define er erase
                            #define in insert
                            #define f first
                            #define s second




                            typedef  long long LL;
                            typedef vector<int> VI;
                            typedef vector<LL > VL;
                            typedef vector<vector<int > > VVI;
                            typedef vector<vector<LL>> VVL;
                            typedef vector <vector<pair<int, int >> >VVPI;
                            typedef vector<vector<pair<LL, LL >> >VVPL;
                            typedef vector<pair<LL, LL >> PL;
                            typedef vector<PL> VPL;
                            typedef pair<int, int> PII;
                            typedef vector<PII> VPI;

                            const double PI = acos(-1.0);
                            const int INF = 1e9;
                            const LL LINF = (LL)1e18;

                            const double EPS = 1e-7;
                            const int MAS =  3 *1e5 + 10;
                            const int mod = 998244353;
                            const int MOD =1e9+7;
                            const int LOG= 19;
                            const int ar = 1e5 +100;
                            const int MAX = 1e6 + 1e2;


                        int main() {
                            ios_base::sync_with_stdio(false);
                            cin.tie(NULL);
                            string k ;
                            cin >> k;

                            int d;cin >> d;
                            vector<vector<int >> dp(d,vector<int > (2,0));
                            dp[0][0] = 1;
                            rep(i,SZ(k))
                            {
                                vector<vector<int >> new_dp(d,vector<int > (2));
                                rep(rem,d) {
                                    rep(alr, 2) {
                                        rep(digit, 10) {
                                           if(digit > k[i] -'0' && !alr)break;
                                           new_dp[(rem + digit )% d][alr == 1 || (digit < k[i] -'0')]+=dp[rem][alr];
                                            new_dp[(rem + digit )% d][alr == 1 || (digit < k[i] -'0')]%=MOD;

                                        }
                                    }
                                }
                                dp = new_dp;
                            }
                            int ans =(dp[0][0] + dp[0][1])%MOD;
                            ans--;
                            if(ans == -1)ans+=MOD;
                            cout << ans << '\n';



                        }















































