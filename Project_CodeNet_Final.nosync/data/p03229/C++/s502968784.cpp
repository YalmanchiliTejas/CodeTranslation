#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define MOD 1000000007LL

#define rep(i, n) for(ll (i) = 0LL;(i) < (ll)(n);(i)++)
#define rep2(i, s, e) for(ll (i) = (ll)(s);(i) < (ll)(e);(i)++)
#define repi(i, n) for(ll (i) = 0LL;(i) <= (ll)(n);(i)++)
#define repi2(i, s, e) for(ll (i) = (ll)(s);(i) <= (ll)(e);(i)++)
#define per(i, n) for(ll (i) = (ll)(n) - 1LL;(i) >= 0LL;(i)--)
#define per2(i, s, e) for(ll (i) = (ll)(s) - 1LL;(i) >= (ll)(e);(i)--)
#define peri(i, n) for(ll (i) = (ll)(n);(i) >= 0LL;(i)--)
#define peri2(i, s, e) for(ll (i) = (ll)(s);(i) >= (ll)(e);(i)--)
#define iter(i, it) for(auto &(i): (it))

template<typename T, typename U> ostream& operator<<(ostream &s, const pair<T, U> m) {
    cout << "(" << m.first << ", " << m.second << ")";
    return s;
}
template<typename T, typename U> ostream& operator<<(ostream &s, const map<T, U> m) {
    ll c = 0;
    cout << "{ ";
    iter(i, m) cout << i << (c++ == m.size() - 1 ? " " : ", ");
    cout << "}";
    return s;
}
template<typename T> ostream& operator<<(ostream &s, const vector<T> &v) {
    cout << "{ ";
    rep(i, v.size()) cout << v[i] << (i == v.size() - 1 ? " " : ", ");
    cout << "}";
    return s;
}
template<typename T> ostream& operator<<(ostream &s, const list<T> &v) {
    ll c = 0;
    cout << "{ ";
    iter(i, v) cout << i << (c++ == v.size() - 1 ? " " : ", ");
    cout << "}";
    return s;
}

int main(void) {
    ll N;
    cin >> N;
    list<ll> A;
    rep(i, N) {
        ll temp;
        cin >> temp;
        A.push_back(temp);
    }
    A.sort();
    ll ANS = 0;
    {
        ll ans = 0;
        list<ll> B, temp;
        temp = A;
        rep(i, N) {
            if(i % 2 == 0) B.push_back(temp.back()), temp.pop_back();
            else B.push_back(temp.front()), temp.pop_front();
        }
        if(abs(B.back() - B.front()) > abs(*----B.end() - B.back())) B.push_front(B.back()), B.pop_back();
        vector<ll> C(B.begin(), B.end());
        rep(i, N - 1) ans += abs(C[i + 1] - C[i]);
        ANS = ans;
    }
    {
        ll ans = 0;
        list<ll> B, temp;
        temp = A;
        rep(i, N) {
            if(i % 2) B.push_back(temp.back()), temp.pop_back();
            else B.push_back(temp.front()), temp.pop_front();
        }
        if(abs(B.back() - B.front()) > abs(*----B.end() - B.back())) B.push_front(B.back()), B.pop_back();
        vector<ll> C(B.begin(), B.end());
        rep(i, N - 1) ans += abs(C[i + 1] - C[i]);
        if(ANS < ans) ANS = ans;
    }
    cout << ANS << endl;
    return 0;
}
