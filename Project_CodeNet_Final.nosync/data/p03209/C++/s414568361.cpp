#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}
bool cmp(int a,int b){return a>b;}

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;
const int N = 5e5 + 10;
vector<ll>a(55);
vector<ll>p(55);
ll dfs(ll n,ll k){
   if(n==0) return 1;
   else if(k<=n) return 0;
   else if(k<=a[n-1]+1) return dfs(n-1,k-1);
   else if(k==a[n-1]+2) return p[n-1]+1;
   else return p[n-1]+dfs(n-1,k-a[n-1]-2)+1;
}

void solve(){
     ll n,k;cin >> n >> k;
     a[0] = 1;p[0] = 1;
     for(int i = 1;i<=n;i++){
        a[i] = a[i-1]*2+3;
        p[i] = p[i-1]*2+1;
     }
     cout << dfs(n,k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}