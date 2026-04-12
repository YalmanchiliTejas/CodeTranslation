#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <climits>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <functional>
#include <set>
#include <numeric>
#include <stack>
#include <utility>
#include <time.h>
#include <iterator>
//#include "util.h"

using namespace std;
typedef unsigned uint;
typedef long long lint;
typedef unsigned long long ulint;



//??????
template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const pair<_KTy, _Ty>& m) { cout << "{" << m.first << ", " << m.second << "}"; return ostr; }
template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const map<_KTy, _Ty>& m) { if (m.empty()) { cout << "{ }"; return ostr; } cout << "{" << *m.begin(); for (auto itr = ++m.begin(); itr != m.end(); itr++) { cout << ", " << *itr; } cout << "}"; return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const vector<_Ty>& v) { if (v.empty()) { cout << "{ }"; return ostr; }	cout << "{" << v.front(); for (auto itr = ++v.begin(); itr != v.end(); itr++) { cout << ", " << *itr; }	cout << "}"; return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const set<_Ty>& s) { if (s.empty()) { cout << "{ }"; return ostr; } cout << "{" << *(s.begin()); for (auto itr = ++s.begin(); itr != s.end(); itr++) { cout << ", " << *itr; }	cout << "}"; return ostr; }
//template <typename T> void print(T* v, int N) { if (N == 0) cout << "{ }"; cout << "{" << v[0]; for (int i = 1; i < N; i++) cout << ", " << v[i]; cout << "}"; }
#define PI 3.14159265358979323846
#define EPS 1e-8
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define all(x) (x).begin(), (x).end()

string binary(int n, int len = 32)
{
	string ret;
	for (int i = len - 1; i >= 0; i--) {
		ret.push_back((n & (1 << i)) ? '1' : '0');
	}
	return ret;
}

int main()
{
	map<char, string> ctob;
	for (char ch = 'A'; ch <= 'Z'; ch++) {
		ctob[ch] = binary(ch - 'A', 5);
	}
	ctob[' '] = "11010";		ctob['.'] = "11011";
	ctob[','] = "11100";		ctob['-'] = "11101";
	ctob['\''] = "11110";	ctob['?'] = "11111";


	char alpha[32] = { ' ', '\'', ',', '-', '.', '?' };
	for (int i = 6; i < 32; i++) alpha[i] = char('A' + i - 6);
	string code[32] = {
		"101", "000000", "000011", "10010001", "010001", "000001", "100101", "10011010",
		"0101", "0001", "110", "01001", "10011011", "010000", "0111", "10011000",
		"0110", "00100", "10011001", "10011110", "00101", "111", "10011111", "1000",
		"00110", "00111", "10011100", "10011101", "000010", "10010010", "10010011", "10010000"
	};

	string S;
	while (getline(cin, S)) {
		string src, dst;
		for (int i = 0; i < S.size(); i++) src += ctob[S[i]];
	
		bool flag = true;
		while (flag) {
			flag = false;
			for (int i = 0; i < 32; i++) {
				int len = code[i].size();
				if (len > src.size()) continue;
				if (code[i] == src.substr(0, code[i].size())) {
					dst.push_back(alpha[i]);
					src.erase(src.begin(), src.begin() + len);
					flag = true;
				}
			}
		}
		cout << dst << endl;
	}

	return 0;
}