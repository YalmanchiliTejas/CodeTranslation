#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<numeric>
#include<list>
#include<stack>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<ULL> VULL;
typedef vector<VLL> VVLL;

class MYCP {
public:

	static const LL MOD_CONST_ATCODER = 1000 * 1000 * 1000 + 7;

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
	static LL Sum(vector<LL> a) {
		LL i, sum = 0;

		for (i = 0; i < a.size(); i++) {
			sum += a[i];
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

	//最大公約数
	static LL GreatestCommonFactor(LL a, LL b) {
		LL temp;
		if (a < b) {
			temp = b;
			b = a;
			a = temp;
		}

		while (true)
		{
			temp = a % b;
			a = b;
			b = temp;
			if (b == 0)break;
		}

		return a;
	}

	//最小公倍数
	static LL LeastCommonMultiple(LL a, LL b) {
		return (a / GreatestCommonFactor(a, b))*b;
	}

	//素因数分解
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
	static LL sign(LL x) {
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

	//数値の出力
	static void CoutVectorLL(VLL list) {
		LL i, j, k, n;
		n = list.size();

		for (i = 0; i < n - 1; i++) {
			cout << list[i] << " ";
		}

		cout << list[n - 1] << flush;
	}

	//VLLの配列をソートする
	static void Sort_VLL(VVLL & x, LL n) {
		auto function = [&](VLL a, VLL b) {
			return a[n] < b[n];
		};

		sort(x.begin(), x.end(), function);
	}

	//デバッグ用出力
	static LL DebugPrintf(string output) {

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

		if (!this->Check(a,b)) {
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

LL Cal_Dis(LL a, LL b, LL c) {
	return abs(a - b) + abs(b - c);
}

LL Saitan(VLL const& list, LL target) {
	auto itr1 = lower_bound(list.begin(), list.end(), target);
	auto itr2 = itr1;

	if (itr1 == list.begin()) {
		return distance(list.begin(), itr1);
	}

	if (itr1 == list.end()) {
		itr2--;
		return distance(list.begin(), itr2);
	}

	itr2--;
	if (abs(*itr1 - target) < abs(*itr2 - target)) {
		return distance(list.begin(), itr1);
	}

	return distance(list.begin(), itr2);
}


//ここからメイン
int main(void) {
	MYCP::DebugFlag = 0;

	LL i, j, k, n, m;
	auto a = MYCP::ReadInts(3);
	k = 0;
	for (i = 0; i < 3; i++) {
		k *= 10;
		k += a[i];
	}

	if (k % 4 == 0)cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}