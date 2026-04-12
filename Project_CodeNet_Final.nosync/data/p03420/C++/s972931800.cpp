#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<numeric>
#include<list>
#include<stack>
#include<tuple>
#include<map>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<ULL> VULL;
typedef vector<VLL> VVLL;

class MYCP {
public:

	static const LL MOD_CONST_ATCODER = (LL)1000 * 1000 * 1000 + 7;

	static LL DebugFlag;

	//数値を区切って文字列にする
	static string MakeString_LongLong(vector<long long> const& numbers, string const& str) {
		if (numbers.size() == 0)return "";
		string result = "" + to_string(numbers[0]);
		for (long long i = 1; i < numbers.size(); i++) {
			result += str;
			result += to_string(numbers[i]);
		}

		return result;
	}

	//空白で区切る為のオーバーロード
	static string MakeString_LongLong(vector<long long> const& numbers) {
		if (numbers.size() == 0)return "";
		string result = "" + to_string(numbers[0]);
		for (long long i = 1; i < numbers.size(); i++) {
			result += " ";
			result += to_string(numbers[i]);
		}

		return result;
	}



	//文字列の配列を改行を挟んでまとめる
	static string MakeString_VectorString(vector<string> const& str) {
		string result = "";
		for (long long i = 0; i < str.size(); i++) {
			result += str[i] + "\n";
		}

		return result;
	}

	//文字列を必要な個数だけ読み取る
	static vector<string> MyReadLineSplit(LL n) {
		vector<string> str(n);
		for (long long i = 0; i < n; i++) {
			std::cin >> str[i];
		}

		return str;
	}

	//数値を必要な個数だけ読み取る
	static vector<long long> ReadInts(long long number) {
		vector<long long> a(number);
		for (int i = 0; i < number; i++) {
			std::cin >> a[i];
		}

		return a;
	}

	//渡された自然数が素数ならtureを返す
	static bool PrimeCheck_Int(long long number) {
		if (number < 2)return false;

		for (ULL i = 2; i*i <= number; i++) {
			if (number%i == 0)return false;
		}

		return true;
	}

	//渡された数値以下の素数表を作る
	static vector<long long> MakePrimeList(long long n) {
		vector<long long> list;
		LL i, j, p;
		bool flag;
		for (i = 2; i <= n; i++) {
			flag = true;
			for (j = 0; j < list.size(); j++) {

				if (!(list[j] * list[j] <= i))break;

				if (i%list[j] == 0) {
					flag = false;
					break;
				}
			}
			if (flag)list.push_back(i);
		}

		return list;
	}



	//文字列の分割
	static vector<string> split(string const& str, char sep)
	{
		vector<std::string> v;        // 分割結果を格納するベクター
		auto first = str.begin();              // テキストの最初を指すイテレータ
		while (first != str.end()) {         // テキストが残っている間ループ
			auto last = first;                      // 分割文字列末尾へのイテレータ
			while (last != str.end() && *last != sep)       // 末尾 or セパレータ文字まで進める
				last++;
			v.push_back(string(first, last));       // 分割文字を出力
			if (last != str.end())
				last++;
			first = last;          // 次の処理のためにイテレータを設定
		}
		return v;
	}

	//合計を求める
	template<typename T>
	static LL Sum(T const& a) {
		LL sum = 0;
		auto itr = a.begin();

		while (itr != a.end())
		{
			sum += (*itr);
			itr++;
		}

		return sum;
	}

	//小文字ならtrueを返す
	static bool Komoji(char a) {
		if (a >= 'a'&&a <= 'z')return true;

		return false;
	}

	//大文字ならtrueを返す
	static bool Oomoji(char a) {
		if (a >= 'A'&&a <= 'Z')return true;

		return false;
	}

	//切り上げの整数値割り算
	static LL KiriageWarizan(LL a, LL b) {
		LL result = a / b;

		if (a%b > 0)result++;

		return result;
	}

	//最大公約数を求める
	static LL GreatestCommonFactor(LL a, LL b) {
		a = abs(a);
		b = abs(b);

		LL temp;
		if (a < b) {
			temp = b;
			b = a;
			a = temp;
		}

		while (b > 0)
		{
			temp = a % b;
			a = b;
			b = temp;
		}

		return a;
	}

	//最小公倍数を求める
	static LL LeastCommonMultiple(LL a, LL b) {
		return (a / GreatestCommonFactor(a, b))*b;
	}

