#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define MOD 1000000007
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define RREP(i,a,b) for(ll i=(a); i>=(b); i--)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> p;
typedef vector<pair<ll, ll>> vpl;

int main(){
    ll n; cin >> n;
    vl h(n);
    ll M = 0;
    ll cnt = 0;
    rep(i,n){
        cin >> h[i];
        if(h[i] >= M){
            cnt++;
            M = h[i];
        }
    }
    cout << cnt << "\n";
}