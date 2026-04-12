#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pii;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fo(i,a,b) for(ll i = a; i<=b;i+=1)
#define rf(i,a,b)  for(ll i=a;i>=b;i--)
#define vll vector<ll>
#define sz(a) ll(a.size())
#define all(v) v.begin(),v.end()
#define pb push_back
#define pf push_front 
#define MAXN 100010
#define N 100010
#define MOD 1000000007
#define mod 998244353
#define deb(x) cout << '>' << #x << ':' << x << endl;
#define debug(x) cout << '>' << #x << ':' << x << " ";
#define nl '\n'
#define INF 1000000000000000000
#define IO                 \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);
#define int long long int
main()
{
    IO;
	int T = 1;
    // cin >> T;
    fo(c, 1, T){
        // cout<<"Case #"<<c<<": ";
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        int ans = 0;
        int pre = arr[0];
        for(int i = 1; i < n; i++){
            (ans += (pre * (arr[i]%MOD)))%=MOD;
            (pre += arr[i])%=MOD;
        }
        cout << ans << nl;
    }
    return 0;
}