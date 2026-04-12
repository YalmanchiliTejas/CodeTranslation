#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;

#define PI (2*acos(0.0))
#define eps 1e-9
#define pb push_back
#define endl "\n"
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define show(v) for(int fi = 0; fi < v.size(); fi++) cout << v[fi] << " "; cout << endl;
#define showpair(v) for(int fi = 0; fi < v.size(); fi++) cout << v[fi].first << " " << v[fi].second << endl;
#define ff first
#define ss second
#define fu cout << "lol" << endl;
#define precision(n) cout << fixed << setprecision(n);
#define lb lower_bound
#define up upper_bound
#define vscan for(i = 0;i<n;i++){cin>>in; v.pb(in);}
#define all(a) a.begin(), a.end()
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define mem(a,val) memset(a,val,sizeof(a))
#define loop(i,n) for(i = 0; i < n; i++)
#define TC() ull T; cin>>T; while(T--)
#define IN(x) {scanf("%d",&x);}
#define LL(x) {scanf("%lld",&x);}
#define CC(x) {scanf("%c",&x);}
#define pfl(x) printf("%d\n",x)
#define pfll(x) printf("%lld\n",x)
#define newl puts("")
#define space printf(" ")
#define MOD 1000000007
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);

const int N = 2e5 + 10;
ll dp[3][N];

int main()
{
    int i = 0, j = 0, cs = 0, in;
    int n; cin>>n;
    vi v; vscan;
    dp[0][0] = dp[1][0] = dp[2][0] = v[0];
    dp[0][1] = dp[1][1] = dp[2][1] = v[1];
    for(i = 2; i < n; i++){
        dp[0][i] = dp[0][i-2] + v[i];
        dp[1][i] = max(dp[1][i-2], dp[0][i-3]) + v[i];
        dp[2][i] = max(dp[2][i-2], dp[1][i-3]) + v[i];
    }
    if(n & 1){
        ll ans = dp[0][n-3];
        ans = max3(dp[0][n-2], dp[1][n-2], ans);
        ans = max3(dp[0][n-1], dp[1][n-1], max(ans, dp[2][n-1]));
        cout << ans << endl;
    }
    else cout << max3(dp[0][n-2], dp[0][n-1], dp[1][n-1]) << endl;
    return 0;
}
