#include <bits/stdc++.h>
using namespace std;

//#define getchar getchar_unlocked
//#define putchar putchar_unlocked
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define ff first
#define ss second
#define err stderr
#define out stdout

typedef long long int ll;
typedef long double ld;
typedef short int sh;

inline void readI(int *i)
{
	register int t=0;
	register char z=getchar();
	int znak=1;
	if (z=='-')
	{
		znak=-1;
	}
	while ((z<'0') || ('9'<z))
	{
		z=getchar();
		if (z=='-')
		{
			znak=-1;
		}
	}
	while (('0'<=z) && (z<='9'))
	{
		t=(t<<3)+(t<<1)+z-'0';
		z=getchar();
	}
	*i=(t*znak);
}
inline void readUI(int *i)
{
	register int t=0;
	register char z=getchar();
	while ((z<'0') || ('9'<z))
	{
		z=getchar();
	}
	while (('0'<=z) && (z<='9'))
	{
		t=(t<<3)+(t<<1)+z-'0';
		z=getchar();
	}
	*i=t;
}
inline void readL(ll *l)
{
	register ll t=0;
	register char z=getchar();
	int znak=1;
	if (z=='-')
	{
		znak*=-1;
	}
	while ((z<'0') || ('9'<z))
	{
		z=getchar();
		if (z=='-')
		{
			znak=-1;
		}
	}
	while (('0'<=z) && (z<='9'))
	{
		t=(t<<3)+(t<<1)+z-'0';
		z=getchar();
	}
	*l=(t*znak);
}
inline void readUL(ll *l)
{
	register ll t=0;
	register char z=getchar();
	while ((z<'0') || ('9'<z))
	{
		z=getchar();
	}
	while (('0'<=z) && (z<='9'))
	{
		t=(t<<3)+(t<<1)+z-'0';
		z=getchar();
	}
	*l=t;
}
inline void writeL(ll l)
{
	if (l==0)
	{
		putchar(48);
	}
	else
	{
		if (l<0)
		{
		   l*=-1;
		   putchar(45);
		}
		int _tab[21];
		int wsk=0;
		while (l>0)
		{
			++wsk;
			_tab[wsk]=(l%10)+48;
			l/=10;
		}
		for (int j=wsk; j>=1; --j)
		{
			putchar(_tab[j]);
		}
	}
}
inline void writeS(string s)
{
	int l=s.length();
	for (int i=0; i<l; ++i)
	{
		putchar(s[i]);
	}
}
inline void space()
{
	putchar(32);
}
inline void endl()
{
	putchar(10);
}

#define debug if(0)
#define debug2 if(1)
#define debug3 if(1)
#define debug4 if(1)
#define MAXN (int)(2e5)+5
#define ZAK (1<<19)+5

int n, m, a, b, c, R;
vector <pair <int, int> > v[MAXN];
struct
{
	int lewy;
	int prawy;
	int bonus;
} przedzial[MAXN];
ll dp[MAXN];
ll tree[ZAK], akt[ZAK];
ll INF=(1e18);

void test_tree()
{
	for (int i=1; i<(R<<1); ++i)
	{
		fprintf (err, "i=%d tree[i]=%lld akt[i]=%lld\n", i, tree[i], akt[i]);
	}
}

void insert(int x, int pp, int pk, int zp, int zk, ll war)
{
	if (zk<pp || pk<zp)
	{
		return;
	}
	if (zp<=pp && pk<=zk)
	{
		tree[x]+=war;
		akt[x]+=war;
		return;
	}
	akt[x<<1]+=akt[x];
	akt[x<<1|1]+=akt[x];
	tree[x<<1]+=akt[x];
	tree[x<<1|1]+=akt[x];
	akt[x]=0;
	int sr=((pp+pk)>>1);
	insert(x<<1, pp, sr, zp, zk, war);
	insert(x<<1|1, sr+1, pk, zp, zk, war);
	tree[x]=max(tree[x<<1], tree[x<<1|1]);
}
ll query(int x, int pp, int pk, int zp, int zk)
{
	if (zk<pp || pk<zp)
	{
		return -INF;
	}
	if (zp<=pp && pk<=zk)
	{
		return tree[x];
	}
	akt[x<<1]+=akt[x];
	akt[x<<1|1]+=akt[x];
	tree[x<<1]+=akt[x];
	tree[x<<1|1]+=akt[x];
	akt[x]=0;
	int sr=((pp+pk)>>1);
	return max(query(x<<1, pp, sr, zp, zk), query(x<<1|1, sr+1, pk, zp, zk));
}
int main()
{
	readUI(&n);
	readUI(&m);
	R=1;
	while (R<n+1)
	{
		R<<=1;
	}
	for (int i=1; i<=m; ++i)
	{
		readUI(&a);
		readUI(&b);
		readI(&c);
		przedzial[i]={a, b, c};
		v[a].eb(mp(i, 1));
		v[b+1].eb(mp(i, -1));
	}
	for (int i=1; i<=n+1; ++i)
	{
		int l=v[i].size();
		for (int j=0; j<l; ++j)
		{
			int nr=v[i][j].ff;
			int war=v[i][j].ss;
			insert(1, 0, R, 0, przedzial[nr].lewy-1, przedzial[nr].bonus*war);
		}
		dp[i]=query(1, 0, R, 0, i-1);
		if (i<=n)
		{
			insert(1, 0, R, i, i, dp[i]);
		}
		debug
		{
			fprintf (err, "i=%d dp[i]=%lld\n", i, dp[i]);
			//test_tree();
			fprintf (err, "\n");
		}
	}
	fprintf (out, "%lld\n", tree[1]);
	return 0;
}
/*
*/


