#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring> 
#include <cmath> 
#include <algorithm>
#include <set> 
using namespace std; 
inline int gi() {
    register int data = 0, w = 1;
    register char ch = 0;
    while (!isdigit(ch) && ch != '-') ch = getchar(); 
    if (ch == '-') w = -1, ch = getchar(); 
    while (isdigit(ch)) data = 10 * data + ch - '0', ch = getchar(); 
    return w * data; 
}

const int MAX_N = 2e5 + 5; 
struct Node { int x, y; } a[MAX_N]; 
bool operator < (const Node &l, const Node &r) { 
	if (l.x == r.x) return l.y < r.y; 
	else return l.x < r.x; 
} 
int N; 
long long ans = 0; 
multiset<int> s1, s2; 

int main () { 
	N = gi(); 
	for (int i = 1; i <= N; i++) {
		int x = gi(), y = gi(); 
		if (x > y) swap(x, y); 
		a[i] = (Node){x, y}; 
	} 
	sort(&a[1], &a[N + 1]); 
	for (int i = 1; i <= N; i++) s2.insert(a[i].y); 
	ans = 1ll * (a[N].x - a[1].x) * (*s2.rbegin() - *s2.begin()); 
	for (int i = 1; i < N; i++) { 
		s2.erase(s2.find(a[i].y)), s1.insert(a[i].y); 
		int mx1 = *s1.rbegin(), mn1 = *s1.begin(); 
		int mx2 = *s2.rbegin(); 
		int Lmax = max(mx1, a[N].x), Lmin = min(mn1, a[i + 1].x); 
		int Rmax = mx2, Rmin = a[1].x; 
		ans = min(ans, 1ll * (Lmax - Lmin) * (Rmax - Rmin)); 
	} 
	printf("%lld\n", ans); 
    return 0; 
} 