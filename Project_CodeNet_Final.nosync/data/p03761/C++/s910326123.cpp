#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using P = pair<ll, ll>;

// chmin, chmax関数
template<typename T, typename U, typename Comp=less<>>
bool chmax(T& xmax, const U& x, Comp comp={}) {
    if(comp(xmax, x)) {
        xmax = x;
        return true;
    }
    return false;
}
template<typename T, typename U, typename Comp=less<>>
bool chmin(T& xmin, const U& x, Comp comp={}) {
    if(comp(x, xmin)) {
        xmin = x;
        return true;
    }
    return false;
}

//---------------------------

int main(){
    ll n;
    cin >> n;
    VL alph(28,55);
    rep(i,n){
        string s;
        cin >> s;
        VL temp(28,0);
        rep(j,s.size()){
            temp[s[j]-'a']++;
        }
        rep(j,28){
            chmin(alph[j], temp[j]);
        }
    }

    rep(i,28){
        int c = alph[i];
        char x = 'a' + i;
        rep(j,c){
            cout << x;
        }
    }

    cout << endl;

    return 0;
}