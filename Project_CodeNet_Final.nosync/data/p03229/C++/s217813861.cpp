
#include <bits/stdc++.h>
using namespace std;;
#define ll long long
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
int main(){
    int n; cin >> n;
    vector<ll> a;
    REP(i,n){
        ll t; cin >> t; a.push_back(t);
    }
    sort(a.begin(), a.end());
    auto be = a.begin();
    auto en = a.end()-1;
    ll f = *be;
    ll e = *en;
    ll ans = e - f;
    be++;
    en--;
    REP(i,n-2){
        ll fdel = max(abs(e-*be), abs(f-*be));
        ll edel = max(abs(e-*en), abs(f-*en));
        ans += max(fdel, edel);
        if(fdel>edel){
            if(abs(e-*be)>abs(f-*be)){
                e = *be;
            }else{
                f = *be;
            }
            be++;
        }else{
            if(abs(e-*en)<abs(f-*en)){
                f = *en;
            }else{
                e = *en;
            }
            en--;
        }
    }
    cout << ans << endl;


}