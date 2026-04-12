#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<queue>
#include<cstdlib>
#include<ctime>
#define rep(i,j,k) for(register int i = j; i <= k; i++)
#define dow(i,j,k) for(register int i = j; i >= k; i--)
#define ll long long
using namespace std;
 
inline int read() {
	int s = 0, t = 1; char c = getchar();
	while( !isdigit(c) ) { if( c == '-' ) t = -1; c = getchar(); }
	while( isdigit(c) ) s = s * 10 + c - 48, c = getchar();
	return s * t;	
} 

const int N = 1e5+5, p = 1e9+7;
inline void Min(int &x,int v) { if( x > v ) x = v; }
struct node{ int x, y, id; } A[N];
inline bool cmp1(const node&a,const node&b) { 
	return a.x < b.x;
}
inline bool cmp2(const node&a,const node&b) { 
	return a.y < b.y;
}
struct edge{ 
	int x, y, v; bool operator < (const edge&rhs) const { return v < rhs.v; }
} e[N<<1];
int fa[N];
inline int find(int x) { 
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
	int n = read(), cnt = 0;
	rep(i,1,n) A[i].x = read(), A[i].y = read(), fa[i] = A[i].id = i;
	sort(A+1,A+n+1,cmp1);
	rep(i,1,n-1) e[++cnt].x = A[i].id, e[cnt].y = A[i+1].id, e[cnt].v = A[i+1].x - A[i].x;
	sort(A+1,A+n+1,cmp2);
	rep(i,1,n-1) e[++cnt].x = A[i].id, e[cnt].y = A[i+1].id, e[cnt].v = A[i+1].y - A[i].y;
	
	sort(e+1,e+cnt+1);
	int x, y, tot = 0; ll ans = 0;
	rep(i,1,cnt) { 
		x = find(e[i].x), y = find(e[i].y);
		if( x != y ) { 
			ans += e[i].v, fa[x] = y, tot++;
			if( tot == n - 1 ) break;
		}
	}
	cout<<ans<<endl;
    return 0;
} 