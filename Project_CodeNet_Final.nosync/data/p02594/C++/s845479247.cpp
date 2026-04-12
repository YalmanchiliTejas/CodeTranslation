#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<numeric>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#include<map>
#include<functional>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<ULL> VULL;
typedef vector<VLL> VVLL;

class Large_Integer {
private:
	//n進数
	static const LL shinsuu = 7;

	//符号付絶対値で表現
	LL sign;
	VLL numbers;

	//補数表現された整数の足し算
	static VLL plusVector(VLL a, VLL b) {
		VLL ans(max(a.size(), b.size()), 0);

		for (LL i = 0; i < ans.size(); i++) {
			if (i < a.size())ans[i] += a[i];
			if (i < b.size())ans[i] += b[i];

			if (i + 1 < ans.size()) {
				ans[i + 1] += (ans[i] / Large_Integer::shinsuu);
			}

			ans[i] %= Large_Integer::shinsuu;
		}

		return ans;
	}

	//符号付絶対値を補数表現に変換
	static VLL ToVLL(Large_Integer const& a, LL const& min) {
		LL i;
		VLL ans;
		if (a.sign == 1) {
			ans = VLL(max(min, (LL)a.numbers.size()) + 5, 0);
			for (i = 0; i < a.numbers.size(); i++) {
				ans[i] += a.numbers[i];
			}
		}

		else
		{
			ans = VLL(max(min, (LL)a.numbers.size()) + 5, Large_Integer::shinsuu - 1);
			for (i = 0; i < a.numbers.size(); i++) {
				ans[i] -= a.numbers[i];
			}
			ans = Large_Integer::plusVector(ans, VLL(1, 1));
		}

		return ans;
	}

	//補数表現を符号付き絶対値に変換
	static Large_Integer ToInteger(VLL const& a) {
		Large_Integer ans;
		LL i, j, k, n;
		n = a.size();

		if (a[n - 1] == Large_Integer::shinsuu - 1) {
			auto temp = VLL(n, Large_Integer::shinsuu - 1);
			temp = Large_Integer::plusVector(a, temp);
			//ここから

			for (i = 0; i < temp.size(); i++) {
				temp[i] -= Large_Integer::shinsuu;
				temp[i] *= -1;
			}

			ans.sign = -1;
			ans.numbers = temp;
			ans.Syusei();
		}

		else
		{
			ans.sign = 1;
			ans.numbers = a;
			ans.Syusei();
		}

		return ans;
	}


	//シフト演算子
	Large_Integer operator<<(Large_Integer const& a)const {
		LL shift = a.to_LongLong(), i;
		if (shift < 0) {
			return *this >> (shift * -1);
		}

		Large_Integer ans = *this;

		ans.numbers = VLL(this->numbers.size() + shift, 0);

		for (i = 0; i < this->numbers.size(); i++) {
			ans.numbers[i + shift] += this->numbers[i];
		}

		ans.Syusei();

		return ans;
	}

	Large_Integer operator>>(Large_Integer const& a)const {
		LL shift = a.to_LongLong(), i;
		if (shift < 0) {
			return *this << (shift * -1);
		}

		Large_Integer ans = *this;

		ans.numbers = VLL(max((LL)0, (LL)this->numbers.size() - shift), 0);

		for (i = 0; i < this->numbers.size(); i++) {
			if (i - shift >= 0) {
				ans.numbers[i - shift] = this->numbers[i];
			}
		}

		ans.Syusei();

		return ans;
	}


	//掛け算(long long)
	Large_Integer operator*(LL const& b)const {
		Large_Integer ans;

		ans.sign = this->sign;
		ans.numbers = VLL(this->numbers.size() + 2, 0);

		LL i, a = b;

		if (a < 0) {
			a *= -1;
			ans.sign *= -1;
		}

		for (i = 0; i < this->numbers.size(); i++) {
			ans.numbers[i] = a * this->numbers[i];
		}

		for (i = 0; i < ans.numbers.size(); i++) {
			if (i + 1 < ans.numbers.size()) {
				ans.numbers[i + 1] = (ans.numbers[i] / Large_Integer::shinsuu);
			}

			ans.numbers[i] %= Large_Integer::shinsuu;
		}

		return ans;
	}

