



    #include <iostream>
    #include <sstream>
    #include <iomanip>
    #include <cstdio>
    #include <cstdlib>
    #include <cmath>
    #include <cctype>
    #include <cstring>
    #include <vector>
    #include <list>
    #include <queue>
    #include <deque>
    #include <stack>
    #include <map>
    #include <set>
    #include <algorithm>
    #include <iterator>
    #include <bitset>
    #include <ctime>



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

    typedef  long long LL;
    typedef vector<int> VI;
    typedef pair<int, int> PII;

    const double PI = acos(-1.0);
    const int INF = 1000 * 1000 * 1000 + 7;
    const LL LINF = INF * (LL)INF;

    const double EPS = 1e-7;
    const int MAX = 20 * 1000 + 47;
    const int MAS = 1e5 * 3;
    const int MOD = 1000 * 1000 * 1000 + 7;

    double DIST(double x1, double x2, double y1, double y2)
    {
        return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }
    
    LL dp[3005][3005];
    int main()
    {
        int n;
        cin >> n; 
        vector<LL> a(n);
        rep(i, n)
        {
            cin >> a[i]; 
        }
        for (int l = n - 1; l >= 0; l--)
        {
            for (int r = l; r < n; r++)
            {
                if (l == r)
                {
                    dp[l][r] = a[l]; 
                }
                else
                {
                    dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r -1]); 
                }
            }
        }
        cout << dp[0][n - 1] << endl;   

    }







