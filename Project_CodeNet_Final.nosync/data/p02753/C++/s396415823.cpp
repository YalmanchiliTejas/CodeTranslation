#include <bits/stdc++.h>

using Int = int;
using namespace std;

#define ARC(i, a, b) for(Int i = (a); i < (b); ++i)
#define RC(i, n) ARC(i, 0, n)
#define ARCH(i, a, b) for(Int i = (a) - 1; i >= (b); --i)
#define RCH(i, n) ARCH(i, n, 0)
template<class T> T ant(const T &a, const T &b){ return a > b ? a : b; };
template<class T> T ont(const T &a, const T &b){ return a < b ? a : b; };
template<class T> T th(T &a, const T &b, T (*f)(const T &, const T &)){ a = f(a, b); }
#define anth(a, b) th(a, b, ant)
#define onth(a, b) th(a, b, ont)

int main(){
	std::string str;
	cin >> str;
	cout << (str[0] == str[1] && str[1] == str[2] ? "No" : "Yes") << endl;
}
