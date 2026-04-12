#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<functional>
#include<map>
#include<cstdlib>
#include<complex>
#include<numeric>
#include<set>
#include<deque>

using namespace std;
using Int = long long;
Int INF = 1LL << 60;
const Int MOD = 1000000000 + 7;

template<int Modulo = MOD> struct Mint {
	Int val;
	constexpr Mint(Int v = 0) noexcept : val(v% Modulo) {
		if (val < 0) v += Modulo;
	}
	constexpr int getmod() { return Modulo; }
	constexpr Mint operator - () const noexcept { return val ? Modulo - val : 0; }
	constexpr Mint operator + (const Mint& r) const noexcept { return Mint(*this) += r; }
	constexpr Mint operator - (const Mint& r) const noexcept { return Mint(*this) -= r; }
	constexpr Mint operator * (const Mint& r) const noexcept { return Mint(*this) *= r; }
	constexpr Mint operator / (const Mint& r) const noexcept { return Mint(*this) /= r; }
	constexpr Mint& operator += (const Mint& r) noexcept {
		val += r.val;
		if (val >= Modulo) val -= Modulo;
		return *this;
	}
	constexpr Mint& operator -= (const Mint& r) noexcept {
		val -= r.val;
		if (val < 0) val += Modulo;
		return *this;
	}
	constexpr Mint& operator *= (const Mint& r) noexcept {
		val = val * r.val % Modulo;
		return *this;
	}
	constexpr Mint& operator /= (const Mint& r) noexcept {
		Int a = r.val, b = Modulo, u = 1, v = 0;
		while (b) {
			Int t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		val = val * u % Modulo;
		if (val < 0) val += Modulo;
		return *this;
	}
	constexpr bool operator == (const Mint& r) const noexcept {
		return this->val == r.val;
	}
	constexpr bool operator != (const Mint& r) const noexcept {
		return this->val != r.val;
	}
	friend ostream& operator << (ostream& os, const Mint<Modulo>& x) noexcept {
		return os << x.val;
	}
	friend istream& operator >> (istream& is, Mint<Modulo>& x) noexcept {
		Int tmp; is >> tmp;
		x = Mint<Modulo>(tmp);
		return is;
	}
	friend constexpr Mint<Modulo> modpow(const Mint<Modulo>& a, Int n) noexcept {
		Mint res(1), tmp = a;
		while (n > 0) {
			if (n & 1) res *= tmp;
			tmp *= tmp;
			n >>= 1;
		}
		return res;
	}
};

using mint = Mint<>;

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Int N;
	cin >> N;

	string s;
	cin >> s;

	vector<char> temp(N,'a');

	
	Int flag = 0;
	if (s[0] == 'o') {
		//先頭がSの場合
		temp[0] = 'S';
		temp[1] = 'S';//両隣がSの場合
		for (Int i = 2; i < N; i++) {
			if (temp[i-1]=='S' && s[i - 1] == 'o') {
				temp[i] = temp[i - 2];
			}
			else if (temp[i - 1] == 'S' && s[i - 1] == 'x') {
				if (temp[i - 2] == 'S')temp[i] = 'W';
				else temp[i] = 'S';
			}
			else if (temp[i - 1] == 'W' && s[i - 1] == 'o') {
				if (temp[i - 2] == 'S')temp[i] = 'W';
				else temp[i] = 'S';
			}
			else if (temp[i - 1] == 'W' && s[i - 1] == 'x') {
				if (temp[i - 2] == 'S')temp[i] = 'S';
				else temp[i] = 'W';
			}
		}
		if (temp[N - 1] == 'S') {
			flag = 1;
		}
		if (s[N - 1] == 'o') {
			if (temp[N - 1] == 'S') {
				if (temp[N - 2] != temp[0])flag = 0;
			}
			else {
				if (temp[N - 2] == temp[0])flag = 0;
			}
		}
		else {
			if (temp[N - 1] == 'S') {
				if (temp[N - 2] == temp[0])flag = 0;
			}
			else {
				if (temp[N - 2] != temp[0])flag = 0;
			}
		}

		if (flag == 0) {
			temp[0] = 'S';
			temp[1] = 'W';//両隣がWの場合
			for (Int i = 2; i < N; i++) {
				if (temp[i - 1] == 'S' && s[i - 1] == 'o') {
					temp[i] = temp[i - 2];
				}
				else if (temp[i - 1] == 'S' && s[i - 1] == 'x') {
					if (temp[i - 2] == 'S')temp[i] = 'W';
					else temp[i] = 'S';
				}
				else if (temp[i - 1] == 'W' && s[i - 1] == 'o') {
					if (temp[i - 2] == 'S')temp[i] = 'W';
					else temp[i] = 'S';
				}
				else if (temp[i - 1] == 'W' && s[i - 1] == 'x') {
					if (temp[i - 2] == 'S')temp[i] = 'S';
					else temp[i] = 'W';
				}
			}
			if (temp[N - 1] == 'W') {
				flag = 1;
			}
		}
		if (s[N - 1] == 'o') {
			if (temp[N - 1] == 'S') {
				if (temp[N - 2] != temp[0])flag = 0;
			}
			else {
				if (temp[N - 2] == temp[0])flag = 0;
			}
		}
		else {
			if (temp[N - 1] == 'S') {
				if (temp[N - 2] == temp[0])flag = 0;
			}
			else {
				if (temp[N - 2] != temp[0])flag = 0;
			}
		}

		//先頭がWの場合
		if (flag == 0) {
			temp[0] = 'W';
			temp[1] = 'W';//右隣がWの場合
			for (Int i = 2; i < N; i++) {
				if (temp[i - 1] == 'S' && s[i - 1] == 'o') {
					temp[i] = temp[i - 2];
				}
				else if (temp[i - 1] == 'S' && s[i - 1] == 'x') {
					if (temp[i - 2] == 'S')temp[i] = 'W';
					else temp[i] = 'S';
				}
				else if (temp[i - 1] == 'W' && s[i - 1] == 'o') {
					if (temp[i - 2] == 'S')temp[i] = 'W';
					else temp[i] = 'S';
				}
				else if (temp[i - 1] == 'W' && s[i - 1] == 'x') {
					if (temp[i - 2] == 'S')temp[i] = 'S';
					else temp[i] = 'W';
				}
			}
			if (temp[N - 1] == 'S') {
				flag = 1;
			}
			if (s[N - 1] == 'o') {
				if (temp[N - 1] == 'S') {
					if (temp[N - 2] != temp[0])flag = 0;
				}
				else {
					if (temp[N - 2] == temp[0])flag = 0;
				}
			}
			else {
				if (temp[N - 1] == 'S') {
					if (temp[N - 2] == temp[0])flag = 0;
				}
				else {
					if (temp[N - 2] != temp[0])flag = 0;
				}
			}
		}

		if (flag == 0) {
			temp[0] = 'W';
			temp[1] = 'S';//右隣がSの場合
			for (Int i = 2; i < N; i++) {
				if (temp[i - 1] == 'S' && s[i - 1] == 'o') {
					temp[i] = temp[i - 2];
				}
				else if (temp[i - 1] == 'S' && s[i - 1] == 'x') {
					if (temp[i - 2] == 'S')temp[i] = 'W';
					else temp[i] = 'S';
				}
				else if (temp[i - 1] == 'W' && s[i - 1] == 'o') {
					if (temp[i - 2] == 'S')temp[i] = 'W';
					else temp[i] = 'S';
				}
				else if (temp[i - 1] == 'W' && s[i - 1] == 'x') {
					if (temp[i - 2] == 'S')temp[i] = 'S';
					else temp[i] = 'W';
				}
			}
			if (temp[N - 1] == 'W') {
				flag = 1;
			}
			if (s[N - 1] == 'o') {
				if (temp[N - 1] == 'S') {
					if (temp[N - 2] != temp[0])flag = 0;
				}
				else {
					if (temp[N - 2] == temp[0])flag = 0;
				}
			}
			else {
				if (temp[N - 1] == 'S') {
					if (temp[N - 2] == temp[0])flag = 0;
				}
				else {
					if (temp[N - 2] != temp[0])flag = 0;
				}
			}
		}
	}
	else if (flag == 0 && s[0] == 'x') {
	//先頭がSの場合
	temp[0] = 'S';
	temp[1] = 'S';//両隣がSの場合
	for (Int i = 2; i < N; i++) {
		if (temp[i - 1] == 'S' && s[i - 1] == 'o') {
			temp[i] = temp[i - 2];
		}
		else if (temp[i - 1] == 'S' && s[i - 1] == 'x') {
			if (temp[i - 2] == 'S')temp[i] = 'W';
			else temp[i] = 'S';
		}
		else if (temp[i - 1] == 'W' && s[i - 1] == 'o') {
			if (temp[i - 2] == 'S')temp[i] = 'W';
			else temp[i] = 'S';
		}
		else if (temp[i - 1] == 'W' && s[i - 1] == 'x') {
			if (temp[i - 2] == 'S')temp[i] = 'S';
			else temp[i] = 'W';
		}
	}
	if (temp[N - 1] == 'W') {
		flag = 1;
	}
	if (s[N - 1] == 'o') {
		if (temp[N - 1] == 'S') {
			if (temp[N - 2] != temp[0])flag = 0;
		}
		else {
			if (temp[N - 2] == temp[0])flag = 0;
		}
	}
	else {
		if (temp[N - 1] == 'S') {
			if (temp[N - 2] == temp[0])flag = 0;
		}
		else {
			if (temp[N - 2] != temp[0])flag = 0;
		}
	}

	if (flag == 0) {
		temp[0] = 'S';
		temp[1] = 'W';//両隣がWの場合
		for (Int i = 2; i < N; i++) {
			if (temp[i - 1] == 'S' && s[i - 1] == 'o') {
				temp[i] = temp[i - 2];
			}
			else if (temp[i - 1] == 'S' && s[i - 1] == 'x') {
				if (temp[i - 2] == 'S')temp[i] = 'W';
				else temp[i] = 'S';
			}
			else if (temp[i - 1] == 'W' && s[i - 1] == 'o') {
				if (temp[i - 2] == 'S')temp[i] = 'W';
				else temp[i] = 'S';
			}
			else if (temp[i - 1] == 'W' && s[i - 1] == 'x') {
				if (temp[i - 2] == 'S')temp[i] = 'S';
				else temp[i] = 'W';
			}
		}
		if (temp[N - 1] == 'S') {
			flag = 1;
		}
		if (s[N - 1] == 'o') {
			if (temp[N - 1] == 'S') {
				if (temp[N - 2] != temp[0])flag = 0;
			}
			else {
				if (temp[N - 2] == temp[0])flag = 0;
			}
		}
		else {
			if (temp[N - 1] == 'S') {
				if (temp[N - 2] == temp[0])flag = 0;
			}
			else {
				if (temp[N - 2] != temp[0])flag = 0;
			}
		}
	}

	//先頭がWの場合
	if (flag == 0) {
		temp[0] = 'W';
		temp[1] = 'W';//右隣がWの場合
		for (Int i = 2; i < N; i++) {
			if (temp[i - 1] == 'S' && s[i - 1] == 'o') {
				temp[i] = temp[i - 2];
			}
			else if (temp[i - 1] == 'S' && s[i - 1] == 'x') {
				if (temp[i - 2] == 'S')temp[i] = 'W';
				else temp[i] = 'S';
			}
			else if (temp[i - 1] == 'W' && s[i - 1] == 'o') {
				if (temp[i - 2] == 'S')temp[i] = 'W';
				else temp[i] = 'S';
			}
			else if (temp[i - 1] == 'W' && s[i - 1] == 'x') {
				if (temp[i - 2] == 'S')temp[i] = 'S';
				else temp[i] = 'W';
			}
		}
		if (temp[N - 1] == 'W') {
			flag = 1;
		}
		if (s[N - 1] == 'o') {
			if (temp[N - 1] == 'S') {
				if (temp[N - 2] != temp[0])flag = 0;
			}
			else {
				if (temp[N - 2] == temp[0])flag = 0;
			}
		}
		else {
			if (temp[N - 1] == 'S') {
				if (temp[N - 2] == temp[0])flag = 0;
			}
			else {
				if (temp[N - 2] != temp[0])flag = 0;
			}
		}
	}

	if (flag == 0) {
		temp[0] = 'W';
		temp[1] = 'S';//右隣がSの場合
		for (Int i = 2; i < N; i++) {
			if (temp[i - 1] == 'S' && s[i - 1] == 'o') {
				temp[i] = temp[i - 2];
			}
			else if (temp[i - 1] == 'S' && s[i - 1] == 'x') {
				if (temp[i - 2] == 'S')temp[i] = 'W';
				else temp[i] = 'S';
			}
			else if (temp[i - 1] == 'W' && s[i - 1] == 'o') {
				if (temp[i - 2] == 'S')temp[i] = 'W';
				else temp[i] = 'S';
			}
			else if (temp[i - 1] == 'W' && s[i - 1] == 'x') {
				if (temp[i - 2] == 'S')temp[i] = 'S';
				else temp[i] = 'W';
			}
		}
		if (temp[N - 1] == 'S') {
			flag = 1;
		}
		if (s[N - 1] == 'o') {
			if (temp[N - 1] == 'S') {
				if (temp[N - 2] != temp[0])flag = 0;
			}
			else {
				if (temp[N - 2] == temp[0])flag = 0;
			}
		}
		else {
			if (temp[N - 1] == 'S') {
				if (temp[N - 2] == temp[0])flag = 0;
			}
			else {
				if (temp[N - 2] != temp[0])flag = 0;
			}
		}
	}


    }

	if (flag) {
		for (Int i = 0; i < N; i++) {
			printf("%c", temp[i]);
		}
	}
	else {
		printf("-1");
	}
	printf("\n");
}