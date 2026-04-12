#include<bits/stdc++.h>
using namespace std;

#define lint long long
#define P pair<int, int>
#define LLP pair<long long, long long>
#define REP(i, x, n) for(int i = (x), i##_len = int(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = int(n) ; i < i##_len ; ++i)
#define reps(i, n) for(int i = 1, i##_len = int(n) ; i <= i##_len ; ++i)
#define rrep(i, n) for(int i = int(n) - 1 ; i >= 0 ; --i)
#define rreps(i, n) for(int i = int(n) ; i > 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())

const int IINF = (1 << 30) - 1;
const long long LLINF = 1LL << 61;
const long long MOD = 1000000007LL;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

template<uint_fast64_t modulus>
class modInt{
    using u64 = uint_fast64_t;

private:
    u64 num;

    u64 _power(u64 _x, u64 _n){
        u64 res = 1;
        while(_n > 0){
            if(_n & 1){
                res = res * _x % modulus;
            }
            _x = _x * _x % modulus;
            _n >>= 1;
        }
        return res;
    }

public:
    modInt(){
        num = 0;
    }

    modInt(u64 x){
        num = x % modulus;
    }

    u64 get(void){
        return num;
    }

    void print(void){
        cout << num << endl;
        return;
    }

    void print(char c){
        cout << num << c;
    }

    modInt &operator+=(const modInt &rhs){
        num += rhs.num;
        if(num >= modulus){
            num -= modulus;
        }
        return *this;
    }

    modInt &operator-=(const modInt &rhs){
        if(num < rhs.num){
            num += modulus;
        }
        num -= rhs.num;
        return *this;
    }

    modInt &operator*=(const modInt &rhs){
        num = num * rhs.num % modulus;
        return *this;
    }

    modInt &operator/=(const modInt &rhs){
        num = num * _power(rhs.num, modulus - 2) % modulus;
        return *this;
    }

    modInt operator+(const modInt &rhs){
        return modInt(*this) += rhs;
    }

    modInt operator-(const modInt &rhs){
        return modInt(*this) -= rhs;
    }

    modInt operator*(const modInt &rhs){
        return modInt(*this) *= rhs;
    }

    modInt operator/(const modInt &rhs){
        return modInt(*this) /= rhs;
    }
};

using mint = modInt<MOD>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    lint n, m, k;
    cin >> n >> m >> k;

    vector<mint> fact(n * m + 1), inv_fact(n * m + 1);
    fact[0] = 1;
    inv_fact[0] = 1;
    reps(i, n * m){
        fact[i] = fact[i - 1] * mint(i);
        inv_fact[i] = inv_fact[i - 1] / mint(i);
    }

    mint ans = 0;
    rep(i, n + 1){
        ans += fact[n * m - 2] * inv_fact[k - 2] * inv_fact[n * m - 2 - k + 2] * mint(i) * mint(n - i) * mint(m) * mint(m);
    }

    rep(i, m + 1){
        ans += fact[n * m - 2] * inv_fact[k - 2] * inv_fact[n * m - 2 - k + 2] * mint(i) * mint(m - i) * mint(n) * mint(n);
    }

    ans.print();

    return 0;
}