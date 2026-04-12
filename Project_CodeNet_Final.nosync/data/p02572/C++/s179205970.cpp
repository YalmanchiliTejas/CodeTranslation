#include <bits/stdc++.h>

#define ll long long
#define ld long double

#define rep(i, n) for(ll i = 0; i < n; ++i)
#define rep2(i, a, b) for(ll i = a; i <= b; ++i)
#define rrep(i, a, b) for(ll i = a; i >= b; --i)

#define pii pair<int, int>
#define pll pair<ll, ll>

#define fi first
#define se second

#define pb push_back
#define eb emplace_back

#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define all(a) a.begin(), a.end()

#define endl '\n'
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
  
const ll MOD=1e9+7;
const ll INF=1e18;
const double PI=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
 
const int MAX=1000010;
template<uint_fast64_t Modulus>
struct modint {
    using u64 = uint_fast64_t;
    u64 a;
    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
    constexpr u64& value() noexcept { return a; }
    constexpr const u64& value() const noexcept { return a; }
    constexpr modint operator+(const modint rhs) const noexcept {
        return modint(*this) += rhs;
    }
    constexpr modint operator-(const modint rhs) const noexcept {
        return modint(*this) -= rhs;
    }
    constexpr modint operator*(const modint rhs) const noexcept {
        return modint(*this) *= rhs;
    }
    constexpr modint operator/(const modint rhs) const noexcept {
        return modint(*this) /= rhs;
    }
    constexpr modint& operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) a -= Modulus;
        return *this;
    }
    constexpr modint& operator-=(const modint rhs) noexcept {
        if (a < rhs.a) a += Modulus;
        a -= rhs.a;
        return *this;
    }
    constexpr modint& operator*=(const modint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr modint& operator/=(modint rhs) noexcept {
        return *this *= rhs.inv();
    }
    constexpr modint& operator++() noexcept {
        a++;
        if (a == Modulus) a = 0;
        return *this;
    }
    constexpr modint operator++(int) noexcept {
        modint tmp(*this);
        operator++();
        return tmp;
    }
    constexpr modint& operator--() noexcept {
        if (a == 0) a = Modulus;
        a--;
        return *this;
    }
    constexpr modint operator--(int) noexcept {
        modint tmp(*this);
        operator--();
        return tmp;
    }
    constexpr modint pow(u64 exp) const noexcept {
        modint res(1), mul(*this);
        for (; exp; mul *= mul, exp >>= 1) if (exp & 1) res *= mul;
        return res;
    }
    constexpr modint inv() const noexcept {
        return modint(*this).pow(Modulus - 2);
    }
    constexpr bool operator==(modint rhs) const noexcept { return a == rhs.a; }
    constexpr bool operator!=(modint rhs) const noexcept { return a != rhs.a; }
    friend ostream& operator<<(ostream& os, const modint<Modulus>& rhs) { return os << rhs.a; }
};

using mint = modint<1000000007>;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
   
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  
  ll sum = 0;
  rep(i,n) sum += a[i];
  
  mint ans = 0;
  rep(i,n){
    ans += mint(sum-a[i])*a[i];
  }
  ans/=2;
  cout << ans << endl;
  return 0;
}
