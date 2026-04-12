#include<bits/stdc++.h>
#pragma GCC optimize("02")
#define ll long long
#define _inline __inline__ __attribute__((always_inline))
using namespace std;
struct ios{
    inline char gc(){
        static const int IN_LEN=1<<18|1;
        static char buf[IN_LEN],*s,*t;
        return (s==t)&&(t=(s=buf)+fread(buf,1,IN_LEN,stdin)),s==t?-1:*s++;
    }
    template <typename _Tp> _inline ios & operator >> (_Tp &x){
        static char ch,sgn; ch=gc(),sgn=0;
        for(;!isdigit(ch);ch=gc()){if(ch==-1)return *this;sgn|=ch=='-';}
        for(x=0;isdigit(ch);ch=gc())x=x*10+(ch^'0');
        sgn&&(x=-x); return *this;
    }
}inc;
int n;
int main(){
	inc>>n;
	return printf("%d\n",800*n-200*(n/15)),0;
}