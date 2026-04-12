#include<bits/stdc++.h>
#define int long long
#define inc(i) (++ (i))
#define dec(i) (-- (i))
#define Rep(i, a, b) for(register int i = (a) , i##Limit = (b) ; i <= i##Limit ; inc(i))
#define Dep(i, a, b) for(register int i = (a) , i##Limit = (b) ; i >= i##Limit ; dec(i))
#define QQ 2745186036

using namespace std;

const int maxn = 200010;
int n, bMax = -1, bMin = QQ, sMax = -1, sMin = QQ, teM, tem, ans = QQ, ri, le;
struct fn{
	int big, small;
}f[maxn];

int read(){
    int x=0,w=1;char ch=0;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
    return x*w;
}

bool cmp(fn x, fn y)
{
	return x.small < y.small;
}

signed main()
{
    #ifndef ONLINE_JUDGE
  	freopen("test.in", "r", stdin);	
	freopen("test.out", "w", stdout);
    #endif  

	n = read();
	Rep(i,1,n) {
		f[i].big = read(); f[i].small = read();
		if(f[i].big < f[i].small) swap(f[i].big, f[i].small);
		// printf("%lld %lld\n", f[i].small, f[i].big);
		if(f[i].big > bMax) bMax = f[i].big;
		if(f[i].big < bMin) bMin = f[i].big;
		if(f[i].small < sMin) sMin = f[i].small;
		if(f[i].small > sMax) sMax = f[i].small;
	}
	// printf("%lld %lld %lld %lld\n", bMax, bMin, sMax, sMin);
	sort(f + 1, f + n + 1, cmp);
	ri = le = f[1].big;
	// printf("%lld\n", f[1].big);
	Rep(i,2,n) {
		ri = max(ri, f[i].big);
		le = min(le, f[i].big);
		// printf("%lld %lld\n", ri, le);
		if(i != n) ans = min(ans, max(ri, f[n].small) - min(le, f[i + 1].small));
	}
	// printf("%lld\n", ans);
	ans *= bMax - sMin;
	// if(teM != tem) 
	ans = min(ans, (bMax - bMin) * (sMax - sMin));
	printf("%lld", ans);
	return 0;
}