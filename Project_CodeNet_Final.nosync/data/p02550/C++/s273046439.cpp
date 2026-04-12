#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long ,long long>pll;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}
ll lcm(ll a, ll b) {return ((a*b)/gcd(a,b));}
bool cmp(int a,int b){return a>b;}

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;

 long long modpow(long long n, long long k,long long mod)
{
if (k == 0) return 1;
long long r = modpow(n * n % mod, k >> 1, mod);
if (k & 1) r = r * n % mod;
return r;
}

void solve(){
    ll n,x,m;cin >> n >> x >> m;
    ll ans = 0,cnt = 1,sum = 0,pos1 = 0,pos2 = 0;
    vector<ll>a;
    vector<ll>b(m,0);
    while(true){
        if(b[x%m]==0){
            b[x%m] = cnt;
            a.push_back(x%m);
            ans += (x%m);
        }
        else{
            pos1 = b[x%m];
            pos2 = cnt;
            break;
        }
        if(cnt==n){
            cout << ans;
            return;
        }
        x = (x%m)*(x%m);
        cnt++;
    }
    ans = 0;
    for(int i = 0;i<pos1-1;i++) ans += a[i];
    for(int i = pos1-1;i<pos2;i++) sum += a[i];
    ans += ((n-pos1+1)/(pos2-pos1))*sum;
    ll tp = (n-pos1+1)%(pos2-pos1);
    for(int i = pos1-1;i<pos1+tp-1;i++)
        ans += a[i];
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}