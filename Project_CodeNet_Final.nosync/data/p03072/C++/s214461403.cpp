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
typedef vector<ULL> VULL;

class MYCP {
public:

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

	static LL LeastCommonMultiple(LL a, LL b) {
		return (a / GreatestCommonFactor(a, b))*b;
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

string strnum = "0123456789";
string alpS = "abcdefghijklmnopqrstuvwxyz";
string alpL = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int sizealp = (int)(alpS.size());
int mod = 1e9 + 7;
#define SORT(x) sort(x.begin(),x.end())
#define REVE(x) reverse(x.begin(),x.end())
#define rep(i,n) for(int i=0;i<n;i++)
#define COUT(x) cout<<x<<endl
#define PAI 3.1415926535
string atc = "atcoder";

int main(void) {
	int count = 0;
	int sum = 0;
	int flag = 0;

	int N;
	cin >> N;
	vector<int> H(N);
	rep(i, N)
		cin >> H[i];
	int max=H[0];
	for (int i = 0; i < N; i++) {
		if (H[i] >= max) {
			count++;
			max = H[i];
		}
	}
	cout << count << endl;
}
