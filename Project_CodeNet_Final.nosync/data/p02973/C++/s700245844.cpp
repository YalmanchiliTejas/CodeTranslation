#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const ll INF = 1001001001;
const ll LINF = 1001001001001001001;

void prvec(vector<ll> vec){
    ll n = vec.size();
    rep(i,n) cout << "i" << " " << vec.at(i) << "\n";
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
    ll n ; cin >> n;
    deque<ll> a;
    rep(i,n){
        ll x; cin >> x;
        auto it = lower_bound(a.begin(),a.end(),x);
        if(it==a.begin()){
            a.push_front(x);
        }else{
            ll y = it-a.begin();
            a.at(y-1) = x;
        }
    }
    cout << a.size() << endl;
}