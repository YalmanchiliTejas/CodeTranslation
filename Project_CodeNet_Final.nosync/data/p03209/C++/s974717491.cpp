#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;
#define MOD 1000000007
#define INF 1<<30
#define LINF (ll)1<<62
#define MAX 5100
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;



int main(){
    ll n,x; cin >> n >> x;
    vl v(n+1), p(n+1);
    v[0] = 1;
    p[0] = 1;
    rep(i,n){
        v[i+1] = v[i] * 2 + 3;
        p[i+1] = p[i] * 2 + 1;
    }
    ll ans = 0;
    for(ll i=n; i>=0; i--){
        while(x >= v[i]){
            x -= v[i];
            ans += p[i];
            if(x>=1){
                ans++; x--;
            }
        }
        if(x == 0) break;
        x--;
    }
    printf("%lld\n",ans);
}