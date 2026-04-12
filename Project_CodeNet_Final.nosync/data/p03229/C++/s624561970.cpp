#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))


int main(){
    int n;  cin >> n;
    vector<ll> a(n);
    REP(i, n) cin >> a.at(i);
    sort(ALL(a));

    deque<ll> ori, out;

    REP(i, n) ori.push_back(a[i]);
    out.push_back(ori.front());
    ori.pop_front();
 
    while(!ori.empty()){
        ll fv=out.front(), bv=out.back();
        ll frontx = max(abs(fv-ori.front()), abs(bv-ori.front()));
        ll backx = max(abs(fv-ori.back()), abs(bv-ori.back()));
        if(backx<frontx){
            if(abs(bv-ori.front())<abs(fv-ori.front())) out.push_front(ori.front());
            else out.push_back(ori.front());
            ori.pop_front();
        }else{
            if(abs(bv-ori.back())<abs(fv-ori.back())) out.push_front(ori.back());
            else out.push_back(ori.back());
            ori.pop_back();
        }
        
    }
    ll ans=0, x=out.front();
    out.pop_front();
    if(out.empty()) ans=x;
    while(!out.empty()){
        ans += abs(x-out.front());
        x = out.front();
        out.pop_front();
    }
    

    cout << ans << endl;


}