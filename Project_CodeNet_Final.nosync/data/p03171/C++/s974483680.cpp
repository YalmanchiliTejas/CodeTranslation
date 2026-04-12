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

#define debug if(1)
#define debug2 if(1)
#define debug3 if(1)
#define debug4 if(1)
#define MAXN (int)(3e3)+5

int n;
ll dp[MAXN][MAXN][2];

int main()
{
	readUI(&n);
	for (int i=1; i<=n; ++i)
	{
		readUL(&dp[i][i][0]);
		dp[i][i][1]=-dp[i][i][0];
	}
	for (int dl=2; dl<=n; ++dl)
	{
		for (int i=1; i<=n-dl+1; ++i)
		{
			dp[i][i+dl-1][0]=max(dp[i][i+dl-2][1]+dp[i+dl-1][i+dl-1][0], dp[i+1][i+dl-1][1]+dp[i][i][0]);
			dp[i][i+dl-1][1]=min(dp[i][i+dl-2][0]+dp[i+dl-1][i+dl-1][1], dp[i+1][i+dl-1][0]+dp[i][i][1]);
		}
	}
	fprintf (out, "%lld\n", dp[1][n][0]);
	return 0;
}
/*
*/


