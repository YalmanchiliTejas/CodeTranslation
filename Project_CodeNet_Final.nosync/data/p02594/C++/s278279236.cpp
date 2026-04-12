#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <string>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define int ll

const double PI = acos(-1.0);
const int MOD = (int)pow(10, 9) + 7;
const vector<string> alpha{ "a", "b", "c", "d" , "e" , "f" , "g" , "h" , "i" , "j" , "k" , "l" , "m" , "n" , "o" , "p" , "q" , "r" , "s" , "t" , "u" , "v" , "w" , "x" , "y" , "z" };
const vector<string> ALPHA{ "A", "B", "C", "D" , "E" , "F" , "G" , "H" , "I" , "J" , "K" , "L" , "M" , "N" , "O" , "P" , "Q" , "R" , "S" , "T" , "U" , "V" , "W" , "X" , "Y" , "Z" };
const map<string, int, less<>> alphaMap{
	{"a", 0},
	{"b", 1},
	{"c", 2},
	{"d", 3},
	{"e", 4},
	{"f", 5},
	{"g", 6},
	{"h", 7},
	{"i", 8},
	{"j", 9},
	{"k", 10},
	{"l", 11},
	{"m", 12},
	{"n", 13},
	{"o", 14},
	{"p", 15},
	{"q", 16},
	{"r", 17},
	{"s", 18},
	{"t", 19},
	{"u", 20},
	{"v", 21},
	{"w", 22},
	{"x", 23},
	{"y", 24},
	{"z", 25},
};
const map<string, int, less<>> ALPHAMap{
	{"A", 0},
	{"B", 1},
	{"C", 2},
	{"D", 3},
	{"E", 4},
	{"F", 5},
	{"G", 6},
	{"H", 7},
	{"I", 8},
	{"J", 9},
	{"K", 10},
	{"L", 11},
	{"M", 12},
	{"N", 13},
	{"O", 14},
	{"P", 15},
	{"Q", 16},
	{"R", 17},
	{"S", 18},
	{"T", 19},
	{"U", 20},
	{"V", 21},
	{"W", 22},
	{"X", 23},
	{"Y", 24},
	{"Z", 25},
};

#define YES(n) std::cout << ((n) ? "YES" : "NO") << endl;
#define Yes(n) std::cout << ((n) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define Ini(a) ll a; cin >> a;
#define Inui(a) ull a; cin >> a;
#define Ind(a) double a; cin >> a;
#define Ins(a) string a; cin >> a;
#define Inc(a) char a; cin >> a;
#define Inv(a,type,n) vector<type> a;a.reserve(n);for(ll i=0;i<n;++i){type tmp;cin>>tmp;a.emplace_back(tmp);}
#define Out(Bool, T, F) std::cout << ((Bool) ? T : F) << endl;
#define Sort(v) sort(all(v));
#define Rsort(v,type) sort(all(v),greater<type>());
#define Rsort_s(v) sort(v.rbegin(), v.rend());

