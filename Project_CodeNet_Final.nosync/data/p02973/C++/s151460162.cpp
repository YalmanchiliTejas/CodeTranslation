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
    vl a(n);
    multiset<ll> se;
    rep(i,n){
        cin >> a[i]; 
        a[i] = -a[i];
        if(se.upper_bound(a[i]) == se.end()){
            se.insert(a[i]);
            //cout << "#" << endl;
        }else{
            auto it = se.upper_bound(a[i]);
            se.erase(it);
            //cout << ((*it));
            se.insert(a[i]);
            /*for(auto it = se.begin(); it != se.end(); it++){
                cout << (*it) << " ";
            }
            cout << endl;*/
        }
    } 
    cout << se.size() << endl;
}