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
#define ford(i, a, b) for (int i = (int)(a); i >= b; --i)
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

const int N = 2e5+77;
//const ll mod = 1e9+7;

int n,p[N];
pair<pii,int> xy[N];
priority_queue<pair<int,pii>> q;

int root(int x){
    while(x!=p[x]) p[x]=p[p[x]], x=p[x];
    return x;
}

int main(){
    fast;
    cin>>n;
    forn(i,n){
        p[i]=i;
        cin>>xy[i].first.first>>xy[i].first.second;
        xy[i].second=i;
    }
    sort(xy,xy+n);
    forn(i,n-1){
        q.push({-(xy[i+1].first.first-xy[i].first.first),{xy[i].second,xy[i+1].second}});
    }
    
    forn(i,n) swap(xy[i].first.first,xy[i].first.second);
    
    sort(xy,xy+n);
    forn(i,n-1){
        q.push({-(xy[i+1].first.first-xy[i].first.first),{xy[i].second,xy[i+1].second}});
    }
    ll ans=0;
    while(q.size()){
        auto zz = q.top();
        q.pop();
        int x = root(zz.second.first);
        int y = root(zz.second.second);
        if(x==y) continue;
        p[x] = y;
        ans+=-zz.first;
    }
    cout<<ans<<endl;
    return 0;
}