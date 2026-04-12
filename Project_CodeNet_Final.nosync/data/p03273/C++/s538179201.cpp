/**
 * Problem:	D. 
 * Author:	hkxadpall. 
 * Date:	2018-08-25. 
 * Upload:	AtCoder. 
 */
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue> 
#include <map>
#include <set>
using namespace std;

namespace AuthorName { 
    template <typename _TpInt> inline _TpInt read();
    template <typename _TpRealnumber> inline double readr();
    template <typename _TpInt> inline void write(_TpInt x);
//	template <typename _TpSwap> inline void swap(_TpSwap &x, _TpSwap &y);
	
#	define Max_N 1007
	
	int n, m;
	
	int main() 
	{
		n = read<int>();
		m = read<int>();
		char str[101][101];
		bool look1[101] = {0}, look2[101] = {0};
		for (int i = 0; i < n; i++)
			scanf("%s", str[i]);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (str[i][j] == '#') look1[i] = look2[j] = 1;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (look1[i] && look2[j]) putchar(str[i][j]);
			}
			if (look1[i]) putchar(10);
		}
	    return 0;
	}

#	define Getchar() getchar()

    template <typename _TpInt>
    inline _TpInt read()       
    {
        register int flag = 1;
        register char c = Getchar();
        while ((c > '9' || c < '0') && c != '-') 
            c = Getchar();
        if (c == '-') flag = -1, c = Getchar();
        register _TpInt init = (c & 15);
        while ((c = Getchar()) <= '9' && c >= '0') 
            init = (init << 3) + (init << 1) + (c & 15);
        return init * flag;
    }

    template <typename _TpRealnumber>
    inline double readr()       
    {
        register int flag = 1;
        register char c = Getchar();
        while ((c > '9' || c < '0') && c != '-') 
            c = Getchar();
        if (c == '-') flag = -1, c = Getchar();
        register _TpRealnumber init = (c & 15);
        while ((c = Getchar()) <= '9' && c >= '0') 
            init = init * 10 + (c & 15);
        if (c != '.') return init * flag;
        register _TpRealnumber l = 0.1;
        while ((c = Getchar()) <= '9' && c >= '0') 
            init = init + (c & 15) * l, l *= 0.1;
        return init * flag;
    }

    template <typename _TpInt>
    inline void write(_TpInt x)
    {
        if (x < 0) {
            putchar('-');
            write<_TpInt>(~x + 1);
        }
        else {
            if (x > 9) write<_TpInt>(x / 10);   
            putchar(x % 10 + '0');
        }
    }

//	template <typename _TpSwap>
//	inline void swap(_TpSwap &x, _TpSwap &y)
//	{
//	    _TpSwap t = x;
//	    x = y;
//	    y = t;
//	}
}

int main()
{
    AuthorName::main();
    return 0;
}