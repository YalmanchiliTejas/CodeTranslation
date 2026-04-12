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
                                                        #define sqr(x) ((x)*(x))





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
                                                        typedef pair<LL,LL > PLL ;
                                                        typedef vector<PII> VPI;

                                                        const double PI = acos(-1.0);
                                                        const int INF = 1e9 * 2;
                                                        const LL LINF = (LL)1e18 ;

                                                        const double EPS = 1e-7;
                                                        const int MAS =  3 *1e5 + 10;
                                                     //   const int mod = 998244353;
                                                        const int MOD =1e9+7;
                                                        const int LOG= 19;
                                                        const int ar = 1e5 +100;
                                                        const int MAX = 1e6 + 1e2;
                                                        const int root = 0;




                                                        const int mx =20101;
                                                        const int nax = 2 * 1e5 + 100 ;

                                             VL t;
                                             VL lazy;

                                             void update(int v, int tl, int tr  ,int l ,int r,LL val )
                                             {
                                                 if (lazy[v]!=0)
                                                 {
                                                     t[v]+=lazy[v];
                                                     if(tl !=tr)
                                                     {
                                                         lazy[v * 2 ] +=lazy[v];
                                                         lazy[v * 2 + 1] +=lazy[v];
                                                     }
                                                     lazy[v] = 0;
                                                 }
                                                 if ( l<=tl && r >=tr)
                                                 {
                                                     t[v] += val;
                                                     if(tl !=tr)
                                                     {
                                                         lazy[v * 2] +=val;
                                                         lazy[v * 2 +1] +=val;
                                                     }
                                                     return ;
                                                 }
                                                 if ( tr < l || tl > r)return ;
                                                 int tm  = (tl + tr)/2;
                                                 update(v * 2 , tl , tm , l ,r ,val);
                                                 update(v * 2 + 1, tm  +1 ,tr, l ,r ,val);
                                                 t[v] = min(t[v* 2],t[v * 2 +1]);
                                             }
                                             LL  mn (int v ,int tl ,int tr ,int l ,int r )
                                             {
                                                 if (lazy[v] !=0)
                                                 {
                                                     t[v] +=lazy[v];
                                                     if(tl !=tr)
                                                     {
                                                         lazy[v * 2] +=lazy[v];
                                                         lazy[v * 2 + 1] +=lazy[v];
                                                     }
                                                     lazy[v] = 0;
                                                 }
                                                 if (tl > r || tr < l )
                                                 {
                                                     return INF;
                                                 }
                                                 if(l <=tl && r >=tr)
                                                 {
                                                     return t[v];
                                                 }
                                                 int tm = (tl + tr)/ 2;
                                                 return min(mn(v * 2 ,tl ,tm, l ,r ),mn (v* 2 +1 ,tm + 1, tr, l ,r )) ;
                                             }

                                             vector<pair<int ,int >>interval[nax];
                                                        int main() {
                                                            ios_base::sync_with_stdio(false);
                                                            cin.tie(NULL);
                                                            // freopen("horrible.in","r",stdin);
                                                            // freopen("horrible.out","w",stdout);
                                                            int n,m;
                                                            cin >> n >> m ;
                                                            LL sum = 0 ;
                                                            rep(i,m)
                                                            {
                                                                int l,r,val;
                                                                cin >> l >> r >> val;
                                                                interval[r].PB({l,val});
                                                                sum+=val;
                                                            }
                                                            t.resize(4 * (n + 5 )  ,INF);
                                                            lazy.resize(4 * (n +5 ) );
                                                            update(1, 0, n, 0 , 0 ,-INF);
                                                            LL ans = 0;
                                                            FOR(i,1,n + 2 )
                                                            {
                                                               for(auto ev : interval[i - 1])
                                                               {
                                                                   update(1,0,n,0,ev.f - 1, ev.s);
                                                               }
                                                               LL best = mn(1,0,n,0,n);
                                                               if(i == n +1)
                                                               {
                                                                   ans = best;
                                                               }
                                                                update(1,0,n,i,i,best - INF);
                                                            }
                                                            cout << sum - ans ;

                                                        }