	//素因数分解、素数、指数の順
	static vector<VLL> PrimeFactorization(LL n) {
		VLL p_list, s_list;

		LL i, j, k, count;

		for (i = 2; n > 1; i++) {
			if (i*i > n) {
				p_list.push_back(n);
				s_list.push_back(1);
				break;
			}

			if (n%i == 0) {
				count = 0;
				while (n%i == 0)
				{
					n /= i;
					count++;
				}

				p_list.push_back(i);
				s_list.push_back(count);
			}
		}

		vector<VLL> result;
		result.push_back(p_list);
		result.push_back(s_list);

		return result;
	}

	//組み合わせ nCr
	static LL Combination(LL n, LL r) {
		r = min(r, n - r);

		VLL p(n + 1, 0);

		LL i, j, k, a, b, c;

		for (i = 1; i <= r; i++) {
			auto temp = MYCP::PrimeFactorization(i);

			for (j = 0; j < temp[0].size(); j++) {
				p[temp[0][j]] -= temp[1][j];
			}

			a = i + n - r;
			temp = MYCP::PrimeFactorization(a);

			for (j = 0; j < temp[0].size(); j++) {
				p[temp[0][j]] += temp[1][j];
			}

		}

		LL result = 1;

		for (i = 0; i < p.size(); i++) {
			if (p[i] > 0) {

				for (j = 0; j < p[i]; j++) {
					result *= i;
					result %= MYCP::MOD_CONST_ATCODER;
				}

			}
		}

		return result;
	}

	//符号
	static  LL sign(LL const x) {
		if (x > 0)return 1;
		if (x < 0)return -1;
		return 0;
	}

	//円周率
	static double PI() {
		return (double)3.1415926535898;
	}

	//指定した桁でdoubleを出す
	static void CoutDoubleKeta(double a, LL keta) {
		cout << setprecision(keta) << a << flush;
	}

	//コンテナクラスの出力
	template<typename T>
	static T CoutVector(T const& ls) {
		LL i, j, k, size = distance(ls.begin(), ls.end());

		auto itr = ls.begin();

		for (i = 0; i < size - 1; i++) {
			cout << *itr << " " << flush;
			itr++;
		}

		cout << *itr << flush;

		return ls;
	}

	//コンテナクラスをソートする
	template<typename T>
	static T Sort(T & ls) {
		sort(ls.begin(), ls.end());

		return ls;
	}

	//順序関数付きでコンテナクラスをソートする
	template<typename T, typename F>
	static T Sort(T & ls, F func) {
		sort(ls.begin(), ls.end(), func);

		return ls;
	}

	//コンテナクラスを逆順に並び替える
	template<typename T>
	static T Reverse(T & ls) {
		reverse(ls.begin(), ls.end());

		return ls;
	}

	//コンテナクラスの条件を満たす要素を数え上げる。bool func(S x)
	template<typename T, typename S>
	static LL Count(T const& ls, S func) {
		LL ans = 0;
		auto itr = ls.begin();
		while (itr != ls.end()) {
			if (func(*itr))ans++;
			itr++;
		}
		return ans;
	}

	//コンテナクラスの要素をすべて更新する。S func(S x)
	template<typename T, typename S>
	static T AllUpdate(T & ls, S func) {
		auto itr = ls.begin();
		while (itr != ls.end()) {
			*itr = func(*itr);
			itr++;
		}
		return ls;
	}

	//デバッグ用出力
	template<typename T>
	static LL DebugPrintf(T output) {

		if (MYCP::DebugFlag) {
			std::cout << output << endl;
		}

		return MYCP::DebugFlag;
	}

	//デバッグ用入力
	static  LL DebugCin() {
		LL a;

		if (MYCP::DebugFlag) {
			cin >> a;
		}

		return a;
	}
};
LL MYCP::DebugFlag = 0;

//累積和を求めるクラス
class Ruisekiwa {
private:
	vector<LL> list;

public:

	void MakeArray(vector<LL> data) {
		LL i;
		list = data;
		list.push_back(0);
		list[0] = 0;
		for (i = 1; i < list.size(); i++) {
			list[i] = list[i - 1] + data[i - 1];
		}

	}

	LL Sum(LL start, LL end) {
		if (end < start) {
			std::cout << "startがendより大きいです";
			return 0;
		}
		if (start < 0 || end >= list.size()) {
			std::cout << "範囲が異常";
			return 0;
		}

		return list[end] - list[start];
	}

};

//n進数を管理するクラス
class N_Number {
public:
	N_Number(LL n, LL keta) {
		this->N_Shinsuu = n;

		VLL temp(keta, 0);
		this->numbers = temp;

	}