	//誤りの検知と修正
	void Syusei() {
		LL i, j, k;

		if (abs(this->sign) != 1) {
			j = 0;
			j = 1 / j;
		}

		k = 0;

		for (i = 0; i < this->numbers.size(); i++) {
			if (this->numbers[i] < 0) {
				j = 0;
				j = 1 / j;
			}

			if (i + 1 < this->numbers.size()) {
				this->numbers[i + 1] += (this->numbers[i] / Large_Integer::shinsuu);
			}
			this->numbers[i] %= Large_Integer::shinsuu;

			if (this->numbers[i] > 0)k = i + 1;
		}


		VLL ans(k, 0);

		for (i = 0; i < k; i++) {
			ans[i] = this->numbers[i];
		}

		this->numbers = ans;

		if (this->sign == -1 && this->numbers.size() == 0) {
			this->sign = 1;
		}
	}


public:
	//コンストラクタたち
	Large_Integer(Large_Integer const& b) {
		*this = b;
	}

	Large_Integer(LL const& b) {
		if (b < 0)this->sign = -1;
		else this->sign = 1;

		auto c = abs(b);

		while (c > 0)
		{
			this->numbers.push_back(c % this->shinsuu);
			c /= this->shinsuu;
		}

		this->Syusei();
	}

	Large_Integer() {
		this->sign = 1;
		this->numbers = VLL(0);
	}

	//long long型に変換する
	LL to_LongLong()const {
		LL ans = 0, i;

		for (i = this->numbers.size() - 1; i >= 0; i--) {
			ans *= this->shinsuu;
			ans += this->numbers[i];
		}

		ans *= this->sign;

		return ans;
	}

	//代入演算子
	Large_Integer operator=(Large_Integer const& b) {
		this->sign = b.sign;
		this->numbers = b.numbers;

		return *this;
	}


	//足し算
	Large_Integer operator+(Large_Integer const& b)const {
		LL i, j;

		VLL x, y;
		LL size = max(this->numbers.size(), b.numbers.size());

		x = Large_Integer::ToVLL(*this, size);
		y = Large_Integer::ToVLL(b, size);

		x = Large_Integer::plusVector(x, y);

		auto ans = Large_Integer::ToInteger(x);
		ans.Syusei();

		return ans;
	}

	Large_Integer operator+=(Large_Integer const& b) {
		return *this = (*this + b);
	}

	//掛け算
	Large_Integer operator*(Large_Integer const& b)const {
		Large_Integer ans = 0;
		LL i;

		for (i = 0; i < b.numbers.size(); i++) {
			ans += ((*this * b.numbers[i]) << i);
		}

		return ans;

	}

	Large_Integer operator*=(Large_Integer const& b) {
		return *this = (*this * b);
	}

	Large_Integer operator-(Large_Integer const& b)const {
		return *this + (b * -1);
	}

	Large_Integer operator-=(Large_Integer const& b) {
		return *this = (*this - b);
	}

	//未完成
	bool operator<(Large_Integer const& b)const {
		LL i, j, k;

		if (this->sign < b.sign) {
			return true;
		}
		if (this->sign > b.sign) {
			return false;
		}

		if (this->sign == 1) {
			if (this->numbers.size() < b.numbers.size()) {
				return true;
			}
			if (this->numbers.size() > b.numbers.size()) {
				return false;
			}

			for (i = this->numbers.size() - 1; i >= 0; i--) {
				if (this->numbers[i] < b.numbers[i]) {
					return true;
				}
				if (this->numbers[i] > b.numbers[i]) {
					return false;
				}
			}
		}
	}

};

//改良vector
template<typename T>
class ArrayList :public vector<T> {
public:
	ArrayList(long long const& size, T const& a) :vector<T>(size, a) {

	}

	ArrayList(long long const& size) :vector<T>(size) {

	}

	ArrayList() :vector<T>() {

	}

	T& operator[](long long const& index) {
		return vector<T>::at(index);
	}
};

typedef ArrayList<LL> ALL;
typedef ArrayList<ALL> AALL;

//剰余整数
class ModInt {
private:
	LL n;
	static LL modP;
public:

	ModInt(ModInt const& b) {
		this->n = b.n;
	}

	ModInt(LL const& b) {
		this->n = b % ModInt::modP;
	}

	ModInt() {
		*this = ModInt(0);
	}

	LL GetMod()const {
		return ModInt::modP;
	}

	void SetMod(LL const& a) {
		ModInt::modP = abs(a);
	}

	LL getNumber()const {
		return this->n;
	}

