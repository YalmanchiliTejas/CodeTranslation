#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <cctype>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <complex>
#include <fstream>
#include <iomanip>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
template<class T, class C> void chmax(T& a, C b){ if(a < b) a = b; }
template<class T, class C> void chmin(T& a, C b){ if(b < a) a = b; }
template<class T, class C> pair<T, C> mp(T a, C b){ return make_pair(a, b); }


int main()
{
	map<string, char> t;
	map<char, string> r;

	t.insert(map<string,char>::value_type("101", ' '));
	t.insert(map<string,char>::value_type("000000", '\''));
	t.insert(map<string,char>::value_type("000011", ','));
	t.insert(map<string,char>::value_type("10010001", '-'));
	t.insert(map<string,char>::value_type("010001", '.'));
	t.insert(map<string,char>::value_type("000001", '?'));
	t.insert(map<string,char>::value_type("100101", 'A'));
	t.insert(map<string,char>::value_type("10011010", 'B'));
	t.insert(map<string,char>::value_type("0101", 'C'));
	t.insert(map<string,char>::value_type("0001", 'D'));
	t.insert(map<string,char>::value_type("110", 'E'));
	t.insert(map<string,char>::value_type("01001", 'F'));
	t.insert(map<string,char>::value_type("10011011", 'G'));
	t.insert(map<string,char>::value_type("010000", 'H'));
	t.insert(map<string,char>::value_type("0111", 'I'));
	t.insert(map<string,char>::value_type("10011000", 'J'));
	t.insert(map<string,char>::value_type("0110", 'K'));
	t.insert(map<string,char>::value_type("00100", 'L'));
	t.insert(map<string,char>::value_type("10011001", 'M'));
	t.insert(map<string,char>::value_type("10011110", 'N'));
	t.insert(map<string,char>::value_type("00101", 'O'));
	t.insert(map<string,char>::value_type("111", 'P'));
	t.insert(map<string,char>::value_type("10011111", 'Q'));
	t.insert(map<string,char>::value_type("1000", 'R'));
	t.insert(map<string,char>::value_type("00110", 'S'));
	t.insert(map<string,char>::value_type("00111", 'T'));
	t.insert(map<string,char>::value_type("10011100", 'U'));
	t.insert(map<string,char>::value_type("10011101", 'V'));
	t.insert(map<string,char>::value_type("000010", 'W'));
	t.insert(map<string,char>::value_type("10010010", 'X'));
	t.insert(map<string,char>::value_type("10010011", 'Y'));
	t.insert(map<string,char>::value_type("10010000", 'Z'));

	r.insert(map<char,string>::value_type('A', "00000"));
	r.insert(map<char,string>::value_type('B', "00001"));
	r.insert(map<char,string>::value_type('C', "00010"));
	r.insert(map<char,string>::value_type('D', "00011"));
	r.insert(map<char,string>::value_type('E', "00100"));
	r.insert(map<char,string>::value_type('F', "00101"));
	r.insert(map<char,string>::value_type('G', "00110"));
	r.insert(map<char,string>::value_type('H', "00111"));
	r.insert(map<char,string>::value_type('I', "01000"));
	r.insert(map<char,string>::value_type('J', "01001"));
	r.insert(map<char,string>::value_type('K', "01010"));
	r.insert(map<char,string>::value_type('L', "01011"));
	r.insert(map<char,string>::value_type('M', "01100"));
	r.insert(map<char,string>::value_type('N', "01101"));
	r.insert(map<char,string>::value_type('O', "01110"));
	r.insert(map<char,string>::value_type('P', "01111"));
	r.insert(map<char,string>::value_type('Q', "10000"));
	r.insert(map<char,string>::value_type('R', "10001"));
	r.insert(map<char,string>::value_type('S', "10010"));
	r.insert(map<char,string>::value_type('T', "10011"));
	r.insert(map<char,string>::value_type('U', "10100"));
	r.insert(map<char,string>::value_type('V', "10101"));
	r.insert(map<char,string>::value_type('W', "10110"));
	r.insert(map<char,string>::value_type('X', "10111"));
	r.insert(map<char,string>::value_type('Y', "11000"));
	r.insert(map<char,string>::value_type('Z', "11001"));
	r.insert(map<char,string>::value_type(' ', "11010"));
	r.insert(map<char,string>::value_type('.', "11011"));
	r.insert(map<char,string>::value_type(',', "11100"));
	r.insert(map<char,string>::value_type('-', "11101"));
	r.insert(map<char,string>::value_type('\'', "11110"));
	r.insert(map<char,string>::value_type('?', "11111"));



	string line;
	while(getline(cin, line))
	{
		string res, ret;

        
		rep(i, line.size())
			res += r[line[i]];
		
        
		int head = 0;
		while(true)
		{
			int tail = 3;
			while(t.find(res.substr(head, tail)) == t.end()) 
			{
				tail++;

				if(res.size() < head + tail) goto ng;
			}

			if(t[res.substr(head, tail)] == '\n') cout << res.substr(head, tail) << endl;

			cout << t[res.substr(head, tail)];
			head += tail;
		}
	ng:;
		
		cout << endl;
	}		
}