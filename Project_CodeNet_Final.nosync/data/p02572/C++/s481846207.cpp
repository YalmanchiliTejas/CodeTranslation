#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <queue>
#include <set>

#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define PI 3.141592653589
#define MOD 1000000007

using namespace std;

template<typename T> T gcd(T a, T b){return (a % b)? gcd(b, a % b) : b;}
template<typename T> T lcm(T a, T b){return a * b / gcd(a, b);}

int mod = 1000000007;
struct mint{
    ll x;
    //コンストラクタ
    mint(ll x=0):x((x%mod+mod)%mod){}

    // %は若干遅いから，%を使わないようにしている
    mint& operator+=(const mint a){
        if((x += a.x) >= mod) x-= mod;
        return *this;
    }

    mint& operator-=(const mint a){
        if((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a){
        (x *= a.x) %= mod;
        return *this;
    }
    
    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }

    mint power(ll t) const { // x^t
        if(!t) return 1;
        mint ans = power(t >> 1);
        ans *= ans;
        if(t&1) ans *= *this;
        return ans;
    }

    //素数が絡むやつ
    mint inv() const{
        return power(mod-2);
    }
    mint& operator/=(const mint a){
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const{
        mint res(*this);
        return res /= a;
    }
};

istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}


int main(void){
    int n;
    cin >> n;
    int a[n];
    mint sum = 0;
    REP(i,n){
        cin >> a[i];
        sum += a[i];
    }

    mint ans = 0;
    REP(i,n){
        sum -= a[i];
        mint b(a[i]);
        ans += b * sum;
    }
    cout << ans << endl;
    
    return 0;
}