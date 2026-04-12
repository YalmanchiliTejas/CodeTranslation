#include<bits/stdc++.h>
using namespace std;
#define ld float
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
#define mod 998244353
#define inf 2000000000
#define limit 200005
#define minval -100000000000000000
#define maxval 1000000000000000
int dx4[4] = {0, -1, 0, 1};
int dy4[4] = {1, 0, -1, 0};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int Power(int base,int exp){int ans=1;  while(exp > 0){if(exp&1)ans=(1LL*ans*base)%mod; exp=exp>>1; base=(1LL*base*base)%mod;}  return ans;}

void solve(int test_case)
{
    lli n, x, m;
    cin >> n >> x >> m;

    lli i = 1, tmp = x;
    vlli a;
    vlli fre(m, 0);
    while(i < 50000000)
    {
        if(fre[tmp] == 1)
            break;
        fre[tmp]++;
        a.pb(tmp);
        tmp = (tmp * tmp)%m;
        i++;
    }

    i = 0;
    lli ans = 0;
    while(a[i] != tmp)
    {
        ans += a[i];
        i++;
    }
    
    lli s = 0;
    loop(j,i,(int)a.size(),1)
        s += a[j];
    
    i++;
    lli l = (int)a.size()-i+1;
    lli k = (n-i)/l;
    ans += s * k;

    lli cnt = n - (i + k * l) + 1;
    loop(j,i-1,i-1+cnt,1)
        ans += a[j];
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
    rep(i,q)
        solve(i+1);
}
