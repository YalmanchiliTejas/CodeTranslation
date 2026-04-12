#include <bits/stdc++.h>
#define F(i, l, r) for(int i = (l), _end_ = (int)(r); i <= _end_; ++i)
#define f(i, r, l) for(int i = (r), _end_ = (int)(l); i >= _end_; --i)
#define Set(a, v) memset(a, v, sizeof(a))
using namespace std;

bool chkmin(int &a, int b) {return b < a ? a = b, 1 : 0;}
bool chkmax(int &a, int b) {return b > a ? a = b, 1 : 0;}

inline int read() {
 int x = 0, fh = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar() ) if (ch == '-') fh = -1;
    for (; isdigit(ch); ch = getchar() ) x = (x<<1) + (x<<3) + (ch ^ '0');
    return x * fh;
}
int n,m;
int main () {
    n=read();
	m=read();
	long long ans=0;
	F(i,m+1,n){
	  int x=n/i,y=n%i;
      ans+=(long long)x*(i-m);
	  if(y>=m){
	     ans+=y-m;
		 if(m)ans++;
	  }
	}
	printf("%lld\n",ans);
	return 0;
}