ll modinv(ll a, ll m) {
	ll b = m, u = 1, v = 0;
	while (b) {
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

inline void finish() {
	std::cout << -1 << endl;
	exit(0);
}

template <typename T>
inline void debug(vector<T>& v) {
	if (v.size() == 0) {
		std::cout << "[]" << endl;
		return;
	}
	std::cout << "[";
	for (size_t i = 0; i < v.size() - 1; ++i) {
		std::cout << v[i] << ", ";
	}
	std::cout << v[v.size() - 1] << "]" << endl;
}

template <typename T, typename U>
inline void debug(map<T, U>& m) {
	if (m.size() == 0) {
		std::cout << "[]" << endl;
		return;
	}
	for (pair<T, U> p : m) {
		std::cout << "[" << p.first << ", " << p.second << "], ";
	}
	std::cout << endl;
}
template<typename T, typename U>
inline void debug(vector<pair<T, U>>& ps) {
	if (ps.size() == 0) {
		std::cout << "[]" << endl;
		return;
	}
	for (pair<T, U> p : ps) {
		std::cout << "[" << p.first << ", " << p.second << "], ";
	}
	std::cout << endl;
}
template<typename T>
inline void debug(multiset<T>& m) {
	if (m.size() == 0) {
		std::cout << "[]" << endl;
		return;
	}
	std::cout << "[";
	for (auto itr = m.begin(); itr != m.end(); ++itr) {
		std::cout << *itr << ", ";
	}
	std::cout << "]" << endl;
}

class Pos {
public:
	double x, y;
	Pos(double x, double y) {
		this->x = x;
		this->y = y;
	}
	Pos() {
		x = 0.0;
		y = 0.0;
	}

	bool operator==(Pos& pos2) {
		if (this->x == pos2.x && this->y == pos2.y) {
			return true;
		}
		return false;
	}
	bool operator!=(Pos& pos2) {
		return !(*this == pos2);
	}
};


class BitFlag {
private:
	ull m_bitFlag;
	int m_size;
	ull m_upper;
	vector<ull> m_exponentiation;
public:
	BitFlag(ull n) {
		if (n > 64) {
			throw string(("ビットフラグは64bitまでしか対応してない 指定された数=" + to_string(n)).c_str());
		}
		m_bitFlag = 0;
		m_size = n;
		m_upper = (int)pow(2, n) - 1;

		m_exponentiation.resize(n);
		for (ull i = 0; i < n; ++i) {
			m_exponentiation[i] = (ll)pow(2, i);
		}
	}

	void Set(ull n) {
		if (n > m_upper) {
			throw string((to_string(n) + "は" + to_string(m_size) + "bitでは表現できない").c_str());
		}
		m_bitFlag = n;
	}

	void Set(string& s) {
		if (s.size() > (size_t)m_size) {
			throw string(("\"" + s + "\"が" + to_string(m_size) + "bitよりも長いので無理").c_str());
		}
		int i = s.size() - 1;
		m_bitFlag = 0;
		for (const char c : s) {
			if (c != '0') {
				m_bitFlag += m_exponentiation[i];
			}
			i--;
		}
	}

	ll size() {
		return m_size;
	}

	bool operator[](int i) {
		if (i >= m_size) {
			throw string(("指定した値が領域を超えている index=" + to_string(i) + " size=" + to_string(m_size)).c_str());
		}
		return (m_bitFlag & m_exponentiation[i]) == 0 ? false : true;
	}

	BitFlag& operator++() {
		m_bitFlag++;
		if (m_bitFlag > m_upper) {
			m_bitFlag = 0;
		}
		return *this;
	}

	BitFlag operator++(signed) {
		BitFlag b = *this;
		m_bitFlag++;
		if (m_bitFlag > m_upper) {
			m_bitFlag = 0;
		}
		return b;
	}

	BitFlag& operator+=(const int n) {
		this->m_bitFlag += n;
		this->m_bitFlag %= m_upper;
		return *this;
	}
	BitFlag& operator-=(const int n) {
		this->m_bitFlag -= n;
		return *this;
	}
	BitFlag& operator+=(const BitFlag& b) {
		this->m_bitFlag += b.m_bitFlag;
		this->m_bitFlag %= m_upper;
		return *this;
	}
	BitFlag& operator-=(const BitFlag& b) {
		this->m_bitFlag -= b.m_bitFlag;
		return *this;
	}

	BitFlag operator+(int n) {
		m_bitFlag += n;
		this->m_bitFlag %= m_upper;
		return *this;
	}
	BitFlag operator-(int n) {
		m_bitFlag -= n;
		return *this;
	}
	BitFlag operator+(BitFlag& b) {
		this->m_bitFlag += b.m_bitFlag;
		this->m_bitFlag %= m_upper;
		return *this;
	}
	BitFlag operator-(BitFlag& b) {
		this->m_bitFlag -= b.m_bitFlag;
		return *this;
	}

	bool operator==(BitFlag& comp) {
		return comp.m_bitFlag == this->m_bitFlag ? true : false;
	}
	bool operator!=(BitFlag& comp) {
		return !(*this == comp);
	}

	friend ostream& operator<<(ostream& o, const BitFlag& b);
};

ostream& operator<<(ostream& o, const BitFlag& b) {
	for (ll i = 0; i < b.m_size; ++i) {
		std::cout << ((b.m_bitFlag & b.m_exponentiation[i]) == 0 ? false : true);
	}
	return o;
}

inline int GetKeta(int num) {
	return to_string(abs(num)).length();
}


class BigNum {
private :
	pair<double, int> num;

	void Update() {
		double absNum = fabs(num.first);
		if (absNum >= 10.0) {
			num.first /= 10.0;
			num.second++;
		}
		else if (absNum < 1.0) {
			num.first *= 10.0;
			num.second--;
		}
	}
public:
	BigNum() : num(0.0, 0) {}
	BigNum(int n) : num(n / pow(10.0, (GetKeta(n) - 1)), GetKeta(n) - 1) {}
	BigNum(signed n) : num(n / pow(10.0, (GetKeta(n) - 1)), GetKeta(n) - 1) {}
	BigNum(double n) : num(n / pow(10.0, (GetKeta((int)n) - 1)), GetKeta((int)n) - 1) {}
	BigNum(double f, int s) : num(f, s) {}
	BigNum(pair<double, int> n) : num(n) {}

	bool operator==(BigNum& comp) {
		return num == comp.num;
	}
	bool operator!=(BigNum& comp) {
		return num != comp.num;
	}
	bool operator<=(BigNum& comp) {
		return num.second < comp.num.second || (num.second == comp.num.second && num.first <= comp.num.first);
	}
	bool operator>=(BigNum& comp) {
		return num.second > comp.num.second || (num.second == comp.num.second && num.first >= comp.num.first);
	}
	bool operator<(BigNum& comp) {
		return num.second < comp.num.second || (num.second == comp.num.second && num.first < comp.num.first);
	}
	bool operator>(BigNum& comp) {
		return num.second > comp.num.second || (num.second == comp.num.second && num.first > comp.num.first);
	}

	BigNum operator+(BigNum& b) {
		if (num.second == b.num.second && num.first == -b.num.first) {
			num.first = 0.0;
			num.second = 0;
		}
		else if (num.second > b.num.second) {
			num.first += b.num.first * (1.0 / ((num.second - b.num.second) * 10.0));
		}
		else if(num.second < b.num.second){
			num.first = b.num.first + num.first * (1.0 / pow(10.0, b.num.second - num.second));
			num.second = b.num.second;
		}
		else {
			num.first += b.num.first;
		}
		Update();
		return *this;
	}

	BigNum operator-(BigNum& b) {
		if (*this == b) {
			num.first = 0.0;
			num.second = 0;
		}
		else if (num.second > b.num.second) {
			num.first -= b.num.first * (1.0 / ((num.second - b.num.second) * 10.0));
		}
		else if (num.second < b.num.second) {
			num.first = num.first * (1.0 / pow(10.0, b.num.second - num.second)) - b.num.first;
			num.second = b.num.second;
		}
		else {
			num.first -= b.num.first;
		}
		Update();
		return *this;
	}

	BigNum& operator+=(const BigNum& b) {
		*this = *this + (BigNum&)b;
		return *this;
	}

	BigNum& operator-=(const BigNum& b) {
		*this = *this - (BigNum&)b;
		return *this;
	}

	void Reverse() {
		num.first *= -1.0;
	}

	friend ostream& operator<<(ostream& o, const BigNum& b);
};

ostream& operator<<(ostream& o, const BigNum& b) {
	cout << b.num.first << "e+" << b.num.second << endl;
	return o;
}

class Mod {
public:
	static inline ll Add(ll a, ll b) {
		return (a + b) % MOD;
	}

	static inline ll Sub(ll a, ll b) {
		ll ans = (a - b) % MOD;
		return (ans < 0) ? (ans + MOD) : ans;
	}

	static inline ll Mul(ll a, ll b) {
		return (a * b) % MOD;
	}

	static inline ll Div(ll a, ll b) {
		return (a % MOD) * modinv(b, MOD) % MOD;
	}
};

inline double distance(Pos p1, Pos p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

inline ull Kaijo(int n) {
	ull ans = 1;
	for (int i = 2; i <= n; ++i) {
		ans *= i;
	}
	return ans;
}

void Main();
inline void DebugMain() {
	while (true) {
		Main();
		std::cout << endl;
	}
}

signed main() {
	bool debug = false;
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	std::cout << fixed << setprecision(15);

	if (debug) {
		std::cout << "\x1b[41m" << "Debug Mode このまま提出すると死" << endl;
	}
	try {
		(debug) ? DebugMain() : Main();
	}
	catch (exception& e) {
		std::cout << e.what() << endl;
	}
	catch (string& s) {
		std::cout << s << endl;
	}

	return 0;
}

template <typename T>
inline bool isExistArray(vector<T>& v, T& str) {
	if (v.size() == 0) {
		return false;
	}
	for (string& s : v) {
		if (s == str) {
			return true;
		}
	}
	return false;
}

inline int ctoi(char c) {
	return (int)c - 48;
}

template <typename T>
inline int Find(vector<T>& v, T n) {
	for (size_t i = 0; i < v.size(); ++i) {
		if (v[i] == n) {
			return i;
		}
	}
	return -1;
}

inline bool isSameArray(vector<int>& v1, vector<int>& v2) {
	for (size_t i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i]) {
			return false;
		}
	}
	return true;
}

inline bool isSeisu(double n) {

	if (std::floor(n) == n) {
		return true;
	}
	return false;
}

int gcd(int a, int b)
{
	if (a % b == 0)
	{
		return(b);
	}
	else
	{
		return(gcd(b, a % b));
	}
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

inline ll Kiriage(ll a, ll b) {
	return (a + (b - 1)) / b;
}

template<class T>
inline void container_sort(std::vector<T>& v) {
	std::sort(all(v));
}
template<class T>
inline void container_sort(std::list<T>& v) {
	v.sort();
}

template<class T>
inline void Unique(T& v) {

	container_sort(v);
	v.erase(
		std::unique(
			v.begin(),
			v.end()),
		v.end()
	);
}

inline vector<bool> GetPrimeTable(int n) {
	vector<bool> primeTable(n + 1, true);
	int sqr = (int)sqrt(n);
	primeTable[0] = false; //0は素数じゃない
	primeTable[1] = false; //1は素数じゃない
	for (int i = 2; i <= sqr; ++i) {
		if (primeTable[i]) {
			for (size_t j = i + i; j < primeTable.size(); j += i) {
				primeTable[j] = false;
			}
		}
	}
	return primeTable;
}

inline vector<ll> GetPrimeNumbers(int n) {
	vector<bool> primeTable = GetPrimeTable(n);
	vector<ll> result;
	if (n < 2) {
		result;
	}
	result.reserve(n / 2);
	for (size_t i = 0; i < primeTable.size(); ++i) {
		if (primeTable[i]) {
			result.push_back(i);
		}
	}
	result.shrink_to_fit();
	return result;
}

inline map<ll, ll> PrimeFact(ull n) {
	ull num = 2;
	map<ll, ll> result;
	while (true) {
		if (n % num == 0) {
			if (result.count(num) == 0) {
				result.insert(pair<ll, ll>{num, 1});
			}
			else {
				result[num]++;
			}
			n /= num;
		}
		else {
			if (++num > sqrt(n)) {
				if (result.size() == 0 || n != 1) {
					result.insert(pair<ll, ll>{n, 1});
				}
				return result;
			}
		}
	}
}

void recursive_comb(int* indexes, int s, int rest, std::function<void(int*)> f) {
	if (rest == 0) {
		f(indexes);
	}
	else {
		if (s < 0) return;
		recursive_comb(indexes, s - 1, rest, f);
		indexes[rest - 1] = s;
		recursive_comb(indexes, s - 1, rest - 1, f);
	}
}

template <typename T>
inline vector<int> GetBorder(vector<T>& v) {
	T tmp = v[0];
	vector<int> border;
	size_t vSize = v.size();
	border.reserve(vSize / 3); //雑に確保
	for (size_t i = 1; i < vSize; ++i) {
		if (v[i] != tmp) {
			border.push_back(i);
			tmp = v[i];
		}
	}
	return border;
}

template <typename T, typename U>
inline vector<int> GetBorder(vector<pair<T, U>>& ps) {
	T tmp = ps[0].first;
	vector<int> border;
	size_t psSize = ps.size();
	border.reserve(psSize / 3); //雑に確保
	for (size_t i = 1; i < psSize; ++i) {
		if (ps[i].first != tmp) {
			border.push_back(i);
			tmp = ps[i].first;
		}
	}
	return border;
}

//foreach_comb(n, k, [](int*indexes){
//});
// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int*)> f) {
	int* indexes = new int[k];
	recursive_comb(indexes, n - 1, k, f);
}

template <typename T>
inline T MultisetPopBack(multiset<T>& m) {
	auto iter = m.end();
	iter--;
	T tmp = *iter;
	m.erase(m.find(*iter));
	return tmp;
}

template <typename T>
inline T MultisetPopFront(multiset<T>& m) {
	auto iter = m.begin();
	T tmp = *iter;
	m.erase(m.find(*iter));

	return tmp;
}

inline void Main() {
	Ini(X);

	Yes(X >= 30);
}