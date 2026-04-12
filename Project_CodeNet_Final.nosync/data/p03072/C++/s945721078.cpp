#include "bits/stdc++.h"
using namespace std;


typedef long long ll;
    typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef pair<ll, ll> pll;
typedef pair<double, int> pdi;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

#define iINF (1<<30)
#define INF (1LL<<59)
#define forn(i) for(int i = 0;i < n; ++i)
#define form(i,n) for(int i = 0 ;i < n; ++i)
#define NIL -1

const ll mod = 998244353;
ll n;
ll m;
ll ans;
string str;

int main(){
    ll h, max_h=0LL;
    cin>>n;
    ans=0LL;
    forn(i){
        cin>>h;
        if(h>=max_h){
            max_h=h;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}