#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
typedef long long lint;
const int N=2e5+5;
int n,val[N],buk[N];

namespace utils{
	template <class T> inline void apn(T &x,const T y){x=x<y?x:y;}
	template <class T> inline void apx(T &x,const T y){x=x>y?x:y;}
	inline int nxi(){
		int x=0;
		char c;
		while(((c=getchar())>'9'||c<'0')&&c!='-');
		const bool f=c=='-'&&(c=getchar());
		while(x=x*10-48+c,(c=getchar())>='0'&&c<='9');
		return f?-x:x;
	}
}
using namespace utils;

int main(){
	n=nxi();
	for(int i=1; i<=n; ++i){
		buk[i]=val[i]=nxi();
	}
	std::sort(buk+1,buk+n+1);
	for(int mid=n>>1,i=1; i<=n; ++i){
		printf("%d\n",buk[mid+(buk[mid]>=val[i])]);
	}
	return 0;
}