	ModInt operator=(ModInt const& b) {
		this->n = b.n;
		return *this;
	}

	ModInt operator+(ModInt const& b)const {
		return ModInt(this->n + b.n);
	}

	ModInt operator+=(ModInt const& b) {
		return *this = (*this + b);
	}

	ModInt operator-(ModInt const& b)const {
		LL temp = this->n - b.n + ModInt::modP;
		return ModInt(temp);
	}

	ModInt operator-=(ModInt const& b) {
		return *this = (*this - b);
	}

	ModInt operator*(ModInt const& b)const {
		LL temp = this->n * b.n;
		return ModInt(temp);
	}

	ModInt operator*=(ModInt const& b) {
		return *this = (*this * b);
	}

	ModInt Pow(ModInt const& b)const {
		LL p = b.n;
		ModInt ans = 1;
		ModInt x = *this;

		while (p > 0)
		{
			if (p % 2 == 1) {
				ans *= x;
			}
			x = x * x;
			p /= 2;
		}

		return ans;
	}

	ModInt operator/(ModInt const& b)const {
		ModInt temp = b.Pow(ModInt::modP - 2);
		return *this * temp;
	}

	ModInt operator/=(ModInt const& b) {
		return *this = (*this / b);
	}
};
LL ModInt::modP = 1000 * 1000 * 1000 + 7;

//関数詰め合わせ
class KyoPro {
public:

	static const LL MOD_CONST = (LL)1000 * 1000 * 1000 + 7;

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

		for (ULL i = 2; i * i <= number; i++) {
			if (number % i == 0)return false;
		}

