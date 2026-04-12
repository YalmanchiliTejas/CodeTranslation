#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> Vec;

#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define rep(i, n) REP(i, 0, n)
const int INF=1e9;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define ALL(v) v.begin(), v.end()
#define dbg(x_) cerr << #x_ << ":" << x_ << endl;
#define pb(x) push_back(x)
#define sum(v) accumulate(ALL(v),0)

template<typename T1, typename T2>
ostream &operator<<(ostream &s, const pair<T1, T2> &p) { return s<<"("<<p.first<<", "<<p.second<<")"; }

// vector
template<typename T>
ostream &operator<<(ostream &s, const vector<T> &v) {
    int len=v.size();
    for(int i=0; i<len; ++i) {
        s<<v[i];
        if(i<len-1) s<<"	";
    }
    return s;
}

// 2 dimentional vector
template<typename T>
ostream &operator<<(ostream &s, const vector<vector<T> > &vv) {
    int len=vv.size();
    for(int i=0; i<len; ++i) {
        s<<vv[i]<<endl;
    }
    return s;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    Vec v(n);
    vector<ll> w;
    ll min=INF;
    rep(i,n){
        int tmp;
        cin>>tmp;
       // dbg(tmp);

        if(min>=tmp){
            w.pb(tmp);
            min = tmp;
        }else{
            rep(j,w.size()){
                if(tmp > w[j]){
                    w[j] = tmp;
                    if(j==w.size()-1){
                        min = tmp;
                    }
                    break;
                }
            }
        }
//        dbg(min);
//        dbg(w);
    }

    cout<<w.size()<<endl;
    return  0;
}
