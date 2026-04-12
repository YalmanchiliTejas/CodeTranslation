#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, s) for (int i = 0; i < s; ++i)
#define ALL(v) (v).begin(), (v).end()
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define DEBUG
#define int long long
#define INF 1e18
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class T> ostream& operator << (ostream &s, set<T> P)
{ EACH(it, P) { s << "<" << *it << "> "; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P)
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s << endl; }
template<class T>void show(vector<T>v){for (int i = 0; i < v.size(); i++){cerr<<v[i]<<" ";}cerr<<"\n";}
typedef long long ll;

int dp[200010][3];
signed main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int cnta = 0, cntb = 0;
    REP(i, n)
    {
        cin >> a[i];
    }
    if(n%2==0){
        dp[0][0] = a[0];
        dp[1][1] = a[1];
        for (int i = 2; i < n; i++)
        {
            if(i <= n-2) dp[i][0] = dp[i - 2][0] + a[i];
            if(i - 3 >= 0) dp[i][1] = dp[i - 2][1] + a[i];
            if (i - 3 >= 0)
            {
                chmax(dp[i][1], dp[i - 3][0] + a[i]);
            }
        }
        cout << max(dp[n - 2][0], dp[n - 1][1]) << endl;
    }
    else{
        dp[0][0] = a[0];
        dp[1][1] = a[1];
        dp[2][2] = a[2];

        for (int i = 2; i < n; i++)
        {
            if(i <= n-3 && i!=3 )
                dp[i][0] = dp[i - 2][0] + a[i];
            if (i  >= 3 && i <= n - 2 && i!=4)
                dp[i][1] = dp[i - 2][1] + a[i];
            if(i  >= 4  ){
                dp[i][2] = dp[i - 2][2] + a[i];
            }
            if (i - 3 >= 0 && i <= n - 2){
               if(i-3 != 1) chmax(dp[i][1], dp[i - 3][0]+a[i]);
            }
            if(i - 4 >= 0 ){
                if(i!=5)chmax(dp[i][2], dp[i - 3][1] + a[i]);
               if(i-4!=1) chmax(dp[i][2], dp[i - 4][0] + a[i]);
            }
          //  cerr <<i<<" "<< dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
        }
        cout << max({dp[n - 3][0], dp[n - 2][1], dp[n - 1][2]}) << endl;
    }

    return 0;
}