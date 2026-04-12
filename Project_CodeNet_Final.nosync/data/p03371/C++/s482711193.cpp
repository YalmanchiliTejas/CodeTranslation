#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <tuple> 
#include <memory>
#include <random>
#include <iterator>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
constexpr int INF = 2147483647;
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };

//以下はC++の練習のための便利プログラム　あんまり便利じゃないけど…
//------------------------------------------便利型----------------------------------------------
//二次元の点
//TODO map,setのほうが楽かも
template <typename T>
struct Point2D
{
	T x;
	T y;

	friend ostream& operator<<(ostream& os, const Point2D<T>& point);

	bool operator < (const Point2D& right) const
	{
		return (this->x == right.x) ? (this->y > right.y) : (this->x > right.x);
	}
};

ostream& operator<<(ostream& os, const Point2D<int>& point)
{
	os << "(" << point.x << ',' << point.y << ")";
	return os;
}

//長くて読みづらかったのでエイリアステンプレートに
template<class T>
using StdAlloc = std::allocator<T>;
//------------------------------------------便利型----------------------------------------------


//-----------------------------------------便利関数---------------------------------------------
//ユニークな要素数
template <class T>
unsigned long long UniqueElementNum(const vector<T>& data)
{
	auto copy = data;

	sort(begin(copy), end(copy));
	copy.erase(unique(begin(copy), end(copy)), end(copy));

	return copy.size();

	//set<unsigned long long>(begin(copy), end(copy)).size();	//１行版　マクロにしても良い
}

//ある開区間の範囲内かどうか
template <class T>
bool IsIncludeOpen(T x, T min, T max) {
	return (min < x && x < max);
}

//ある閉区間の範囲内かどうか
template <class T>
bool IsIncludeClose(T x, T min, T max) {
	return (min <= x && x <= max);
}

//最小公倍数
long long gcd(long long a, long long b)
{
	long long c;

	if (a < b) {
		a += b; b = a - b; a -= b;
	}

	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

//素数かどうか
bool IsPrime(ULL num)
{
	if (num < 2) return false;
	else if (num == 2) return true;
	else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

	double sqrtNum = sqrt(num);
	for (ULL i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			// 素数ではない
			return false;
		}
	}

	// 素数である
	return true;
}

//素因数分解　試し割り（sqrt(n)まで）
//もっと早い方法もあるらしい…
void DecomposePrime(ULL n, vector<tuple<ULL, ULL>>& result)
{
	vector<ULL> primeList;

	// 割る数の初期値
	ULL a = 2;

	// √n ≧ a ( n ≧ a * a ) の間ループ処理
	while (n >= a * a) {
		// a で割り切れたら、a は素因数
		// そして、割られる数を a で割る
		// a で割り切れなかったら、 a を 1 増加させる
		if (n % a == 0) {
			primeList.emplace_back(a);
			n /= a;
		}
		else {
			a++;
		}
	}
	// 最後に残った n は素因数
	primeList.emplace_back(n);


	//素因数がそれぞれいくつあるかを調べる
	set<ULL> uniquePrimeList(begin(primeList), end(primeList));
	for (const auto& p : uniquePrimeList) {
		ULL primeNum = count(begin(primeList), end(primeList), p);
		result.emplace_back(make_tuple(p, primeNum));
	}
}

//n個からr個取り出す組み合わせの数
template <typename Type>
Type nCr(Type n, Type r) {
	Type ans = 1;
	for (Type i = n; i > n - r; --i) {
		ans = ans*i;
	}
	for (Type i = 1; i < r + 1; ++i) {
		ans = ans / i;
	}
	return ans;
}

//新しい方に対応したい場合、以下を参考にする
//コンテナへ要素を追加
//プリミティブ型など
template<class Num, class Container>
void InitContainer(Num num, Container& container) 
{
	container.resize(num);
	for (auto& d : container) {
		cin >> d;
	}
}

//コンテナへ要素を追加
//Container<Point2D<T>>で特殊化　読みにくい…　マクロにする？
template<class Num, template<class T, class Allocator = StdAlloc<T>> class Container, class T2>
void InitContainer(Num num, Container<Point2D<T2>>& firstContainer)
{
	firstContainer.resize(num);
	for (auto& d : firstContainer) {
		cin >> d.x >> d.y;
	}
}

//コンテナへ要素を追加　を呼び出す処理
template<class Num, class First, class... Rest>
void InitContainer(Num num, First& first, Rest&... rest)
{
	InitContainer(num, first);
	InitContainer(num, rest...);
}

//要素数Nと各要素をコンテナに格納
//コンテナを複数個取れるようにしてみた　テンプレートの練習
template <class Num, class... Container>
void InitNumAndContainer(Num& num, Container&... container)
{
	cin >> num;
	InitContainer(num, container...);
}

//コンテナの内容をstreamへ出力
//今はてきとーにcoutへ改行しながら　果たしてこの書き方は便利なのか…？
//#TODO 引数増やしたりオーバーロード増やしたり
template <template<class T, class Allocator = StdAlloc<T>> class Container, class T>
void ShowContainer(const Container<T>& container)
{
	ostream_iterator<T> outItr(cout, "\n");
	copy(container.begin(), container.end(), outItr);
	cout << endl;
}


//-----------------------------------------便利関数---------------------------------------------

int main()
{
	long A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	long value = 0;

	if (X == 1 && Y == 1) {
		value += std::min(A + B, C * 2);
	}
	else if (X == 1 && Y == 2) {
		value += std::min(A + B * 2, C * 2);
	}
	else if (X == 2 && Y == 1) {
		value += std::min(A * 2 + B, C * 2);
	}
	else if (X == Y) {
		value += min({X * A + Y * B, X * (C * 2)});
	}
	else{
		long v = (X > Y) ? abs(X - Y) * A + Y * (C * 2) : abs(X - Y) * B + X * (C * 2);
		value += min({ X * A + Y * B, max(X, Y) * (C * 2), v });
	}

	cout << value;

	return 0;

	//ULL N, C;
	//cin >> N >> C;

	//vector<
}