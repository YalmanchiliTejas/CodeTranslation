//Generated at 2020-03-22 21:32:15 UTC+8
//Created by Alphagocc
#include<bits/stdc++.h>
#ifdef USE_PBDS
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#endif
#define FORCE_INLINE __inline__ __attribute__((always_inline))
class IO
{
static const int bufSize=1<<18;char inBuf[bufSize],outBuf[bufSize];char*ip1=inBuf,*ip2=inBuf;int goodReadBit=0,op1=-1,op2=bufSize-1;
template <typename T>FORCE_INLINE void __RI(T&x){int ch=gc(),neg=1;x=0;for(;!(isdigit(ch)||ch=='-'||ch==EOF);ch=gc());if(ch==EOF){goodReadBit=0;return;}if(ch=='-')neg=-1,ch=gc();for(;isdigit(ch);ch=gc())x=x*10+(ch-48)*neg;}
template <typename T>FORCE_INLINE void __RC(T&x){unsigned char ch;while(isspace(ch=gc()));x=ch;}
FORCE_INLINE void __RS(std::string&x){char ch;x.clear();for(ch=gc();isspace(ch);ch=gc());if(ch==EOF){goodReadBit=0;return;}for(;!isspace(ch);ch=gc())x.push_back(ch);}
public:
FORCE_INLINE int gc(){return ip1==ip2 &&(ip2 =(ip1=inBuf)+fread(inBuf,1,bufSize,stdin),ip1==ip2)?EOF:*ip1++;}
FORCE_INLINE void R(char&x){__RC(x);}FORCE_INLINE void R(unsigned char&x){__RC(x);}FORCE_INLINE void R(std::string&x){__RS(x);}
template <typename T1,typename T2>FORCE_INLINE void R(std::pair<T1,T2>&x){R(x.first),R(x.second);}template<typename T>FORCE_INLINE void R(std::vector<T>&x){for(auto it=x.begin();it!=x.end();++it)R(*it);}
template <typename T,typename...Args>FORCE_INLINE void RA(T*a,int n){for(int i=0;i < n;++i)R(a[i]);}template<typename T,typename...Args>FORCE_INLINE void R(T&x,Args&...args){R(x),R(args...);}
template <typename T,typename...Args>FORCE_INLINE void RA(T*a,int n,Args...args){for(int i=0;i < n;++i)RA(a[i],args...);}template<typename T>FORCE_INLINE void R(T&x){static_assert(std::is_integral<T>::value,"Unsupported types");if(std::is_integral<T>::value)__RI(x);}
private:
char space;template <typename T>FORCE_INLINE void __WI(T x){static char buf[64];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while(x);}else{pc('-');do{buf[++len]=-(x%10)+48,x/=10;}while(x);}while(len>=0){pc(buf[len]),--len;}}
public:
FORCE_INLINE void pc(const char&x){if(op1==op2)flush();outBuf[++op1]=x;}
FORCE_INLINE void flush(){fwrite(outBuf,1,op1+1,stdout),op1=-1;}FORCE_INLINE void W(const char&x){pc(x);}FORCE_INLINE void W(const char*x){while(*x!='\0')pc(*(x++));}FORCE_INLINE void W(const std::string&x){W(x.c_str());}
template<typename T>FORCE_INLINE void W(const std::vector<T>&x){for(auto it=x.begin();it != x.end();it++)WS(*it);WL();}FORCE_INLINE void WL(){W('\n');}
template<typename T>FORCE_INLINE void WL(const T&x){W(x),W('\n');}FORCE_INLINE void WS(){W(' ');}
template<typename T>FORCE_INLINE void WS(const T&x){W(x),W(space);}
template<typename T>FORCE_INLINE void WA(T* a,int n){for(int i=0;i<n;i++)WS(a[i]);WL();}
template<typename T,typename...Args>FORCE_INLINE void W(const T&x,const Args&...args){W(x),W(space),W(args...);}
template<typename...Args>FORCE_INLINE void WL(const Args&...args){W(args...),W('\n');}
template<typename T,typename...Args>FORCE_INLINE void WA(T* a,int n,Args...args){for(int i=0;i < n;i++)WA(a[i],args...);}
template<typename T>FORCE_INLINE void W(const T&x){static_assert(std::is_integral<T>::value,"Unsupported types");if(std::is_integral<T>::value)__WI(x);}
template<typename T>FORCE_INLINE IO&operator>>(T&x){R(x);return(*this);}
template<typename T>FORCE_INLINE IO&operator<<(const T&x){W(x);return(*this);}IO(){space=' ';}
} io;
namespace Alphagocc{decltype(std::chrono::high_resolution_clock::now()) tStart;};void TimeBegin(){Alphagocc::tStart=std::chrono::high_resolution_clock::now();}long long TimeEnd(){return(std::chrono::high_resolution_clock::now() - Alphagocc::tStart).count();} // namespace Alphagocc
using namespace std;
#define REP(i,x,y) for(int i=x;i<y;i++)
#define ALL(x) x.begin(),x.end()
const int8_t INFC=0x3f;
const int16_t INFS=0x3f3f;
const int32_t INF=0x3f3f3f3f;
const int64_t INFL=0x3f3f3f3f3f3f3f3fLL;

using namespace std;
const int MAXN = 4000;
int dp[MAXN][MAXN];
const int JYH = 998244353;
int main()
{
    int n, s;
    io >> n >> s;
    vector<int> a(n);
    io >> a;
    for (int i = 0; i < n; i++) dp[i][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= s; j++) {
            if (j + a[i] <= s && dp[i][j] != 0)
                dp[i + 1][j + a[i]] = (dp[i + 1][j + a[i]] + dp[i][j]) % JYH;
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % JYH;
        }
    int ans = 0;
    for (int i = 0; i <= n; i++) ans = (ans + dp[i][s]) % JYH;
    io.WL(ans);
    io.flush();
}