		return true;
	}

	//自然数が平方数か判定する
	static bool SquareCheck(LL const& number) {
		if (KyoPro::PrimeCheck_Int(number))return false;

		LL m = number;

		for (LL i = 2; i <= m; i++) {
			if (m % i == 0) {
				LL count = 0;
				while (m % i == 0)
				{
					m /= i;
					count++;
				}

				if (count % 2 == 1)return false;
			}
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

				if (i % list[j] == 0) {
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
		if (a >= 'a' && a <= 'z')return true;

		return false;
	}

	//大文字ならtrueを返す
	static bool Oomoji(char a) {
		if (a >= 'A' && a <= 'Z')return true;

		return false;
	}

	//切り上げの整数値割り算
	static LL KiriageWarizan(LL a, LL b) {
		LL result = a / b;

		if (a % b > 0)result++;

		return result;
	}

	//最大公約数を求める
	static LL GreatestCommonFactor(LL a, LL b) {
		a = KyoPro::abs(a);
		b = KyoPro::abs(b);

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
		return (a / GreatestCommonFactor(a, b)) * b;
	}

	//二次元配列を行列とみなして転置する
	static VVLL VVLLturn(VVLL a) {

		if (a.size() == 0)return VVLL(0);

		VVLL result(a[0].size(), VLL(a.size()));
		LL i, j;
		for (i = 0; i < a.size(); i++) {
			for (j = 0; j < a[0].size(); j++) {
				result[j][i] = a[i][j];
			}
		}

		return result;
	}

	//素因数分解、素数、指数の順
	static vector<VLL> PrimeFactorization(LL n) {
		VLL p_list, s_list;

		LL i, j, k, count;

		for (i = 2; n > 1; i++) {
			if (i * i > n) {
				p_list.push_back(n);
				s_list.push_back(1);
				break;
			}

			if (n % i == 0) {
				count = 0;
				while (n % i == 0)
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

		return KyoPro::VVLLturn(result);
	}

	//整数nの約数の配列を作る
	static VLL MakeYakusuList(LL n) {
		auto primes = KyoPro::PrimeFactorization(n);
		VLL ans;
		VLL roop(primes.size(), 0);

		LL i, j, k, m, size = roop.size();

		while (true)
		{
			LL a = 1;

			for (i = 0; i < size; i++) {
				for (j = 0; j < roop[i]; j++) {
					a *= primes[i][0];
				}
			}

			ans.push_back(a);

			roop[0]++;

			for (i = 0; i < size; i++) {
				if (i + 1 < size) {
					roop[i + 1] += (roop[i] / (primes[i][1] + 1));
				}
				roop[i] %= (primes[i][1] + 1);
			}

			bool flag = true;
			for (i = 0; i < size; i++) {
				if (roop[i] != 0)flag = false;
			}

			if (flag)break;
		}

		return KyoPro::Sort(ans);
	}

	//組み合わせ nCrを10^9+7で割った余りを返す
	static LL Combination(LL n, LL r) {
		ModInt ans = 1;
		r = min(r, n - r);

		for (LL i = 0; i < r; i++) {
			ans *= (n - i);
			ans /= (i + 1);
		}

		return ans.getNumber();
	}

	//順列 nPrを10^9+7で割った余りを返す
	static LL Permutation(LL n, LL r) {
		ModInt ans = 1;
		for (LL i = 0; i < r; i++) {
			ans *= (n - i);
		}

		return ans.getNumber();
	}

	//重複組み合わせ。n種類からr個重複を許して選ぶ
	static LL nHr(LL n, LL r) {
		return KyoPro::Combination(n + r - 1, r);
	}

	template<typename T>
	static T pow(T const& a, LL const& b) {
		T ans = 1;
		auto p = b;
		auto x = a;

		while (p > 0) {
			if (p % 2 == 1) {
				ans *= x;
			}
			x = x * x;
			p /= 2;
		}

		return ans;
	}

	//符号
	template<typename T>
	static  T sign(T const& x) {
		if (x > 0)return 1;
		if (x < 0)return -1;
		return 0;
	}

	//絶対値
	template<typename T>
	static T abs(T x) {
		if (x < 0) {
			x = x * -1;
		}
		return x;
	}

	//円周率
	static double PI() {
		return (double)3.1415926535898;
	}

	//指定した桁でdoubleを出す。改行はしない。
	static void CoutDoubleKeta(double a, LL keta) {
		cout << setprecision(keta) << a << flush;
	}

	//コンテナクラスの出力
	template<typename T>
	static T CoutVector(T const& ls) {
		LL i, j, k, size = distance(ls.begin(), ls.end());

		if (size == 0)return ls;

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
	static T Sort(T& ls) {
		sort(ls.begin(), ls.end());

		return ls;
	}

	//順序関数付きでコンテナクラスをソートする
	template<typename T, typename F>
	static T Sort(T& ls, F const& func) {
		sort(ls.begin(), ls.end(), func);

		return ls;
	}

	//コンテナクラスを逆順に並び替える
	template<typename T>
	static T Reverse(T& ls) {
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
	static T AllUpdate(T& ls, S func) {
		auto itr = ls.begin();
		while (itr != ls.end()) {
			*itr = func(*itr);
			itr++;
		}
		return ls;
	}

	//リストをベクターに変換する
	template<typename T>
	static vector<T> FromListToVector(list<T> const& a) {
		vector<T> ans;
		for (auto itr = a.begin(); itr != a.end(); itr++) {
			ans.push_back(*itr);
		}

		return ans;
	}

	//ベクターをリストに変換する
	template<typename T>
	static list<T> FromVectorToList(vector<T> a) {
		list<T> ans;
		for (auto itr = a.begin(); itr != a.end(); itr++) {
			ans.push_back(*itr);
		}

		return ans;
	}

	//最大値の要素番号を求める
	template<typename T>
	static LL MaxElementIndex(T const& ls) {
		return distance(ls.begin(), max_element(ls.begin(), ls.end()));
	}

	//最小値の要素番号を求める
	template<typename T>
	static LL MinElementIndex(T const& ls) {
		return distance(ls.begin(), min_element(ls.begin(), ls.end()));
	}

	//デバッグ用出力
	template<typename T>
	static LL DebugPrintf(T output) {

		if (KyoPro::DebugFlag) {
			std::cout << output << endl;
		}

		return KyoPro::DebugFlag;
	}

	//デバッグ用入力
	static  LL DebugCin() {
		LL a;

		if (KyoPro::DebugFlag) {
			cin >> a;
		}

		return a;
	}
};
LL KyoPro::DebugFlag = 0;

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

		k = KyoPro::KiriageWarizan(zettaiti, this->N_Shinsuu);
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

	LL getRoot(LL index) {
		return this->root(index);
	}

	VLL getList() {
		VLL ans(this->tree.size(), 0);
		for (LL i = 0; i < ans.size(); i++) {
			ans[i] = this->root(i);
		}

		return ans;
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

		return KyoPro::sign(this->n);
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
		if (this->n == b.n && this->inf == b.inf)return true;

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

//ここからメイン

int main(void) {
	KyoPro::DebugFlag = 0;

	LL x;
	cin >> x;

	if (x >= 30) {
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	return 0;
}