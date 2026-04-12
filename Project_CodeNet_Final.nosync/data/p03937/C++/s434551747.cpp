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
template<typename T> inline void print(T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,m;
int main(){
	cin>>n>>m;
	char ch;
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>ch;
			if(ch=='#') cnt++;
		}
	}
	puts(cnt==n+m-1?"Possible":"Impossible");
	return 0;
}