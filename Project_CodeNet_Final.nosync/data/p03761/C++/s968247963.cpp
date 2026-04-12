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
#define MAX 510000
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;

ll h,w;

bool in(ll y, ll x){
    return 0<=y && y<h && 0<=x && x<w;
}

int main(){
    ll n; cin >> n;
    string s;
    ll cnt[n][26] = {};
    rep(i,n){
        cin >> s;
        rep(j,s.size()){
            cnt[i][s[j]-'a']++;
        }
    }
    vl mn(26,INF);
    rep(i,26){
        rep(j,n){
            mn[i] = min(mn[i], cnt[j][i]);
        }
    }
    rep(i,26){
        rep(j,mn[i]){
            cout << (char)(i+'a');
        }
    }
    cout << endl;
}