//Generated at 2020-08-02 20:01:50 UTC+8
//Created by Alphagocc
#include<bits/stdc++.h>
#ifdef USE_PBDS
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#endif
using namespace std;
#define FI __inline__ __attribute__((always_inline))
#define TN typename
#define TP template
class IO{static const int bufSize=1<<18;char inBuf[bufSize],outBuf[bufSize];char*ip1=inBuf,*ip2=inBuf;int goodReadBit=0,op1=-1,op2=bufSize-1;
TP <TN T>FI void __RI(T&x){int ch=gc(),neg=1;x=0;for(;!(isdigit(ch)||ch=='-'||ch==EOF);ch=gc());if(ch==EOF){goodReadBit=0;return;}if(ch=='-')neg=-1,ch=gc();for(;isdigit(ch);ch=gc())x=x*10+(ch-48)*neg;}
TP <TN T>FI void __RC(T&x){unsigned char ch;while(isspace(ch=gc()));x=ch;}FI void __RS(string&x){char ch;x.clear();for(ch=gc();isspace(ch);ch=gc());if(ch==EOF){goodReadBit=0;return;}for(;!isspace(ch);ch=gc())x.push_back(ch);}
public:
FI int gc(){return ip1==ip2 &&(ip2 =(ip1=inBuf)+fread(inBuf,1,bufSize,stdin),ip1==ip2)?EOF:*ip1++;}
FI IO& R(char&x){__RC(x);return(*this);}FI IO& R(unsigned char&x){__RC(x);return(*this);}FI IO& R(string&x){__RS(x);return(*this);}TP<TN T1,TN T2>FI IO& R(pair<T1,T2>&x){R(x.first),R(x.second);return(*this);}TP<TN T>FI IO& R(vector<T>&x){for(auto &i:x)R(i);return(*this);}
TP <TN T,TN...Args>FI IO& RA(T*a,int n){for(int i=0;i<n;++i)R(a[i]);return(*this);}TP<TN T,TN...Args>FI IO& R(T&x,Args&...args){R(x),R(args...);return(*this);}
TP <TN T,TN...Args>FI IO& RA(T*a,int n,Args...args){for(int i=0;i<n;++i)RA(a[i],args...);return(*this);}TP<TN T>FI IO& R(T&x){static_assert(is_integral<T>::value,"Unsupported types");if(is_integral<T>::value)__RI(x);return(*this);}
private:
char space=' ';TP<TN T>FI void __WI(T x){static char buf[64];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while(x);}else{pc('-');do{buf[++len]=-(x%10)+48,x/=10;}while(x);}while(len>=0){pc(buf[len]),--len;}}
public:
FI void pc(const char&x){if(op1==op2)flush();outBuf[++op1]=x;}
FI void flush(){fwrite(outBuf,1,op1+1,stdout),op1=-1;}FI IO&W(const char&x){pc(x);return(*this);}FI IO&W(const char*x){while(*x!='\0')pc(*(x++));return(*this);}FI IO&W(const string&x){W(x.c_str());return(*this);}
TP<TN T>FI IO& W(const vector<T>&x){for(auto &i:x)WS(i);WL();return(*this);}FI IO&WL(){W('\n');return(*this);}TP<TN T1,TN T2>FI IO& W(const pair<T1,T2>&x){WS(x.first),W(x.second);return(*this);}
TP<TN T>FI IO& WL(const T&x){W(x),W('\n');return(*this);}FI IO&WS(){W(' ');return(*this);}TP<TN T>FI IO& WS(const T&x){W(x),W(space);return(*this);}
TP<TN T>FI IO& WA(T* a,int n){for(int i=0;i<n;i++)WS(a[i]);WL();return(*this);}TP<TN T,TN...Args>FI IO& W(const T&x,const Args&...args){W(x),W(space),W(args...);return(*this);}
TP<TN...Args>FI IO& WL(const Args&...args){W(args...),W('\n');return(*this);}TP<TN T,TN...Args>FI IO& WA(T* a,int n,Args...args){for(int i=0;i<n;i++)WA(a[i],args...);return(*this);}
TP<TN T>FI IO& W(const T&x){static_assert(is_integral<T>::value,"Unsupported types");if(is_integral<T>::value)__WI(x);return(*this);}
TP<TN T>FI IO&operator>>(T&x){R(x);return(*this);}TP<TN T>FI IO&operator<<(const T&x){W(x);return(*this);}IO(){}}io;
#undef TN 
#undef TP
#undef FI
#define REP(i,x,y) for(int i=x;i<y;i++)
#define ALL(x) x.begin(),x.end()
void EXIT(int code){io.flush(),exit(code);}
const int8_t INFC=0x3f;
const int16_t INFS=0x3f3f;
const int32_t INF=0x3f3f3f3f;
const int64_t INFL=0x3f3f3f3f3f3f3f3fLL;

int main()
{
    int n;
    io >> n;
    io.WL(n >= 30 ? "Yes" : "No");
    EXIT(0);
}