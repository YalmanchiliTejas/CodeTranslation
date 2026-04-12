#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
//#include <stdio.h>
//#include <stack>
//#include <queue>
//#include <cstdio>
#include <cmath>
#include <iterator>
#include <map>
//#include <fstream>
//#include <list>
#include <iomanip>
//#include <stdlib.h>
//#include <cctype>

using namespace std;

const int MAX_N = 1000000;
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define prec std::cout << std::fixed << std::setprecision(15);
#define endl "\n"
#define MOD 1000000007
#define Int int64_t
#define PI 3.14159265358979
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define ssort(z) sort(z.begin(), z.end())
#define rsort(z) sort(z.rbegin(), z.rend())
#define eerase(z) z.erase(unique(z.begin(), z.end()), z.end())
#define ccnt(z, w) count(z.begin(), z.end(), w)

void printVec(std::vector<int> & vec)
{
	std::cout << "";
	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << " ";
	}
	cout << '\n';
}
void printVec1(std::vector<string>& vec)
{
	std::cout << "";
	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << " ";
	}
	cout << '\n';
}
void printVec2(std::vector<Int>& vec)
{
	std::cout << "";
	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << " ";
	}
	cout << '\n';
}

Int gcd(Int a, Int b)
{
	return b != 0 ? gcd(b, a % b) : a;
}
Int lcm(Int a, Int b)
{
	return a / gcd(a, b) * b;
	//a*bは64bit integer overflow
}

bool integer(double num)
{
	return floor(num) == num;
}

Int fact(int num)
{
	if (num == 0)
		return 1;
	else
		return num * fact(num - 1);
}

void haerobatya(int start, int end, char level) {
	if (start > end) swap(start, end);
	for (int i = start; i <= end; i++) {
		if (i < 100) {
			cout << "https://atcoder.jp/contests/abc0" << i << "/tasks/abc0" << i << "_" << level << endl;
		}
		else {
			cout << "https://atcoder.jp/contests/abc" << i << "/tasks/abc" << i << "_" << level << endl;
		}
	}
}

Int binary(Int bina) {
	Int ans = 0;
	for (int i = 0; bina > 0; i++)
	{
		ans = ans + (bina % 2) * pow(10, i);
		bina = bina / 2;
	}
	return ans;
}

int main() {
	IOS;
	int n,x; cin>>n;
	vector<int> alpha[26];
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < 26; j++) {
			int h = count(str.cbegin(), str.cend(), 97 + j);
			alpha[j].push_back(h);
		}
		
	}
	string ans = "";
	for (int j = 0; j < 26; j++) {
		ssort(alpha[j]);
		for (int i = 0; i < alpha[j][0]; i++) {
			ans += j + 97;
		}
	}
	cout << ans;

	cout << endl;
	return 0;
}

/*
テレビも無ェ ラジオも無ェ
自動車もそれほど走って無ェ
ピアノも無ェ バーも無ェ
巡査 毎日ぐーるぐる
朝起ぎで 牛連れで
二時間ちょっとの散歩道
電話も無ェ 瓦斯も無ェ
バスは一日一度来る
俺らこんな村いやだ 俺らこんな村いやだ
東京へ出るだ 東京へ出だなら
銭コァ貯めで 東京でベコ(牛)飼うだ
*/
