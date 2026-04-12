#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define lli long long int
#define vi vector<int>
#define vlli vector<lli>
#define vvi vector<vi >
#define str string
#define vs vector<str>
#define vb vector<bool>
#define slli set<lli>
#define mii map<int, int>
#define mlli map<int, lli>
#define msi map<str, int>
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lli, lli>
#define vpii vector<pii >
#define vpll vector<pll >
#define pb push_back
#define loop(i, s, l, j) for(int i = s; i < l; i += j)
#define rloop(i, s, l, j) for(int i = s; i >= l; i -= j)
#define rep(i, n) loop(i,0,n,1)
#define rrep(i, n) rloop(i,n-1,0,1) 
#define fastio() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ft first
#define sd second
#define all(a) a.begin(),a.end()
#define rev(a) reverse(all(a))
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define mod 1000000007
#define inf 100000000
#define limit 200005
#define minval -100000000000000000
#define maxval 1000000000000000
/**********************************************************************************************************************************************/
int dx4[4] = {0, -1, 0, 1};
int dy4[4] = {1, 0, -1, 0};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int Power(int base,int exp){int ans=1;  while(exp > 0){if(exp&1)ans=(1LL*ans*base)%mod; exp=exp>>1; base=(1LL*base*base)%mod;}  return ans;}
/**********************************************************************************************************************************************/ 
void input()
{
    int n;
    cin >> n;
    vlli a(n);
    
    rep(i,n)
        cin >> a[i];

    lli s1 = 0;
    rep(i,n)
        s1 = (s1 + a[i])%mod;

    s1 = (s1 * s1)%mod;

    lli s2 = 0;
    rep(i,n)
        s2 = (s2 + (a[i] * a[i])%mod)%mod;
    
    lli ans = 0;
    ans = (s1 + (mod - s2))%mod;

    ans = (ans * Power(2, mod-2))%mod;
    cout << ans << '\n';
}
int main()
{
   /*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
   */
    fastio();
    int q = 1;
    //cin >> q;
    while(q--)
        input();
}
