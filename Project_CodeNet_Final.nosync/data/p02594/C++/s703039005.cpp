#include <bits/stdc++.h>
using namespace std;
#define FIND(c, e) ((c).find(e) != (c).end())
#define NFIND(c, e) ((c).find(e) == (c).end())
#define ALL(t) (t).begin(), (t).end()
#define ALLR(t) (t).rbegin(), (t).rend()
#define MP make_pair
template<class T> inline T max(T a,T b,T c){return max(max(a,b),c);}
template<class T> inline T min(T a,T b,T c){return min(min(a,b),c);}
const int  MOD = int( 1e9 ) + 7;
const int    N = int( 1e5 ) + 42;
const int LOGN = ceil(log(N) / log(2));
const double EPS = 1e-6;


void __answer()
{
    int n;
    cin >> n;
    if(n >= 30) cout << "Yes";
    else cout << "No";
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(11) << fixed;
    #ifdef LOCAL
        freopen("TEST.txt", "r", stdin);
    #endif
    __answer();
    return 0;
}