	//数を足す
	void plus(LL a) {
		if (a < 0) {
			a *= (-1);
			this->minus(a);
			return;
		}

		this->numbers[0] += a;
		LL size = this->numbers.size();
		for (LL i = 0; i < size; i++) {
			if (i + 1 < size) {
				this->numbers[i + 1] += this->numbers[i] / this->N_Shinsuu;
			}
			this->numbers[i] %= this->N_Shinsuu;
		}
	}

	//全ての桁が同じ数字になっていればその数字を返す。それ以外の場合は -1 を返す
	LL check() {
		LL a = this->numbers[0];

		for (LL i = 0; i < this->numbers.size(); i++) {
			if (this->numbers[i] != a)return -1;
		}

		return a;
	}

	LL getNumber(LL keta) {
		return this->numbers[keta];
	}

	LL getKeta() {
		return this->numbers.size();
	}

	LL getShinsuu() {
		return this->N_Shinsuu;
	}

	void setNumber(LL keta, LL number) {
		if (0 <= number && number < this->getShinsuu()) {
			if (0 <= keta && keta < this->getKeta()) {
				this->numbers[keta] = number;
				return;
			}
		}

		cout << "er" << endl;
	}

	void setAllNumbers(LL number) {
		LL size = this->getKeta(), i;
		for (i = 0; i < size; i++) {
			this->setNumber(i, number);
		}
	}

	string to_string_KetaSoroe() {
		string s = "";
		for (LL i = this->getKeta() - 1; i >= 0; i--) {
			s += to_string(this->getNumber(i));
		}

		return s;
	}

private:
	void minus(LL a) {
		LL i, j, k, zettaiti = abs(a);

		k = MYCP::KiriageWarizan(zettaiti, this->N_Shinsuu);
		j = k * (this->N_Shinsuu - 1);

		for (i = 0; i < this->getKeta(); i++) {
			this->numbers[i] += j;
		}

		this->numbers[0] += k - a;
		this->plus(0);
	}

	VLL numbers;
	LL N_Shinsuu;
};

//UnionFind
class Union_Find {
private:
	VLL tree;
	VLL count;

	LL root(LL a) {
		if (this->tree[a] == a)return a;
		return this->tree[a] = this->root(this->tree[a]);
	}

public:
	Union_Find(LL n) {
		VLL set(n);
		this->tree = set;
		this->count = set;

		for (LL i = 0; i < n; i++) {
			this->tree[i] = i;
			this->count[i] = 1;
		}
	}

	void unite(LL a, LL b) {
		LL x, y;

		if (!this->Check(a, b)) {
			x = this->getCount(a) + getCount(b);

			y = this->root(a);
			this->count[y] = x;

			y = this->root(b);
			this->count[y] = x;
		}


		x = this->root(a);
		y = this->root(b);

		this->tree[x] = y;

	}

	bool Check(LL a, LL b) {
		return this->root(a) == this->root(b);
	}

	LL getCount(LL index) {
		LL temp = this->root(index);
		return this->count[temp];
	}

};

//プラスマイナス無限に対応したlong long型
class INF_LONG_LONG {
private:
	LL inf, n;

public:

	//コンストラクタ
	INF_LONG_LONG(LL a) {
		this->n = a;
		this->inf = 0;

		this->Syusei();
	}

	INF_LONG_LONG() {
		*this = INF_LONG_LONG(0);
	}

	INF_LONG_LONG(INF_LONG_LONG const& a) {
		this->n = a.n;
		this->inf = a.inf;

		this->Syusei();
	}

	//ゲッター
	LL getN()const {
		return this->n;
	}

	LL getInf()const {
		return this->inf;
	}

	//正の無限大生成
	static INF_LONG_LONG plus_inf() {
		INF_LONG_LONG a;
		a.n = 0;
		a.inf = 1;

		a.Syusei();

		return a;
	}

	//負の無限大生成
	static INF_LONG_LONG minus_inf() {
		INF_LONG_LONG a;
		a.n = 0;
		a.inf = -1;

		a.Syusei();

		return a;
	}

	//符号を取得
	LL sign() const {
		if (this->inf != 0) {
			return this->inf;
		}

		return MYCP::sign(this->n);
	}

	//代入演算子
	INF_LONG_LONG operator=(INF_LONG_LONG const& b) {
		this->n = b.n;
		this->inf = b.inf;

		this->Syusei();

		return *this;
	}

