#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)

//* 便利な変数
namespace {
	int dx4[] = { 1, -1, 0, 0 };
	int dy4[] = { 0, 0, 1, -1 };

	int dx8[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
	int dy8[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

	int mDays[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	ll A, B, C, D, E, F, G, H, I, J, K, L, M,
		N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

	const ll MOD_CONST = (ll)(1e9 + 7);
}
template <typename T>
vector<T> INP(ll n)
{
	vector<T> x;
	REP(i, n) {
		T tmp; cin >> tmp;
		x.push_back(tmp);
	}
	return move(x);
}
//* n文字1行の文字列を入力，一文字ごとの配列を返す
vector<char> SPRIT_STRING(ll n)
{
	string str; cin >> str;
	vector<char> cs(n);
	REP(i, n) cs[i] = str[i];
	return move(cs);
}
//* 文字列中から文字列を検索して別の文字列に置換する
void strReplace(std::string& str, const std::string& from, const std::string& to) {
	std::string::size_type pos = 0;
	while (pos = str.find(from, pos), pos != std::string::npos) {
		str.replace(pos, from.length(), to);
		pos += to.length();
	}
}
//* 素数関連関数
namespace PrimeLib {
	//* 素数判定 is_prime<unsigned>(N)
	template<typename T, std::enable_if_t<std::is_unsigned<T>::value, std::nullptr_t> = nullptr>
	bool is_prime(const T n) {
		if (n < 4) return n == 2 || n == 3;
		if (n % 2 == 0 || n % 3 == 0 || (n % 6 != 1 && n % 6 != 5)) return false;
		for (T i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false;
		return true;
	}
	//* 素数テーブル生成　エラトステネスの篩
	vector<ll> primeTable(ll n) {
		vector<bool> table(n - 1);
		vector<ll> ret;
		for (ll i = 0; i < n - 1; ++i) {
			if (table[i] == false) {
				ll num = i + 2;
				ret.push_back(i + 2);
				for (int j = i + num; j < n - 1; j += num)
					table[j] = true;	
			}
		}
		return ret;
	}
}
//* 組み合わせ計算
inline unsigned long long NChooseK(const unsigned long long& n, const unsigned long long& k)
{
	if (n  < k) return 0;
	if (0 == n) return 0;
	if (0 == k) return 1;
	if (n == k) return 1;
	if (1 == k) return n;
	typedef unsigned long long value_type;
	value_type* table = new value_type[static_cast<std::size_t>(n * n)];
	std::fill_n(table, n * n, 0);
	class n_choose_k_impl
	{
	public:

		n_choose_k_impl(value_type* table, const value_type& dimension)
			: table_(table),
			dimension_(dimension)
		{}

		inline value_type& lookup(const value_type& n, const value_type& k)
		{
			return table_[dimension_ * n + k];
		}

		inline value_type compute(const value_type& n, const value_type& k)
		{
			if ((0 == k) || (k == n))
				return 1;
			value_type v1 = lookup(n - 1, k - 1);
			if (0 == v1)
				v1 = lookup(n - 1, k - 1) = compute(n - 1, k - 1);
			value_type v2 = lookup(n - 1, k);
			if (0 == v2)
				v2 = lookup(n - 1, k) = compute(n - 1, k);
			return v1 + v2;
		}

		value_type* table_;
		value_type dimension_;
	};
	value_type result = n_choose_k_impl(table, n).compute(n, k);
	delete[] table;
	return result;
}
//* 座標nx, nyがWidth,Heightの領域内にあるかどうかのチェック
inline bool rangeCheck2D(int nx, int ny, int Width, int Height)
{
	return nx >= 0 and nx < Width and ny >= 0 and ny < Height;
}
//* bit全探索
/*
for (int i = 0; i < 1<<N; i++) {
	REP(j, N)
		if ((1 & i >> j) == 1) {;}
}
*/

namespace arc077a {
	void arc077a()
	{
		cin >> N;
		list<int> as;
		REP(i, N) {
			int a; cin >> a;
			if (i % 2 != 0)
				as.push_front(a);
			else
				as.push_back(a);
		}
		int cnt = 0;
		if (N % 2 != 0) {
			for (auto itr = as.rbegin(); itr != as.rend(); ++itr) {
				cout << *itr;
				if (cnt == N - 1)
					cout << endl;
				else
					cout << " ";
				cnt++;
			}
			return;
		}
		for (auto a : as) {
			cout << a;
			if (cnt == N - 1)
				cout << endl;
			else
				cout << " ";
			cnt++;
		}
	}
}

int main()
{
	//abc017c::abc017c();
	//abc084d::abc084d();
	arc077a::arc077a();
	//agc001a::agc001a();
	return 0;
}