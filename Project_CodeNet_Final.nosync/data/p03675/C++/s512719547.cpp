#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
inline void read(int &x){
    x=0;static char ch;static bool flag;flag = false;
    while(ch=getchar(),ch<'!');if(ch == '-') ch=getchar(),flag = true;
    while(x=10*x+ch-'0',ch=getchar(),ch>'!');if(flag) x=-x;
}
#define rg register int
#define rep(i,a,b) for(rg i=(a);i<=(b);++i)
#define per(i,a,b) for(rg i=(a);i>=(b);--i)
deque<int>q;
int main(){
    int n;read(n);
    int p = 1,x;
    if(n&1) p ^= 1;
    rep(i,1,n){
	read(x);
	if(p&1) q.push_back(x);
	else q.push_front(x);
	p ^= 1;
    }
    while(!q.empty()){
	printf("%d",q.front());
	q.pop_front();
	if(q.empty()) putchar('\n');
	else putchar(' ');
    }
    
    return 0;
}