	INF_LONG_LONG operator=(LL const& b) {
		*this = INF_LONG_LONG(b);

		this->Syusei();

		return *this;
	}

	//比較演算子
	bool operator==(INF_LONG_LONG const& b) const {
		if (this->n == b.n&&this->inf == b.inf)return true;

		return false;
	}

	bool operator!=(INF_LONG_LONG const& b)const {
		return !(*this == b);
	}

	bool operator<(INF_LONG_LONG const& b) const {
		if (this->inf < b.inf)return true;

		if (this->inf > b.inf)return false;

		return this->n < b.n;
	}

	bool operator>(INF_LONG_LONG const& b) const {
		return b < *this;
	}

	bool operator<=(INF_LONG_LONG const& b) const {
		return !(*this > b);
	}

	bool operator>=(INF_LONG_LONG const& b) const {
		return !(*this < b);
	}

	//算術演算子
	INF_LONG_LONG operator+(INF_LONG_LONG const& b) const {
		if (max(this->inf, b.inf) > 0)return INF_LONG_LONG::plus_inf();
		if (min(this->inf, b.inf) < 0)return INF_LONG_LONG::minus_inf();

		auto ans = *this;
		ans.n += b.n;

		ans.Syusei();

		return ans;
	}

	INF_LONG_LONG operator*(INF_LONG_LONG const& b) const {

		if (*this == INF_LONG_LONG(0) || b == INF_LONG_LONG(0)) {
			return INF_LONG_LONG(0);
		}

		if (this->inf != 0 || b.inf != 0) {
			LL s = this->sign() * b.sign();

			INF_LONG_LONG ans(0);
			ans.n = 0;
			ans.inf = s;

			ans.Syusei();

			return ans;
		}

		INF_LONG_LONG ans(0);

		ans.n = this->n * b.n;

		ans.Syusei();

		return ans;
	}

	INF_LONG_LONG operator-(INF_LONG_LONG const& b) const {
		auto ans = (*this + (INF_LONG_LONG(-1) * b));
		ans.Syusei();

		return ans;
	}

	INF_LONG_LONG operator/(INF_LONG_LONG const& b)const {
		if (b == INF_LONG_LONG(0)) {
			LL a = this->n / b.n;

			return INF_LONG_LONG(a);
		}

		if (b.inf != 0) {
			return INF_LONG_LONG(0);
		}

		if (*this == INF_LONG_LONG(0)) {
			return INF_LONG_LONG(0);
		}

		if (this->inf != 0) {
			LL s = this->sign() * b.sign();

			return INF_LONG_LONG::plus_inf() * INF_LONG_LONG(s);
		}

		INF_LONG_LONG ans;

		ans.n = this->n / b.n;

		ans.Syusei();

		return ans;
	}

	INF_LONG_LONG operator%(INF_LONG_LONG const& b)const {
		if (this->inf == 0 && b.inf == 0) {
			INF_LONG_LONG ans;

			ans.n = this->n % b.n;

			ans.Syusei();

			return ans;
		}

		auto x = *this / b;
		x.Syusei();
		auto ans = *this - b * x;
		ans.Syusei();

		return ans;
	}

	//複合代入演算子
	INF_LONG_LONG operator+=(INF_LONG_LONG const& b) {
		auto ans = *this + b;
		*this = ans;

		return *this;
	}

	INF_LONG_LONG operator-=(INF_LONG_LONG const& b) {
		auto ans = *this - b;
		*this = ans;

		return *this;
	}

	INF_LONG_LONG operator*=(INF_LONG_LONG const& b) {
		auto ans = *this * b;
		*this = ans;

		return *this;
	}

	INF_LONG_LONG operator/=(INF_LONG_LONG const& b) {
		auto ans = *this / b;
		*this = ans;

		return *this;
	}

	INF_LONG_LONG operator%=(INF_LONG_LONG const& b) {
		auto ans = *this % b;
		*this = ans;

		return *this;
	}

	//符号演算子
	INF_LONG_LONG operator+()const {
		return *this;
	}

	INF_LONG_LONG operator-()const {
		return *this * INF_LONG_LONG(-1);
	}

	//前置きインクリメント・デクリメント
	INF_LONG_LONG operator++() {
		this->n++;
		this->Syusei();

		return *this;
	}

	INF_LONG_LONG operator--() {
		this->n--;
		this->Syusei();

		return *this;
	}

	//後置きインクリメント・デクリメント
	INF_LONG_LONG operator++(int) {
		auto copy = *this;
		++(*this);
		return copy;
	}

