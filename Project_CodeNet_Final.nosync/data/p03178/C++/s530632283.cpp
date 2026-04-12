#include <bits/stdc++.h>
using namespace std;

template <typename T> T load() { T r; cin >> r; return r; }
template <typename T> vector<T> loadMany(int n) { vector<T> rs(n); generate(rs.begin(), rs.end(), &load<T>); return rs; }

template <unsigned m> struct Mint {
    Mint():val(0){}
    Mint(int raw):val((raw%m+m)%m){}
    Mint(long long raw):val((raw%m+m)%m){}
    Mint(unsigned raw):val(raw%m){}
    Mint(unsigned long long raw):val(raw%m){}
    friend Mint operator+(Mint a, Mint b) { return a.val + b.val; }
    friend Mint operator-(Mint a, Mint b) { return m + a.val - b.val; }
    friend Mint operator*(Mint a, Mint b) { return 1ll * a.val * b.val; }
    friend Mint operator/(Mint a, Mint b) { return a * qpow(b, m-2); }
    friend Mint& operator+=(Mint& a, Mint b) { return a = a + b; }
    friend Mint& operator-=(Mint& a, Mint b) { return a = a - b; }
    friend Mint& operator*=(Mint& a, Mint b) { return a = a * b; }
    friend Mint& operator/=(Mint& a, Mint b) { return a = a / b; }
    friend bool operator==(Mint a, Mint b) { return a.val == b.val; }
    friend bool operator!=(Mint a, Mint b) { return a.val != b.val; }
    friend ostream& operator<<(ostream& out, Mint x) { return out << x.val; }
    unsigned val;
};

using M = Mint<1'000'000'000 + 7>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto k = load<string>();
    auto d = load<int>();
    
    auto dyn = vector<vector<M>>(k.size()+1, vector<M>(d, 0));
    dyn[0][0] = 1;
    for (auto i=0; i<(int)k.size(); ++i)
        for (auto r=0; r<d; ++r)
            for (auto c=0; c<10; ++c)
                dyn[i+1][(r+c)%d] += dyn[i][r];

    auto prefr = 0;
    auto total = M(0);
    for (auto i=(int)k.size()-1; i>=0; --i) {
        auto c = k[((int)k.size()-1)-i] - '0';
        for (auto ci = i == (int)k.size()-1 ? 1 : 0; ci<c; ++ci) {
            auto prefir = (prefr + ci) % d;
            total += dyn[i][(d - prefir)%d];
            clog << "A i=" << i << " ci=" << ci << " -> " << dyn[i][(d - prefir)%d] << endl;
        }
        if (i != (int)k.size()-1) {
            for (auto c0=1; c0<10; ++c0) {
                total += dyn[i][(d - c0%d)%d];
                clog << "B i=" << i << " c0=" << c0 << " -> " << dyn[i][(d - c0%d)%d] << endl;
            }
        }
        prefr = (prefr + c) % d;
    }
    if (prefr == 0)
        total += 1;
    cout << total << '\n';
}
