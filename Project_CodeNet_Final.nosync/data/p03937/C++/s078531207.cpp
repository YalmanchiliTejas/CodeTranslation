//============================================================================
// Author       : Sun YaoFeng
//============================================================================

//#pragma 	comment(linker, "/STACK:100240000,100240000")
//#include	<cstdio>
//#include	<cstdlib>
//#include	<cstring>
//#include	<algorithm>

#include	<bits/stdc++.h>

using	namespace	std;

#define DB		double
#define	lf		else if
#define I64		long long
#define	Rd()	(rand()<<15|rand())
#define For(i,a,b)	for(int i=a,lim=b;i<=lim;i++)
#define Rep(i,a,b)	for(int i=a,lim=b;i>=lim;i--)

#define	fi	first
#define se	second
#define MK	make_pair
#define PA	pair<int, int>

//#define	min(a,b)	((a)<(b)?(a):(b))
//#define	max(a,b)	((a)<(b)?(b):(a))

#define	CH	(ch=getchar())
int		IN()	{
		int x= 0, f= 0, ch;
		for	(; CH < '0' || ch > '9';)	f= (ch == '-');
		for	(; ch >= '0' && ch <= '9'; CH)	x= x*10 + ch -'0';
		return	f? -x : x;
}

#define n	15

int		N, M, C, F[n][n];

char	s[n][n];

int		main(int argc, char* argv[]){
		N= IN();
		M= IN();
		For(i, 1, N)	scanf("%s", s[i] + 1);
		
		For(i, 1, N)	For(j, 1, M)	C+= s[i][j] == '#';
		
		if	(C != N+M-1 || s[1][1] != '#')	puts("Impossible");
		else	{
			F[1][1]= 1;
			For(i, 1, N)	For(j, 1, M)	if	(i != 1 || j != 1)
				F[i][j]= F[i-1][j] || F[i][j-1];
			
			puts(F[N][M] ? "Possible" : "Impossible");
		}
		
		return	0;
}