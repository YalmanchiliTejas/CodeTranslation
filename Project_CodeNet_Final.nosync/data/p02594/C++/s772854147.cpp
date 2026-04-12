#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

#define int long long

#define override_rep(i, l, r, mes, ...) mes
#define rep1(i, n) for (int i = 0; i < n; i++)
#define rep2(i, l, r) for (int i = l; i < r; i++)
#define rep(...) override_rep(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)

using namespace std;
using P = pair<int, int>;
using ll = long long;
using ld = double;

using bint = boost::multiprecision::cpp_int;

constexpr int MOD = 1e9 + 7;

template<typename T, typename U>
istream& operator>>(istream& in, pair<T, U>& p) {
    in >> p.first >> p.second;
    return in;
}

// https://twitter.com/vane11ope ←フォローしましょう
// (ノ)>◡<(ヾ)ﾓﾁﾓﾁ
signed main(signed argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int x;
    cin>>x;
    if(30<=x)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
