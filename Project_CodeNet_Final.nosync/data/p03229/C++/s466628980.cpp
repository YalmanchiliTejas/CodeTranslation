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
#define LINF 1LL<<62
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
const int mod = 1e9 + 7;

int main(){
    ll n; cin >> n;
    vl a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    vl ans(n);
    if(n%2==1){
        ll index;
        if(a[n/2]-a[n/2-1] <= a[n/2+1]-a[n/2]) index = 1;
        else index = 0;
        rep(i,n/2){
            ans[index] = a[n/2+i+1];
            ans[index+1] = a[i];
            index += 2;
        }
        if(index==n) ans[0] = a[n/2];
        else ans[n-1] = a[n/2];
    }else{
        ll index = 0;
        rep(i,n/2){
            ans[index] = a[n/2+i];
            ans[index+1] = a[i];
            index += 2;
        }
    }
    ll sum = 0;
    rep(i,n-1){
        sum += abs(ans[i+1]-ans[i]);
    }
    cout << sum << endl;
}