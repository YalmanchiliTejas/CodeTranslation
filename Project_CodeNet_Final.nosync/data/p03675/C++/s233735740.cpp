#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <bitset>
#include <map>

#define rep(i, l, r) for(int i=l; i<=r; i++)
#define dow(i, l, r) for(int i=l; i>=r; i--)
#define clr(x, c) memset(x, c, sizeof(x))
#define travel(x) for(edge *p=fir[x]; p; p=p->n)
#define all(x) (x).begin,(x).end
#define pb push_back
#define fi first
#define se second
#define l(x) Left[x]
#define r(x) Right[x]
#define lowbit(x) (x&-x)

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,int> Pli;
typedef long double ld;
typedef unsigned long long ull;

inline int read()
{
	int x=0; bool f=0; char ch=getchar();
	while (ch<'0' || '9'<ch) f|=ch=='-', ch=getchar();
	while ('0'<=ch && ch<='9') x=x*10+ch-'0', ch=getchar();
	return f?-x:x;
}

/* struct num
{
	int L, a[maxn];
	void input()
	{
		char s[maxn]; clr(s,0); scanf("%s", s);
		L=strlen(s);
		rep(i, 0, L-1) a[i]=s[L-1-i]-'0';
	}
	void output()
	{
		char s[maxn]; clr(s,0);
		rep(i, 0, L-1) s[i]=a[L-1-i]+'0';
		printf("%s", s);
	}
	void dec1()
	{
		a[0]--; 
		rep(i, 0, L-1) if (a[i]<0) a[i]+=10, a[i+1]--;
		if (a[L-1]==0) L--;
	}
	void div2()
	{
		dow(i, L-1, 1) a[i-1]+=(a[i]%2?10:0), a[i]/=2; a[0]/=2;
		if (a[L-1]==0) L--;
	}
	void mult2()
	{
		rep(i, 0, L-1) a[i]*=2;
		rep(i, 0, L-1) if (a[i]>9) a[i]-=10, a[i+1]++;
		if (a[L]) L++;
	}
}; */



#define maxn 200009

int n, A[maxn], B[maxn];

int main()
{
	n=read();
	rep(i, 1, n) A[i]=read();
	for(int i=n,a=1,b=n,c=0; i>=1; i--,c^=1) if (c) B[b--]=A[i]; else B[a++]=A[i];
	rep(i, 1, n) printf("%d ", B[i]);
	return 0;
}