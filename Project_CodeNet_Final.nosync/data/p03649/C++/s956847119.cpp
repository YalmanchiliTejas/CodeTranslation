#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <ii> vii;
typedef vector <vii> vvii;
#define endl '\n'
#define PB push_back
#define MP make_pair
#define fr first
#define sc second
#define OO (1000000000)         // ToDo
#define EPS (1e-9)              // ToDo
#define MOD (1000000007)        // ToDo
#define all(v) ((v).begin()),((v).end())
#define WT(x) cout<< #x <<" = "<<"\""<< (x) <<"\""<<endl
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
void read_file(bool outToFile = true){
#ifdef LOCAL_TEST
    freopen("in", "rt", stdin);
    if(outToFile)
    freopen("out", "wt", stdout);
#endif
}
//
int n;
const int MAXN = 50+99;
ll A[MAXN];
typedef pair <ll, ll> pll;
//
int main()
{
    read_file();
    while(scanf("%d", &n) != -1)
    {
        for(int i=0; i<n; i++)
            scanf("%lld\n", &A[i]);
        
        ll ans = 0;
        while(true)
        {
            sort(A, A+n, greater<ll>());
            ll a = A[0];
            if(a <= n-1) break;
            
            ll x = a/n;
            A[0] = a - x * n;
            ans += x;
            for(int i=1; i<n; i++) A[i] += x;
        }
        
        printf("%lld\n", ans);
    }
}
