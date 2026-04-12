#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;
#define MOD 1000000007
#define MAX 510000
#define INF 1<<30
#define LINF (ll)1<<62
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;



int main(){
    ll a,b,c,x,y; cin >> a >> b >> c >> x >> y;
    ll ans = 0;
    if(a+b>2*c){
        ll mn = min(x,y);
        ans += 2 * mn * c;
        x -= mn;
        y -= mn;
        if(x>0){
            ans += x * min(a,2*c);
        }else{
            ans += y * min(b,2*c);
        }
    }else{
        ans = a*x + b*y;
    }
    cout << ans << endl;
}