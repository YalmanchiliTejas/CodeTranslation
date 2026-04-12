#include <bits/stdc++.h>
//#pragma GCC target("avx,avx2,sse4.2")
#define rep(q, a, b) for (int q = a, q##_end_ = b; q <= q##_end_; ++q)
#define dep(q, a, b) for (int q = a, q##_end_ = b; q >= q##_end_; --q)
#define mem(a, b) memset(a, b, sizeof a)
#define debug(a) cerr << #a << ' ' << a << "___" << endl
using namespace std;
// char buf[10000000], *p1 = buf, *p2 = buf;
#define Getchar() getchar()  // p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 10000000, stdin), p1 == p2) ? EOF : *p1++
void in(int &r) {
    static char c;
    r = 0;
    while (c = Getchar(), c < 48);
        ;
    do
        r = (r << 1) + (r << 3) + (c ^ 48);
    while (c = Getchar(), c > 47);
}
const int mn=100005;
int val[mn],mid[mn],n;
struct BIT{
	int c[mn];
	void add(int x,int v){
		while(x)c[x]=max(c[x],v),x&=x-1;
	}
	int ask(int x){
		int ans=0;
		while(x<=n)ans=max(ans,c[x]),x+=x&-x;
		return ans;
	}
}an;
int main(){
	in(n);
	rep(q,1,n)in(val[q]),mid[q]=val[q];
	sort(mid+1,mid+n+1);
	rep(q,1,n)val[q]=lower_bound(mid+1,mid+n+1,val[q])-mid;
	rep(q,1,n)an.add(val[q],an.ask(val[q])+1);
	cout<<an.ask(1);
	return 0;
}