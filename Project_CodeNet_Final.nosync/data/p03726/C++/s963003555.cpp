#include<bits/stdc++.h>
using namespace std;
#define INFS (1LL<<28)
#define DEKAI 1000000007
//#define MOD 1000000007
#define lp(i,n) for(int i=0;i<n;i++)
#define lps(i,n) for(int i=1;i<=n;i++)
#define all(c) begin(c), end(c)

//#define int long long 

namespace {
	#define __DECLARE__(C)    \
	    template <typename T> \
	    std::ostream &operator<<(std::ostream &, const C<T> &);

	#define __DECLAREM__(C)               \
	    template <typename T, typename U> \
	    std::ostream &operator<<(std::ostream &, const C<T, U> &);

	__DECLARE__(std::vector)
	__DECLARE__(std::deque)
	__DECLARE__(std::set)
	__DECLARE__(std::stack)
	__DECLARE__(std::queue)
	__DECLARE__(std::priority_queue)
	__DECLARE__(std::unordered_set)
	__DECLAREM__(std::map)
	__DECLAREM__(std::unordered_map)

	template <typename T, typename U>
	std::ostream &operator<<(std::ostream &, const std::pair<T, U> &);
	template <typename... T>
	std::ostream &operator<<(std::ostream &, const std::tuple<T...> &);
	template <typename T, std::size_t N>
	std::ostream &operator<<(std::ostream &, const std::array<T, N> &);

	template <typename Tuple, std::size_t N>
	struct __TuplePrinter__ {
	    static void print(std::ostream &os, const Tuple &t) {
	        __TuplePrinter__<Tuple, N - 1>::print(os, t);
	        os << ", " << std::get<N - 1>(t);
	    }
	};

	template <typename Tuple>
	struct __TuplePrinter__<Tuple, 1> {
	    static void print(std::ostream &os, const Tuple &t) { os << std::get<0>(t); }
	};

	template <typename... T>
	std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &t) {
	    os << '(';
	    __TuplePrinter__<decltype(t), sizeof...(T)>::print(os, t);
	    os << ')';
	    return os;
	}

	template <typename T, typename U>
	std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &v) {
	    return os << '(' << v.first << ", " << v.second << ')';
	}

	#define __INNER__                             \
	    os << '[';                                \
	    for (auto it = begin(c); it != end(c);) { \
	        os << *it;                            \
	        os << (++it != end(c) ? ", " : "");   \
	    }                                         \
	    return os << ']';

	template <typename T, std::size_t N>
	std::ostream &operator<<(std::ostream &os, const std::array<T, N> &c) {
	    __INNER__
	}

	#define __DEFINE__(C)                                           \
	    template <typename T>                                       \
	    std::ostream &operator<<(std::ostream &os, const C<T> &c) { \
	        __INNER__                                               \
	    }

	#define __DEFINEM__(C)                                             \
	    template <typename T, typename U>                              \
	    std::ostream &operator<<(std::ostream &os, const C<T, U> &c) { \
	        __INNER__                                                  \
	    }

	#define __DEFINEW__(C, M1, M2)                                  \
	    template <typename T>                                       \
	    std::ostream &operator<<(std::ostream &os, const C<T> &c) { \
	        std::deque<T> v;                                        \
	        for (auto d = c; !d.empty(); d.pop()) v.M1(d.M2());     \
	        return os << v;                                         \
	    }

	__DEFINE__(std::vector)
	__DEFINE__(std::deque)
	__DEFINE__(std::set)
	__DEFINEW__(std::stack, push_front, top)
	__DEFINEW__(std::queue, push_back, front)
	__DEFINEW__(std::priority_queue, push_front, top)
	__DEFINE__(std::unordered_set)
	__DEFINEM__(std::map)
	__DEFINEM__(std::unordered_map)
}

#define pii pair<int,int>
#define ll long long
inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// modint 
template <signed M, unsigned T>
struct mod_int {
    constexpr static signed MODULO = M;
    constexpr static unsigned TABLE_SIZE = T;

    signed x;

    mod_int() : x(0) {}

    mod_int(long long y) : x(static_cast<signed>(y >= 0 ? y % MODULO : MODULO - (-y) % MODULO)) {}

    mod_int(int y) : x(y >= 0 ? y % MODULO : MODULO - (-y) % MODULO) {}

    mod_int &operator+=(const mod_int &rhs) {
        if ((x += rhs.x) >= MODULO) x -= MODULO;
        return *this;
    }

    mod_int &operator-=(const mod_int &rhs) {
        if ((x += MODULO - rhs.x) >= MODULO) x -= MODULO;
        return *this;
    }

    mod_int &operator*=(const mod_int &rhs) {
        x = static_cast<signed>(1LL * x * rhs.x % MODULO);
        return *this;
    }

    mod_int &operator/=(const mod_int &rhs) {
        x = static_cast<signed>((1LL * x * rhs.inv().x) % MODULO);
        return *this;
    }

