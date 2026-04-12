#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define MOD 1000000007
#define INF 1<<30
#define LINF (ll)1<<62
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
    ll n; cin >> n;
    vl s(n);
    rep(i,n) cin >> s[i];
    ll mx = 0;
    for(ll c=1; c<=n-1; c++){
        ll l=0, r=n-1;
        ll sum = 0;
        if((n-1) % c == 0){
            ll tmp = 0;
            while(l < r){
                sum += s[l] + s[r];
                tmp = max(tmp, sum);
                l += c; r -= c;
            }
            mx = max(mx, tmp);
        }else{
            ll tmp = 0;
            while(r > c){
                sum += s[l] + s[r];
                tmp = max(tmp, sum);
                l += c; r -= c;
            }
            mx = max(mx, tmp);
        }
    }
    cout << mx << endl;
}
