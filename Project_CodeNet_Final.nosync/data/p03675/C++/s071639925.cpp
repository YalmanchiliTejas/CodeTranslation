#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <climits>
#include <iomanip>
#include <string.h>
#include <algorithm>

using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n); i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define clr(a,b) memset((a),b,sizeof(a))
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define tr(container, it) \
for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define sz(a) int((a).size())
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N = (int)2e5+77;

ll n, m, k, x, y;
ll a[N];
int main() {
    fast;
    cin>>n;
    forn(i,n) cin>>a[i];
    ll i;
    for(i=n-1;i>=0;i-=2){
        cout<<a[i]<<" ";
    }
    if(n&1) i=1;
    else i=0;
    for(;i<n-1;i+=2){
        cout<<a[i]<<" ";
    }
    return 0;
}