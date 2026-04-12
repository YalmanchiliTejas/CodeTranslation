#include <bits/stdc++.h>
using namespace std;
typedef bool boool;
typedef long long ll;
#define vl vector<ll>
#define vb vector<boool>
#define vs vector<string>
#define vp vector<pair<ll, ll>>
#define vvl vector<vector<ll>>
#define vvp vector<vector<pair<ll, ll>>>
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define rep1(i, n) for (long long i=0; i<(long long)(n); i++)
#define rep2(i, s, e) for (long long i=(s); i<(long long)(e); i++)
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    vl vec;
    vb flags(m, false);
    ll last;
    while(!flags[x]){
        if(x == 0){
            ll ans = 0;
            rep(i, min(n, (ll)vec.size())){
                ans += vec[i];
            }
            cout << ans << endl;
            return 0;
        }
        if(x == 1){
            ll ans = 0;
            rep(i, (ll)vec.size()){
                ans += vec[i];
            }
            ans += n-vec.size();
            cout << ans << endl;
            return 0;
        }
        vec.push_back(x);
        flags[x] = true;
        x = (x*x)%m;
        last = x;
    }
    vl vec2;
    bool isok = false;
    rep(i, vec.size()){
        if(isok) vec2.push_back(vec[i]);
        else{
            if(vec[i] == last){
                isok = true;
                vec2.push_back(vec[i]);
            }
        }
    }
    ll notIterableLength = vec.size()-vec2.size();
    ll iterableLength = vec2.size();
    if(notIterableLength>=n){
        ll ans = 0;
        rep(i, n){
            ans += vec[i];
        }
        cout << ans << endl;
    }else{
        ll sum = 0;
        rep(i, vec2.size()){
            sum += vec2[i];
        }
        ll ans = 0;
        rep(i, notIterableLength){
            ans += vec[i];
        }
        ll shou = (n-notIterableLength) / vec2.size();
        ans += sum*shou;
        rep(i, (n-notIterableLength)%vec2.size()){
            ans += vec2[i];
        }
        cout << ans << endl;
    }
    

    
    return 0;
}