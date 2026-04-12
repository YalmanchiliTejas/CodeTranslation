#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<numeric>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;

class MYCP {
public:

	//数値を区切って文字列にする
	static string MakeString_LongLong(vector<long long> const& numbers,string const& str) {
		if (numbers.size() == 0)return "";
		string result = "" + to_string(numbers[0]);
		for (long long i = 1;i < numbers.size();i++) {
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
		for (long long i = 0;i < n;i++) {
			std::cin >> str[i];
		}

		return str;
	}

	//数値を必要な個数だけ読み取る
	static vector<long long> ReadInts(long long number) {
		vector<long long> a(number);
		for (int i = 0;i < number;i++) {
			std::cin >> a[i];
		}

		return a;
	}

	//渡された自然数が素数ならtureを返す
	static bool PrimeCheck_Int(long long number) {
		if (number < 2)return false;

		for (ULL i = 2;i*i <= number;i++) {
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

	//最初に呼び出す
	static void SetUp() {
		cin.tie(0);
		ios::sync_with_stdio(false);
	}
};

//累積和を求めるクラス
class Syakutori {
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
			cout << "startがendより大きいです";
			return 0;
		}
		if (start < 0 || end >= list.size()) {
			cout << "範囲が異常";
			return 0;
		}

		return list[end] - list[start];
	}




};

LL maxD(vector<double> a) {
	LL i, result;
	double max;

	result = 0;
	max = a[0];

	for (i = 0; i < a.size(); i++) {
		if (max < a[i]) {
			max = a[i];
			result = i;
		}
	}

	return result;
}

LL minLL(VLL a) {
	LL i, result;
	LL min;

	result = 0;
	min = a[0];

	for (i = 0; i < a.size(); i++) {
		if (min > a[i]) {
			min = a[i];
			result = i;
		}
	}

	return result;
}

LL function(LL score, LL i, LL p, LL c) {
	LL j, count = 0;

	for (j = 1; j <= p; j++) {
		count += i * 100;
		if (score <= count)return j;
	}

	return p;
}

class Field {
private:
	vector<VLL> map;
	LL h, w;

public:
	Field(LL h1, LL w1, vector<string> s) {
		h = h1;
		w = w1;

		if (true) {
			VLL temp(w);
			for (LL i = 0; i < h; i++) {
				map.push_back(temp);
			}
		}

		LL i, j;
		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
				if (s[i][j] == '.')map[i][j] = 0;
				else map[i][j] = 1;
			}
		}
	}

	bool change1() {
		LL i, j, c, a, b;

		for (i = 0; i < h; i++) {
			c = 0;
			for (j = 0; j < w; j++) {
				if (map[i][j] == 0)c++;
			}
			if (c == w)goto r;
		}

		return false;

	r:
		vector<VLL> temp;
		for (a = 0; a < h; a++) {
			if (a != i) {
				auto temp1 = map[a];
				temp.push_back(temp1);
			}
		}
		h--;
		map = temp;
		return true;
	}

	bool change2() {
		LL i, j, c, a, b;
		for (j = 0; j < w; j++) {
			c = 0;
			for (i = 0; i < h; i++) {
				if (map[i][j] == 0)c++;
			}

			if (c == h)goto r;
		}

		return false;

	r:
		vector<VLL> temp;
		for (a = 0; a < h; a++) {
			VLL z;
			for (b = 0; b < w; b++) {
				if (b != j) {
					z.push_back(map[a][b]);
				}
			}
			temp.push_back(z);
		}

		w--;
		map = temp;
		return true;
	}

	string makeString() {
		vector<string> result;
		LL i, j, a, b;
		for (i = 0; i < h; i++) {
			string s;
			for (j = 0; j < w; j++) {
				if (map[i][j] == 0)s += ".";
				else s += "#";
			}

			result.push_back(s);
		}

		string s;
		for (i = 0; i < h; i++) {
			s += result[i];
			if (i != h - 1)s += "\n";
		}

		return s;
	}
};

int main(void) {
	MYCP::SetUp();
	LL i, j, k, n, m, h, w;
	vector<string> s;
	string temp;
	cin >> h >> w;
	for (i = 0; i < h; i++) {
		cin >> temp;
		s.push_back(temp);
	}
	bool a, b;
	a = true;
	b = true;

	Field field(h, w, s);


	while (a||b)
	{
		a = field.change1();
		b = field.change2();
	}

	cout << field.makeString() << endl;
	cin >> h;
}