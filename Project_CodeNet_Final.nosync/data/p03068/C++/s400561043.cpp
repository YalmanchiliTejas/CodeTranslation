#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include <algorithm>
#include <functional>
#include <cctype>
#include <sstream>
#include <numeric>
#include <map>
#include <initializer_list>
#include <exception>
#include <deque>
#include <climits>
using namespace::std;
typedef long long lint;
typedef long double ldouble;
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define repi(i,a,b) for(lint i=lint(a);i<lint(b);i++)
#define rep2(i,a,b,c) for(lint i=lint(a);i>lint(b);i+=c)
#define all(x) (x).begin(),(x).end()
#define sl(c) (('a')<=(c)&&(c)<=('z'))
#define ll(c) (('A')<=(c)&&(c)<=('Z'))
#define PI 3.141592653589793
#define cout (cout<<fixed<<setprecision(15))
#define makeupper(t) (transform(all(t),t.begin(),::toupper))
#define makelower(t) (transform(all(t),t.begin(),::tolower))
#define dist(x1,y1,x2,y2) (pow(pow(x2-x1,2)+pow(y2-y1,2),0.5))
#define sum(a) accumulate(all(a),0)
#define NEXT_LINE string junk; getline(cin, junk);
#define output(v,s) do{rep(i,v.size())cout<<(i?s:"")<<v[i];cout<<"\n";}while(0)
#define LINT_MAX numeric_limits<lint>::max()
inline string replace(string str, string before, std::string after) {
	string::size_type  Pos(str.find(before));
	while (Pos != std::string::npos) {
		str.replace(Pos, before.length(), after);
		Pos = str.find(before, Pos + after.length());
	}
	return str;
}
inline vector<string> split(string &s, string delim) {
	vector<string> elems;
	s = replace(s, "#", "HASH");
	s = replace(s, delim, "#");
	stringstream ss(s);
	string item;
	while (getline(ss, item, '#')) {
		elems.push_back(replace(item, "HASH", "#"));
	}
	return elems;
}
inline vector<int> cross(vector<int> a, vector<int> b) {
	return { a[1] * b[2] - a[2] * b[1],a[2] * b[0] - a[0] * b[2],a[0] * b[1] - a[1] * b[0] };
}
inline int GCD(int a, int b) {
	if (a < b)swap(a, b);
	if (a%b != 0)GCD(b, a%b);
	else return b;
}
inline vector<lint> primeList(lint n) {
	vector<bool> p(n + 1);
	vector<lint> list;
	repi(i, 1, n + 1)p[i] = true;
	repi(i, 2, sqrt(n) + 1) {
		if (p[i]) {
			repi(j, 2, n / i + 1) {
				p[i*j] = false;
			}
		}
	}
	repi(i, 2, n + 1)if (p[i])list.push_back(i);
	return list;
}
inline bool isPrime(int num) {
	if (num < 2) return false;
	else if (num == 2) return true;
	else if (num % 2 == 0) return false;
	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2) {
		if (num % i == 0)return false;
	}
	return true;
}
template<typename T>class Stack {
	vector<T> stack;
public:
	void push(T num) {
		stack.push_back(num);
	}
	T pop() {
		T num = stack[stack.size() - 1];
		stack.erase(stack.end() - 1);
		return num;
	}
	bool empty() {
		return stack.empty();
	}
};
template<typename T>class Queue {
	deque<T> queue;
public:
	void push(T num) {
		queue.push_front(num);
	}
	void push_back(T num) {
		queue.push_back(num);
	}
	T pop() {
		T num = queue[queue.size() - 1];
		queue.pop_back();
		return num;
	}
	bool empty() {
		return queue.empty();
	}
};
inline vector<lint> decimalConversion(lint val, lint n) {
	vector<lint> v;
	while (1) {
		if (val == 0)break;
		v.push_back(val%n);
		val %= n;
	}
	reverse(all(v));
	return v;
}
inline vector<lint> decimalConversion(lint val,lint n,lint size) {
	vector<lint> v;
	while (1) {
		if (val == 0)break;
		v.push_back(val%n);
		val %= n;
	}
	v.resize(n, 0);
	reverse(all(v));
	return v;
}
int main() {
	lint n,k;
	string s;
	cin >> n >> s >> k;
	rep(i, s.size())if (s[i] != s[k - 1])s[i] = '*';
	cout << s << "\n";
}