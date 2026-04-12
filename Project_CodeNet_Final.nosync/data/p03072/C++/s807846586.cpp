//#pragma optimizitaion_level 3
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define vse(a) a.begin(), a.end()
#define ovse(a) a.rbegin(), a.rend()
#define pb push_back
#define endl aut '\n'
#define ar vector
#define var auto
#define rand() (((rand()<<15)+rand())&INT32_MAX)
#define ain cin,
#define aut cout,
#define $(a) (i32)a.size()

typedef int i32;
typedef unsigned u32;
typedef long long i64;
typedef unsigned long long u64;
typedef pair<i32, i32> p32;
typedef pair<i64, i64> p64;
typedef double lf;

namespace nyuuryoku{
    const i32 STRSZ=3e5+13;
    char inbufer[STRSZ];
    inline void cscan(string& i){
        i32 c=getc(stdin), cnt=0;while(c<=32)c=getc(stdin);
        while(c>32)*(inbufer+cnt)=c,c=getc(stdin),++cnt;
        *(cnt+inbufer)=0;i=inbufer;
    }
    inline void cprint(string& i){
        char *s=new char[i.size()+1]; 
        strcpy(s, i.c_str());
        while(*s)putchar(*s), s++;
    }
    inline void cprint(const char*& i){
        i32 cnt=0;
        while(*(i+cnt))putc(*(i+cnt), stdout),cnt++;
    }
    inline void cscan(i32&i){
        i=0;i32 c=getc(stdin), b=0;while(c<=32)c=getc(stdin);if(c=='-')b=1, c=getc(stdin);
        while(c>='0'&&c<='9')i*=10,i+=c-'0',c=getc(stdin);
        if(b)i=-i;
    }
    inline void cprint(i32 i){
        if(i<0)putc('-',stdout),i=-i;
        i32 sz=0;char ans[12];while(i||!sz)ans[sz++]=i%10+'0',i/=10;
        while(sz--)putc(ans[sz],stdout);
    }
    inline void cscan(i64&i){
        i=0;i32 c=getc(stdin), b=1;while(c<=32)c=getc(stdin);if(c=='-')b=-1,c=getc(stdin);
        while(c>='0'&&c<='9')i*=10,i+=c-'0',c=getc(stdin);
        i*=b;
    }
    inline void cprint(i64 i){
        if(i<0)putc('-',stdout),i=-i;
        i32 sz=0;char ans[21];while(i||!sz)ans[sz++]=i%10+'0',i/=10;
        while(sz--)putc(ans[sz],stdout);
    }
    inline void cscan(u32&i){
        i=0;i32 c=getc(stdin);while(c<=32)c=getc(stdin);
        while(c>='0'&&c<='9')i*=10,i+=c-'0',c=getc(stdin);
    }
    inline void cprint(u32 i){
        i32 sz=0;char ans[12];while(i||!sz)ans[sz++]=i%10+'0',i/=10;
        while(sz--)putc(ans[sz],stdout);
    }
    inline void cscan(u64&i){
        i=0;i32 c=getc(stdin);while(c<=32)c=getc(stdin);
        while(c>='0'&&c<='9')i*=10,i+=c-'0',c=getc(stdin);
    }
    inline void cprint(u64 i){
        i32 sz=0;char ans[21];while(i||!sz)ans[sz++]=i%10+'0',i/=10;
        while(sz--)putc(ans[sz],stdout);
    }
    inline void cscan(lf&i){
        scanf("%lf", &i);
    }
    inline void cprint(lf i){
        printf("%lf", i);
    }
    inline void cprint(char i){
        putc(i, stdout);
    }
    inline void cscan(char&i){
        i32 b=getc(stdin);
        while(b<=32)b=getc(stdin);
        i=b;
    }
    template<class T>inline void cscan(pair<T, T>& i){
        cscan(i.f);cscan(i.s);
    }
    template<class T>inline void cscan(ar<T>& i){
        for(var& j:i)cscan(j);
    }
    template<class T>inline void cprint(ar<T>& i){
        for(var& j:i)cprint(j), cprint(' ');
    }
    template<class T>inline void cprint(ar<ar<T> >& i){
        for(var& j:i)cprint(j), cprint('\n');
    }
    template<class T>ostream &operator,(ostream &os, T v){
        cprint(v);
        return os;
    }
    template<class T>istream &operator,(istream &is, T &v) {
        cscan(v);
        return is;
    }
}

using namespace nyuuryoku;
void execute();
i32 main(){
    #ifdef home
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    srand(time(0));
    execute();
    #ifdef home
        aut '\n', (lf)clock()/CLOCKS_PER_SEC, " 秒\n";
    #endif
    return 0;
}

void execute(){
	i32 n;
	ain n;
	ar<i32> in(n);
	ain in;
	i32 ans=1;
	for(i32 i=1, mx=in[0];i<n;mx=max(mx, in[i]), i++)
		if(in[i]>=mx)
			ans++;
	aut ans;
}
