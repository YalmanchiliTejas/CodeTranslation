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
#define MAXN (int)(1e4)+5

char s[MAXN];
int d, n, m, sc;
ll dp[MAXN][11][101];
ll P=(1e9)+7, wynik;
ll pot[MAXN];

void test_dp()
{
	for (int i=1; i<=n; ++i)
	{
		for (int j=0; j<10; ++j)
		{
			for (int m=0; m<d; ++m)
			{
				fprintf (err, "i=%d j=%d m=%d dp[i][j][m]=%lld\n", i, j, m, dp[i][j][m]);
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	cin >> d;
	n=strlen(s);
	for (int i=n; i>=1; --i)
	{
		s[i]=s[i-1];
		sc+=int(s[i])-48;
	}
	if (n==1)
	{
		for (int i=1; i<=int(s[n])-48; ++i)
		{
			wynik+=(!(i%d) ? 1 : 0);
		}
		fprintf (out, "%lld\n", wynik);
		return 0;
	}
	for (int i=0; i<10; ++i)
	{
		dp[1][i][i%d]=1;
	}
	for (int j=0; j<d; ++j)
	{
		for (int i=1; i<10; ++i)
		{
			dp[1][i][j]+=dp[1][i-1][j];
		}
	}
	for (int i=2; i<=n; ++i)
	{
		for (int j=0; j<10; ++j)
		{
			for (int m=0; m<d; ++m)
			{
				dp[i][j][(m+j)%d]+=dp[i-1][9][m];
				dp[i][j][(m+j)%d]%=P;
			}
		}
		for (int m=0; m<d; ++m)
		{
			for (int j=1; j<10; ++j)
			{
				dp[i][j][m]+=dp[i][j-1][m];
				dp[i][j][m]%=P;
			}
		}
	}
	debug
	{
		test_dp();
	}
	m=0;
	for (int i=n; i>=1; --i)
	{
		int liczba=int(s[n-i+1])-48;
		if (!liczba)
		{
			continue;
		}
		wynik+=dp[i][liczba-1][m];
		wynik%=P;
		m=(m+(d<<4)-liczba)%d;
	}
	fprintf (out, "%lld\n", ((--wynik)+(!(sc%d) ? 1 : 0)+P)%P);
	return 0;
}
/*
*/


