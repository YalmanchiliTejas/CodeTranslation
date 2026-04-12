
#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
#include<limits>
#include<bitset>
#include<functional>
#include<type_traits>
#include<queue>
#include<stack>
#include<array>
#include<random>
#include<utility>
#include<cstdlib>
#include<cstring>
#include<string>
#include<ctime>
#include <type_traits>


using namespace std;

using ll = long long int;
using ull = long long unsigned;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const double PI = acos(-1.0);
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define Else(a,b,c) a!=b && b!=c && c!=a
#define all(v) v.begin(), v.end()
#define Ini(a) ll a; cin >> a;
#define Ind(a) double a; cin >> a;
#define Ins(a) string a; cin >> a;
#define Sort(v) sort(all(v));
#define Rsort(v,type) sort(all(v),greater<type>());
#define Unique(v) v.erase(unique(all(v)),v.end());

const long MOD = pow(10, 9) + 7;
const double pai = 3.14159265358979;

char ALFA[] = { 'A','B' ,'C','D' ,'E' ,'F' ,'G' ,'H' ,'I' ,'J' ,'K' ,'L' ,'M' ,'N' ,'O' ,'P' ,'Q' ,'R' ,'S' ,'T' ,'U' ,'V' ,'W' ,'X' ,'Y','Z' };
char alfa[] = { 'a','b' ,'c','d' ,'e' ,'f' ,'g' ,'h' ,'i' ,'j' ,'k' ,'l' ,'m' ,'n' ,'o' ,'p' ,'q' ,'r' ,'s' ,'t' ,'u' ,'v' ,'w' ,'x' ,'y','z' };

inline void finish() {
	cout << -1 << endl;
	exit(0);
}

inline vector<bool> GetPrimeTable(int n) {
	vector<bool> primeTable(n + 1, true);
	int sqr = sqrt(n);
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

unsigned GetDigit(double num) {
	return log10(num) + 1;
}

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



template <typename T>
inline void debug(vector<T> v) {
	cout << "[";
	for (ll i = 0; i < v.size() - 1; ++i) {
		cout << v[i] << ", ";
	}
	cout << v[v.size() - 1] << "]" << endl;
}

void Main();
inline void DebugMain() {
	while (true) {
		Main();
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);

	bool debug = false;
	if (debug) {
		cout << "\x1b[41m" << "Debug Mode " << endl;
	}
	(debug) ? DebugMain() : Main();
	return 0;
}

int parmitation(ll N) {
	ll ans = 1;
	for (ll i = 1; i <= N; i++) {
		ans *= i;
	}

	return ans;
}

int SemiCommonMultiple(ll A, ll ANum, ll B, ll BNum, ll diff, ll max) {
	ll calc;
	calc = diff + B * BNum - A * ANum;

	if (diff + B * BNum > max) {
		return 0;
	}
	else {
		if (calc < 0) {
			SemiCommonMultiple(A, ANum, B, ++BNum, diff, max);
		}
		else if (calc > 0) {
			SemiCommonMultiple(A, ++ANum, B, BNum, diff, max);
		}
		else {
			return A * (ANum + 0.5);
		}
	}
}

ll  CaracalVsMonstor(ll H, ll sum, ll count) {
	if (H == 0) {
		return sum;
	}


	H = H / 2;
	sum = sum + count;

	count = count * 2;

	return CaracalVsMonstor(H, sum, count);

}

class ibis {
public:
	ll A;
	ll B;
	ld spec;

	bool operator<(const ibis& another) const
	{
		return spec < another.spec;
	};
};


ll gcd(ll a, ll b) {
	if ((a = a % b) == 0) {
		return b;
	}

	return gcd(b, a);
}



inline void Main() {
	ll X, Y, N, M, K, H, Q, W;
	vector<ll> A;
	vector<ll> B;
	ll ans = 1, temp = 0;
	ll sum = 0, count = 0;
	double avg = 0.0;
	string S;
	ll IndexA = 0;
	ll IndexB = 0;
	bool flag = false;

	cin >> X;

	Yes(X >= 30);

}