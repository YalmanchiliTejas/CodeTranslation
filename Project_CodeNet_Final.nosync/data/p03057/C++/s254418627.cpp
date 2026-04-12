#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }


template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) v += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr istream& operator >> (istream &is, Fp<MOD>& x) noexcept {
        return is >> x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};



// 二項係数ライブラリ
template<class T> struct BiCoef {
    vector<T> fact_, inv_, finv_;
    constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
        int MOD = fact_[0].getmod();
        for(int i = 2; i < n; i++){
            fact_[i] = fact_[i-1] * i;
            inv_[i] = -inv_[MOD%i] * (MOD/i);
            finv_[i] = finv_[i-1] * inv_[i];
        }
    }
    constexpr T com(int n, int k) const noexcept {
        if (n < k || n < 0 || k < 0) return 0;
        return fact_[n] * finv_[k] * finv_[n-k];
    }
    constexpr T fact(int n) const noexcept {
        if (n < 0) return 0;
        return fact_[n];
    }
    constexpr T inv(int n) const noexcept {
        if (n < 0) return 0;
        return inv_[n];
    }
    constexpr T finv(int n) const noexcept {
        if (n < 0) return 0;
        return finv_[n];
    }
};



const int MAX = 501010;
const int MOD = 1000000007;
using mint = Fp<MOD>;

int N, M;
string S;

mint solve() {
    BiCoef<mint> bc(MAX);
    if (S[0] == 'R') {
        for (auto &c : S) {
            if (c == 'R') c = 'B';
            else c = 'R';
        }
    }
    vector<int> nums;
    for (int i = 0; i < M;) {
        int j = i+1;
        while (j < M && S[j] == S[i]) ++j;
        nums.push_back(j-i);
        i = j;
    }
    if (nums.size() > 1 && N % 2 == 1) return 0;

    int minv = 1, maxv = N;
    if (nums.size() == 1) minv = 2, maxv = N;
    else {
        N /= 2;
        maxv = nums[0] / 2 + 1;
        for (int i = 0; i+1 < nums.size(); i += 2) {
            if (nums[i] & 1) maxv = min(maxv, (nums[i] + 1) / 2);
        }
    }
    //COUT(maxv); COUT(N);

    vector<mint> dp(N+1, 0), sdp(N+2, 0);
    dp[0] = 1, sdp[1] = 1;
    for (int i = 1; i <= N; ++i) {
        dp[i] = sdp[max(0, i + 1 - minv)] - sdp[max(0, i - maxv)];
        sdp[i+1] = sdp[i] + dp[i];

        //cout << i << ": " << dp[i] << endl;
    }
    mint res = 0;
    if (nums.size() == 1) {
        for (int r = minv; r <= min(maxv, N); ++r) res += dp[N-r] * r;
        res += 1; // all B
    }
    else {
        for (int r = minv; r <= min(maxv, N); ++r) res += dp[N-r] * r * 2;
    }
    return res;
}

int main() {     
    while (cin >> N >> M >> S) {
        cout << solve() << endl;
    }
}
