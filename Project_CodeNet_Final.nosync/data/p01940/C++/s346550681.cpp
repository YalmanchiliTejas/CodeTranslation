#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)
#define all(v) v.begin(), v.end()
#define rall(x) (x).rbegin(), (x).rend()
#define pll pair<long long, long long>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define vc vector<char>
#define vvc vector<vc>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<long long>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;
template <class T>bool chmax(T &a, const T &b){if (a < b){a = b;return 1;}return 0;}
template <class T>bool chmin(T &a, const T &b){if (b < a){a = b;return 1;}return 0;}
//snippets:tmp,cl,cvl,cs,co,coy,con,cov,setp
const ll mod=1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string t;
    cin >> t;
    string p;
    cin >> p;
    ll pkey=0;
    ll count=0;
    rep(i,t.size()){
        if(pkey!=p.size()-1&&t[i]==p[pkey]){
            pkey++;
        }
        else if(pkey!=0){
            if(t[i]==p[pkey-1]){
                cout<<"no"<<endl;
                return 0;
            }
        }
    }
    if(pkey==p.size()-1)cout << "yes" << endl;
    else cout << "no" << endl;
}
