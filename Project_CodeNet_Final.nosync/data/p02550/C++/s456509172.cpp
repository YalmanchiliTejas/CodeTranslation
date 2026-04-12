#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const ll mod9 = 998244353;
const ll INF = 1001001001;
const ll LINF = 1001001001001001001;

void prvec(vector<ll> vec){
    ll n = vec.size();
    rep(i,n) cout << i << " " << vec.at(i) << "\n";
}

void pr2d(vector<vector<ll>> vvec){
    ll h = vvec.size();
    ll w = vvec.at(0).size();
    rep(i,h){
        rep(j,w){
            cout << vvec.at(i).at(j) << " ";
        }
        cout << "\n";
    }
}

int main(){
    ll n, x, m  ; cin >> n >> x >> m;
    ll a = x;
    vector<ll> lc(m,0);
    ll cur = 1;
    lc.at(a) = cur;
    bool no_loop = false;

    while(true){
        a = (a*a)%m;
        cur++;
        if(lc.at(a)==0) lc.at(a) = cur; else break;
        if(cur==n) break;
    }
    ll loop_start = lc.at(a);
    ll loop_length = cur - loop_start;

    ll nol=INF,stop=INF;
    if(loop_length){
        nol = (n-(loop_start-1))/loop_length; //number of laps(切り捨て)
        stop = (n-(loop_start-1))%loop_length; //最終周でいくつ進むか
    }else{
      	loop_start++;
    }

    ll ans = 0;
    rep(i,m){
        if(lc.at(i) == 0){
            continue;
        }else if(lc.at(i)<loop_start){
            ans += i;
        }else{
            if(lc.at(i)-loop_start<stop){
                ans += (nol+1)*i;
            }else{
                ans += nol*i;
            }
        }
        //cout << i << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}