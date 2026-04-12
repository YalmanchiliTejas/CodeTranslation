#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
#include <memory>
#include <regex>
using namespace std;

template <class T1>
class Operators
{
public:
    template <class T2>
    const T1 operator+(const T2& right) const{
        T1 ans = static_cast<const T1&>( *this );
        return ans += right;
    }
    template <class T2>
    const T1 operator-(const T2& right) const{
        T1 ans = static_cast<const T1&>( *this );
        return ans -= right;
    }
    template <class T2>
    const T1 operator*(const T2& right) const{
        T1 ans = static_cast<const T1&>( *this );
        return ans *= right;
    }
    template <class T2>
    const T1 operator/(const T2& right) const{
        T1 ans = static_cast<const T1&>( *this );
        return ans /= right;
    }
    template <class T2>
    const T1 operator%(const T2& right) const{
        T1 ans = static_cast<const T1&>( *this );
        return ans %= right;
    }
    bool operator!=(const T1& right) const{
        const T1& left = static_cast<const T1&>( *this );
        return !(left == right);
    }
    bool operator>(const T1& right) const{
        const T1& left = static_cast<const T1&>( *this );
        return right < left;
    }
    bool operator<=(const T1& right) const{
        const T1& left = static_cast<const T1&>( *this );
        return !(right < left);
    }
    bool operator>=(const T1& right) const{
        const T1& left = static_cast<const T1&>( *this );
        return !(left < right);
    }
};

class Mod : public Operators<Mod>
{
private:
    static const int MOD = 1000000007;
    long long a;
public:
    Mod(){
        a = 0;
    }
    Mod(long long x){
        a = (x % MOD + MOD) % MOD;
    }
    Mod& operator+=(const Mod& x){
        a = (a + x.a) % MOD;
        return *this;
    }
    Mod& operator-=(const Mod& x){
        a = (a - x.a + MOD) % MOD;
        return *this;
    }
    Mod& operator*=(const Mod& x){
        a = (a * x.a) % MOD;
        return *this;
    }
    Mod& operator/=(const Mod& x){ // フェルマーの小定理、MODが素数である場合のみ有効
        int b = MOD - 2;
        long long c = x.a;
        while(b > 0){
            if(b & 1){
                a *= c;
                a %= MOD;
            }
            c *= c;
            c %= MOD;
            b >>= 1;
        }
        return *this;
    }
    bool operator==(const Mod& x) const{
        return a == x.a;
    }
    long long getValue(){
        return a;
    }
};

Mod combination(int n, int r)
{
    if(n < r)
        return 0;
    if(n-r < r)
        r = n-r;
    Mod ret = 1;
    for(int i=0; i<r; i++){
        ret *= (n--);
        ret /= i+1;
    }
    return ret;
}

Mod solve(int n)
{
    Mod ans = 0;
    for(int i=1; i<n; ++i)
        ans += Mod(i) * (n - i);
    return ans;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    Mod ans = solve(n) * m * m + solve(m) * n * n;
    ans *= combination(n * m - 2, k - 2);
    cout << ans.getValue() << endl;

    return 0;
}
