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
#define uni(q) unique(all(q)),q.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;



int main(){
    ll h,w;
    cin >> h >> w;
    char s[h][w];
    ll cnt = 0;
    rep(i,h){
        rep(j,w){
            cin >> s[i][j];
            if(s[i][j] == '#'){
                cnt++;
            }
        }
    }
    if(cnt == h+w-1) puts("Possible");
    else puts("Impossible");
}
