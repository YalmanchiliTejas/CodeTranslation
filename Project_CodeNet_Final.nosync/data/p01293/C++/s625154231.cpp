#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define each(i,a) for (auto&& i : a)
#define FOR(i,a,b) for (ll i=(a),__last_##i=(b);i<__last_##i;i++)
#define RFOR(i,a,b) for (ll i=(b)-1,__last_##i=(a);i>=__last_##i;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define __GET_MACRO3(_1, _2, _3, NAME, ...) NAME
#define rep(...) __GET_MACRO3(__VA_ARGS__, FOR, REP)(__VA_ARGS__)
#define rrep(...) __GET_MACRO3(__VA_ARGS__, RFOR, RREP)(__VA_ARGS__)
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define chmin(x,v) x = min(x, v)
#define chmax(x,v) x = max(x, v)

const ll linf = 1e18;
const int inf = 1e9;
const double eps = 1e-12;
const double pi = acos(-1);

template<typename T>
istream& operator>>(istream& is, vector<T>& vec) {
    each(x,vec) is >> x;
    return is;
}
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    rep(i,vec.size()) {
        if (i) os << " ";
        os << vec[i];
    }
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, const vector< vector<T> >& vec) {
    rep(i,vec.size()) {
        if (i) os << endl;
        os << vec[i];
    }
    return os;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string T;
    string pwstr = "23456789TJQKA";
    map<char, ll> pw;
    rep(i, pwstr.size()) pw[pwstr[i]] = i;
    while (cin >> T, T != "#") {
        char M = T[0];
        vector<vector<string>> cards(4, vector<string>(13)); cin >> cards;
        ll led = 0;
        ll trick[2] = {0, 0};
        string name[2] = {"NS", "EW"};
        rep(i, 13) {
            char L = cards[led][i][1];
            vector<P> v;
            rep(j, 4) {
                ll power = pw[cards[j][i][0]];
                char suit = cards[j][i][1];
                if (suit == M) power += 1000;
                else if (suit == L) power += 100;
                v.pb({power, j});
            }
            ll win = max_element(all(v))->second;
            led = win;
            trick[win%2]++;
        }
        ll winner = trick[0] > trick[1] ? 0 : 1;
        cout << name[winner] << " " << trick[winner]-6 << endl;
    }
}