    mod_int operator-() const { return mod_int(-x); }

    mod_int operator+(const mod_int &rhs) const { return mod_int(*this) += rhs; }

    mod_int operator-(const mod_int &rhs) const { return mod_int(*this) -= rhs; }

    mod_int operator*(const mod_int &rhs) const { return mod_int(*this) *= rhs; }

    mod_int operator/(const mod_int &rhs) const { return mod_int(*this) /= rhs; }

    bool operator<(const mod_int &rhs) const { return x < rhs.x; }

    mod_int inv() const {
        assert(x != 0);
        if (x <= static_cast<signed>(TABLE_SIZE)) {
            if (_inv[1].x == 0) prepare();
            return _inv[x];
        } else {
            signed a = x, b = MODULO, u = 1, v = 0, t;
            while (b) {
                t = a / b;
                a -= t * b;
                std::swap(a, b);
                u -= t * v;
                std::swap(u, v);
            }
            return mod_int(u);
        }
    }

    mod_int pow(long long t) const {
        assert(!(x == 0 && t == 0));
        mod_int e = *this, res = mod_int(1);
        for (; t; e *= e, t >>= 1)
            if (t & 1) res *= e;
        return res;
    }

    mod_int fact() {
        if (_fact[0].x == 0) prepare();
        return _fact[x];
    }

    mod_int inv_fact() {
        if (_fact[0].x == 0) prepare();
        return _inv_fact[x];
    }

    mod_int choose(mod_int y) {
        assert(y.x <= x);
        return this->fact() * y.inv_fact() * mod_int(x - y.x).inv_fact();
    }

    static mod_int _inv[TABLE_SIZE + 1];

    static mod_int _fact[TABLE_SIZE + 1];

    static mod_int _inv_fact[TABLE_SIZE + 1];

    static void prepare() {
        _inv[1] = 1;
        for (int i = 2; i <= (int)TABLE_SIZE; ++i) {
            _inv[i] = 1LL * _inv[MODULO % i].x * (MODULO - MODULO / i) % MODULO;
        }
        _fact[0] = 1;
        for (unsigned i = 1; i <= TABLE_SIZE; ++i) {
            _fact[i] = _fact[i - 1] * int(i);
        }
        _inv_fact[TABLE_SIZE] = _fact[TABLE_SIZE].inv();
        for (int i = (int)TABLE_SIZE - 1; i >= 0; --i) {
            _inv_fact[i] = _inv_fact[i + 1] * (i + 1);
        }
    }
};

template <int M, unsigned F>
std::ostream &operator<<(std::ostream &os, const mod_int<M, F> &rhs) {
    return os << rhs.x;
}

template <int M, unsigned F>
std::istream &operator>>(std::istream &is, mod_int<M, F> &rhs) {
    long long s;
    is >> s;
    rhs = mod_int<M, F>(s);
    return is;
}

template <int M, unsigned F>
mod_int<M, F> mod_int<M, F>::_inv[TABLE_SIZE + 1];

template <int M, unsigned F>
mod_int<M, F> mod_int<M, F>::_fact[TABLE_SIZE + 1];

template <int M, unsigned F>
mod_int<M, F> mod_int<M, F>::_inv_fact[TABLE_SIZE + 1];

template <int M, unsigned F>
bool operator==(const mod_int<M, F> &lhs, const mod_int<M, F> &rhs) {
    return lhs.x == rhs.x;
}

template <int M, unsigned F>
bool operator!=(const mod_int<M, F> &lhs, const mod_int<M, F> &rhs) {
    return !(lhs == rhs);
}

const int MF = 1000010;
const int MOD = 1000000007;

using mint = mod_int<MOD, MF>;

mint binom(int n, int r) { return (r < 0 || r > n || n < 0) ? 0 : mint(n).choose(r); }

mint fact(int n) { return mint(n).fact(); }

mint inv_fact(int n) { return mint(n).inv_fact(); }
// above

#define int unsigned long long
#define double long double 


signed main(){
	int n;
	cin>>n;
	vector<int> g[100001];
	lp(i,n-1){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<bool> leaf(100001,false);
	vector<bool> up2(100001,false);
	lp(i,n){
		if(g[i].size()==1)leaf[i]=true;
	}
	lp(i,n){
		if(leaf[i]==true){
		lp(j,g[i].size()){
			int next=g[i][j];
			up2[next]=true;
		}
	}
	}
	string ans="Second";
	lp(i,n){
		int lfcnt=0;
		int up2cnt=0;
		lp(j,g[i].size()){
			int next=g[i][j];
			if(leaf[next])lfcnt++;
			if(up2[next])up2cnt++;
		}
		//cout<<i<<" "<<lfcnt<<" "<<up2cnt<<ans<<endl;
		if(lfcnt>=2)ans="First";
		if(up2cnt==g[i].size()&&up2cnt>=2)ans="First";
	}
	if(n%2==1)cout<<"First"<<endl;
	else cout<<ans<<endl;
	return 0;
}  