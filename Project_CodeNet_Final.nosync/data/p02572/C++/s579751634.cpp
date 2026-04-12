#include <bits/stdc++.h>
typedef long long ll;
#define _GLIBCXX_DEBUG
#define int long long
using namespace std;
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPR(i, n) for (ll i = (ll)(n)-1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORD(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MAXIN(x) max_element(ALL(x)) - x.begin();
#define MIN(x) *min_element(ALL(x))
#define MININ(x) min_element(ALL(x)) - x.begin();
#define INF 1000000000000
#define MOD 1000000007

#define MAXR 100000
#define PI 3.14159265358979323846

    using namespace std;

signed main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    int sum = 0;
    int ans = 0;
    REP(i, n){
        cin >> A[i];
        sum += A[i];
        sum %= MOD;
    }
    //cout << sum <<endl ;

    REP(i,n){
        sum -= A[i];
        if (sum < 0) sum += MOD;
        
        int a = A[i] * sum;
        
        //cout <<"a"<<a   <<endl ;
      //  a = a % MOD;
        ans += a;
        ans = ans % MOD;
    }

    cout << ans <<endl ;



    return 0;
}