#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define cs const 
#define fr first 
#define se second
#define ls (now<<1)
#define mid ((l+r)>>1)
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define low(i) (i&(-i))
#define par pair<int,int>
#define cn(x) memset(x, 0, sizeof(x))
#define rep(i, x, y) for(int i=x; i<=y; ++i)
#define sep(i, x, y) for(int i=x; i>=y; --i)
#define fore(i, x) for(int i=fir[x]; i; i=nex[i])

cs int G = 3;
cs int N = 2e5;
cs int ff = 1e6 + 15;
cs int inf = 1e18 + 1;
cs int base = 2333;
cs int M = 998244353;
cs double eps = 1e-14;

struct Node { int x, id; } A[ff];
bool operator < (Node B, Node C) { return B.x < C.x; }
int n, Ans[ff];
void init()
{
	cin >> n;
	rep(i, 1, n) scanf("%lld", &A[i].x), A[i].id = i;
	int md = n / 2;
	sort(A + 1, A + 1 + n);
	rep(i, 1, md) Ans[A[i].id] = A[md + 1].x;
	rep(i, md + 1, n) Ans[A[i].id] = A[md].x;
	rep(i, 1, n) cout << Ans[i] << "\n";
}
signed main()
{
	int Ts = 1;
	while(Ts--)
		init();
}