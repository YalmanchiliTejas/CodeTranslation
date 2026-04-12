#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <bitset>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

typedef const char *Pos;
long long number(Pos &p) {
	int i;
	long long x;
	sscanf(p, "%lld%n", &x, &i);
	p += i;
	return x;
};

long long factor(Pos &p) {
	long long x = number(p);
	while(*p == '*') {
		++ p;
		long long y = number(p);
		if(x * 1. * y > 1e10) x = INFL;
		else x *= y;
	}
	return x;
};

long long expr(Pos &p) {
	long long x = factor(p);
	while(*p == '+') {
		++ p;
		long long y = factor(p);
		if(x + y > 1e10) x = INFL;
		else x += y;
	}
	return x;
}

long long expr2(Pos &p) {
	long long x = number(p);
	while(*p == '+' || *p == '*') {
		char op = *p;
		++ p;
		long long y = number(p);
		if(op == '*') {
			if(x * 1. * y > 1e10) x = INFL;
			else x *= y;
		}else {
			if(x + y > 1e10) x = INFL;
			else x += y;
		}
	}
	return x;
}


int main() {
	char *s = new char[20];
	scanf("%s", s);
	long long t;
	cin >> t;
	long long x1, x2;
	{	const char *p = s;
		x1 = expr(p);
	}
	{	const char *p = s;
		x2 = expr2(p);
	}
//	cerr << x1 << ", " << x2 << endl;
	if(t == x1 && t != x2)
		puts("M");
	else if(t != x1 && t == x2)
		puts("L");
	else if(t == x1 && t == x2)
		puts("U");
	else
		puts("I");
	return 0;
}