#include <bits/stdc++.h>

#ifdef DEBUG
#define PRINT(x)\
    cout<<"func "<<__func__<<": line "<<__LINE__<<": "<<#x<<" = "<<(x)<<endl;
#define PRINTA(a,first,last)\
    cout<<"func "<<__func__<<": line "<<__LINE__<<": "<<#a<<"["<<(first)<<", "<<(last)<<")"<<endl;\
    for (int _i=(first);_i<(last);++_i){cout<<#a<<"["<<_i<<"] = "<<(a)[_i]<<endl;}
#define PRINTI(a,i)\
    cout<<"func "<<__func__<<": line "<<__LINE__<<": "<<#a<<"["<<#i<<"] = "<<#a<<"["<<(i)<<"] = "<<(a)[i]<<endl;
#define dprintf(...) printf(__VA_ARGS__)
#else
#define PRINT(x)
#define PRINTA(a,first,last)
#define PRINTI(a,i)
#define dprintf(...)
#endif

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);--i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define RREP(i,n) for (int i=(n)-1;i>=0;--i)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define MOD 1000000007
//#define MOD 998244353

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

template <class T, class U> void amax(T& x, U y) {if (x < y) x = y;}
template <class T, class U> void amin(T& x, U y) {if (x > y) x = y;}

template <class T, class U>
std::ostream& operator<<(std::ostream &os, const std::pair<T, U> &p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}
 
template <class T>
std::ostream& operator<<(std::ostream &os, const std::vector<T> &v) {
    os << "[";
	for (int i = 0; i < v.size(); ++i) {
        if (i) {
            if (i % 5 == 0) {
                os << ",\n ";
            } else {
                os << ", ";
            }
        }
		os << v[i];
	}
	os << "]";
	return os;
}

template <class T>
using vec2 = vector<vector<T>>;

template <class T>
using vec3 = vector<vector<vector<T>>>;

template <class T>
vec2<T> vec2_init(int n0, int n1, T x = 0) {
    return vec2<T>(n0, vector<T>(n1, x));
}

template <class T>
vec3<T> vec3_init(int n0, int n1, int n2, T x = 0) {
    return vec3<T>(n0, vec2_init(n1, n2, x));
}

/*
 *           U P
 *           - x
 *            ^
 *            |
 * LEFT -y <--+--> +y RIGHT
 *            |
 *            v
 *           + x
 *         D O W N
 */

const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

enum {
    DOWN,
    RIGHT,
    UP,
    LEFT,
};

template <class T, T M>
class modulo {
public:
    T data;

    modulo(T data = 0) {
        T r = data % M;
        if (r < 0) {
            r += M;
        }
        this->data = r;
    }

    modulo operator+(const modulo &x) const {
        return modulo(data + x.data);
    }

    modulo operator-(const modulo &x) const {
        return modulo(data + (M - x.data));
    }

    modulo operator*(const modulo &x) const {
        return modulo(data * x.data);
    }

    modulo operator/(const modulo &x) const {
        return modulo(data * x.inv().data);
    }

    modulo operator+=(const modulo &x) {
        return data = (data + x.data) % M;
    }

    modulo operator-=(const modulo &x) {
        return data = (data + (M - x.data)) % M;
    }

    modulo operator*=(const modulo &x) {
        return data = (data * x.data) % M;
    }

    modulo operator/=(const modulo &x) {
        return data = (data * x.inv().data) % M;
    }

    modulo inv() const {
        return _pow(M - 2);
    }

    template <class Integer>
    modulo operator^(Integer n) const {
        if (n >= 0) {
            return _pow(n);
        } else {
            return _pow(M - 1 - (-n) % (M - 1));
        }
    }

    friend std::ostream& operator<<(std::ostream &os, const modulo &x) {
        os << x.data;
        return os;
    }

private:
    template <class NonNegativeInteger>
    modulo _pow(NonNegativeInteger n) const {
        modulo result(1);
        modulo x(*this);
        while (n) {
            if (n & 1) {
                result *= x;
            }
            x *= x;
            n >>= 1;
        }
        return result;
    }
};

template <class T, T M>
struct combinatorics {

    using Mod = modulo<T, M>;

    T N;
    std::vector<Mod> factorial;
    std::vector<Mod> inv_factorial;

    combinatorics(T N) : N(N), factorial(N + 1), inv_factorial(N + 1) {
        factorial[0] = 1;
        for (T i = 1; i <= N; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }
        inv_factorial[N] = factorial[N].inv();
        for (T i = N; i >= 1; --i) {
            inv_factorial[i - 1] = inv_factorial[i] * i;
        }
    }

    Mod P(T n, T k) {
        if (0 <= k && k <= n) {
            return factorial[n] * inv_factorial[n - k];
        } else {
            return 0;
        }
    }

    Mod C(T n, T k) {
        if (0 <= k && k <= n) {
            return factorial[n] * inv_factorial[k] * inv_factorial[n - k];
        } else {
            return 0;
        }
    }

    Mod H(T n, T k) {
        if (n == 0 && k == 0) {
            return 1;
        } else {
            return C(n + k - 1, k);
        }
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    using Mod = modulo<ll, MOD>;

    int N;
    cin >> N;
    Mod A_sum = 0;
    Mod A2_sum = 0;
    REP(_, N) {
        ll A;
        cin >> A;
        A_sum += A;
        A2_sum += A * A;
    }
    Mod result = (A_sum * A_sum - A2_sum) / Mod(2);
    cout << result << endl;

    return 0;
}
