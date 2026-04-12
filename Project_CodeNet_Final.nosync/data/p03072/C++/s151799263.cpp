#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
 
namespace IO{
    const int insiz = 1 << 12, outsiz = 1 << 18;
    char in[insiz], *A(in), *B(in); char out[outsiz], *ptr(out);
    inline char getc(){
    	#ifndef LOCAL
        return (A == B) && (B = (A = in) + fread(in, 1, insiz, stdin), A == B) ? EOF : *A++;
        #endif
        return getchar();
    }
    template <typename T> inline T read(){
        T ret(0), p(1); char ch(getc());
        while(ch < '0' || ch > '9'){
            if(ch == '-') p = -1; ch = getc();
        }
        while(ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getc();
        return ret*p;
    }
    inline void flush(){ fwrite(out, 1, ptr - out, stdout); ptr = out; }
    template <typename T> inline void write(T x, char cmd = '\n'){
        if(x < 0) *ptr++ = '-', x = -x;
        if(x == 0) *ptr++ = '0';
        static char s[123]; int cnt = 0;
        for(; x; x /= 10) s[++cnt] = x % 10 + '0';
        for(; cnt; --cnt) *ptr++ = s[cnt];
        *ptr++ = cmd;
        if((outsiz >> 1) > ptr - out) flush();
    }
} using IO::getc; using IO::read; using IO::write; using IO::flush;
 
int main(){
	int n = read<int>();
	int ans(0), Max(0);
	for(int i(1) ; i <= n; ++i){
		int t = read<int>();
		if(t >= Max) ++ans, Max = t;
	}
	write(ans);
	flush(); return 0;
}
 
 