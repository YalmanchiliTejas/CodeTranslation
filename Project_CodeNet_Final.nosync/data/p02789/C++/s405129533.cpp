//=========================
//  author:hliwen
//  date:2020.1.19
//=========================
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define DEBUG puts("ok")
#define tie0 cin.tie(0),cout.tie(0)
#define fastio ios::sync_with_stdio(false)
#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
typedef long long ll;

template <typename T> inline void read(T &x) {
	T f = 1; x = 0; char c;
    for (c = getchar(); !isdigit(c); c = getchar()) if (c == '-') f = -1;
    for ( ; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    x *= f;
}

int main() {
	int n, m;
	read(n), read(m);
	if (m < n) puts("No");
	else puts("Yes");
	return 0;
}
