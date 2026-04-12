#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

template<const long long MOD>
class Modint{
    public:
        Modint() : x(0) {

        }

        Modint(long long y) : x((y % MOD + MOD) % MOD) {

        }

        Modint& operator+=(const Modint& p){
            if((x += p.x) >= MOD) x -= MOD;
            return *this;
        }

        Modint& operator-=(const Modint& p){
            if((x += MOD - p.x) >= MOD) x -= MOD;
            return *this;
        }

        Modint& operator*=(const Modint& p){
            x = x * p.x % MOD;
            return *this;
        }

        Modint& operator/=(const Modint& p){
            *this *= p.inverse();
            return *this;
        }

        Modint operator-() const {
            return Modint(-x);
        }

        Modint operator+(const Modint& p) const {
            return Modint(*this) += p;
        }

        Modint operator-(const Modint& p) const {
            return Modint(*this) -= p;
        }

        Modint operator*(const Modint& p) const {
            return Modint(*this) *= p;
        }

        Modint operator/(const Modint& p) const {
            return Modint(*this) /= p;
        }

        bool operator==(const Modint& p) const {
            return x == p.x;
        }

        bool operator!=(const Modint& p) const {
            return !(*this == p);
        }

        bool operator<(const Modint& p) const {
            return x < p.x;
        }

        bool operator>(const Modint& p) const {
            return x > p.x;
        }

        bool operator<=(const Modint& p) const {
            return !(*this > p);
        }

        bool operator>=(const Modint& p) const {
            return !(*this < p);
        }

        Modint inverse() const {
            long long a = x, b = MOD, u = 1, v = 0;
            while(b > 0){
                long long t = a / b;
                a -= t * b;
                swap(a, b);
                u -= t * v;
                swap(u, v);
            }
            return Modint(u);
        }

        Modint pow(long long n) const {
            Modint ret(1), mul(x);
            while(n > 0){
                if(n & 1) ret *= mul;
                mul *= mul;
                n >>= 1;
            }
            return ret;
        }

        friend ostream &operator<<(ostream& os, const Modint& p){
            return os << p.x;
        }

        friend istream &operator>>(istream& is, Modint& a){
            long long t;
            cin >> t;
            a = Modint<MOD>(t);
            return is;
        }

        explicit operator long long() const {
            return x;
        }

        static long long get_mod(){
            return MOD;
        }

    private:
        long long x;
};

using mint = Modint<MOD>;
ll N;
mint A[200010];

signed main(){
    cin >> N;
    REP(i, N) cin >> A[i];
    mint sum(0);
    REP(i, N) sum += A[i];
    mint ans(0);
    REP(i, N) ans += A[i] * (sum - A[i]);
    PRINT(ans * mint(2).inverse());
    return 0;
}