	INF_LONG_LONG operator--(int) {
		auto copy = *this;
		--(*this);
		return copy;
	}

	//文字列への変換
	string ToString()const {
		if (this->inf == 1) {
			return "+INF";
		}

		if (this->inf == -1) {
			return "-INF";
		}

		return to_string(this->n);
	}

private:
	void Syusei() {
		if (this->inf != 0) {
			this->n = 0;
		}
	}
};
typedef INF_LONG_LONG ILL_TYPE;
typedef vector<ILL_TYPE> VILL_TYPE;
typedef vector<VILL_TYPE> VVILL_TYPE;

//ワーシャルフロイド
class WarshallFloyd {
public:

	//最短距離を記録
	VVILL_TYPE d;

	//頂点数
	LL v;

	//vは頂点数、edge_cost_listは辺の情報{始点、終点、コスト}の配列。無向グラフの場合、逆矢印の辺に注意。
	WarshallFloyd(LL v, VVLL edge_cost_list) {
		this->v = v;

		this->d = VVILL_TYPE(v, VILL_TYPE(v, ILL_TYPE::plus_inf()));

		LL i, j, k, a, b, c;

		for (i = 0; i < edge_cost_list.size(); i++) {
			a = edge_cost_list[i][0];
			b = edge_cost_list[i][1];
			c = edge_cost_list[i][2];

			this->d[a][b] = ILL_TYPE(c);
		}

		for (i = 0; i < v; i++) {
			this->d[i][i] = ILL_TYPE(0);
		}


		//ここから計算
		for (k = 0; k < v; k++) {
			for (i = 0; i < v; i++) {
				for (j = 0; j < v; j++) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}


	}
};

//ベルマンフォード
class BellmanFord {
public:
	//辺のリスト
	VVILL_TYPE edge;

	//頂点数、辺数
	LL v, e;

	//始点
	LL s;

	//最短距離
	VILL_TYPE d;

	//vは頂点数、startは始点、edge_cost_listは辺の情報{始点、終点、コスト}の配列。
	BellmanFord(LL v, LL start, VVLL edge_cost_list) {
		this->v = v;
		this->s = start;
		this->e = edge_cost_list.size();
		this->d = VILL_TYPE(v, ILL_TYPE::plus_inf());
		this->d[start] = 0;

		LL i, j, k;
		for (i = 0; i < this->e; i++) {
			VILL_TYPE temp;
			LL a, b, c;
			a = edge_cost_list[i][0];
			b = edge_cost_list[i][1];
			c = edge_cost_list[i][2];

			temp.push_back(ILL_TYPE(a));
			temp.push_back(ILL_TYPE(b));
			temp.push_back(ILL_TYPE(c));

			this->edge.push_back(temp);
		}


		this->DoUpdata();

		auto cpy = this->d;

		this->DoUpdata();

		for (i = 0; i < this->d.size(); i++) {
			if (this->d[i] != cpy[i]) {
				this->d[i] = ILL_TYPE::minus_inf();
			}
		}

		this->DoUpdata();
	}

private:
	void DoUpdata() {
		LL i, j, k;
		for (i = 0; i <= this->v; i++) {
			bool update = true;

			for (j = 0; j < this->e; j++) {
				ILL_TYPE c;
				LL a, b;
				a = this->edge[j][0].getN();
				b = this->edge[j][1].getN();
				c = this->edge[j][2];

				if (this->d[a] < ILL_TYPE::plus_inf()) {
					if (this->d[a] + c < this->d[b]) {
						update = false;

						this->d[b] = this->d[a] + c;
					}
				}
			}

			if (update)break;
		}
	}
};

//ダイクストラ
class Dijkstra {
public:
	Dijkstra(LL v, LL start, VVLL edge_cost_list) {

	}
};

//ライブラリはここまで

//ここから下を書く

LL CountA(LL n, LL k, LL b) {
	LL i, j, m;
	if (k >= b) {
		return 0;
	}

	m = n / b * (b - k);
	m += max((LL)0, n % b - max((LL)1, k) + 1);

	return m;
}

//ここからメイン

int main(void) {
	MYCP::DebugFlag = 0;

	LL i, j, k, n, m;
	cin >> n >> k;

	m = 0;
	for (i = 1;i <= n;i++) {
		auto temp = CountA(n, k, i);
		m += temp;
		string s = to_string(i) + " " + to_string(temp);
		MYCP::DebugPrintf(s);
	}

	cout << m << endl;

	return 0;
}
