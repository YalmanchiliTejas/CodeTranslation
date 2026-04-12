#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int man = 2e5+10;
#define IOS ios::sync_with_stdio(0)
template <typename T>
inline T read(){T sum=0,fl=1;int ch=getchar();
for(;!isdigit(ch);ch=getchar())if(ch=='-')fl=-1;
for(;isdigit(ch);ch=getchar())sum=sum*10+ch-'0';
return sum*fl;}
template <typename T>
inline void write(T x) {static int sta[35];int top=0;
do{sta[top++]= x % 10, x /= 10;}while(x);
while (top) putchar(sta[--top] + 48);}
template<typename T>T gcd(T a, T b) {return b==0?a:gcd(b, a%b);}
template<typename T>T exgcd(T a,T b,T &g,T &x,T &y){if(!b){g = a,x = 1,y = 0;}
else {exgcd(b,a%b,g,y,x);y -= x*(a/b);}}
#ifndef ONLINE_JUDGE
#define debug(fmt, ...) {printf("debug ");printf(fmt,##__VA_ARGS__);puts("");}
#else
#define debug(fmt, ...)
#endif
typedef long long ll;
const ll mod = 1e9+7;
int a[man];
ll s[man],dp[man];

int main() {
	#ifndef ONLINE_JUDGE
		//freopen("in.txt", "r", stdin);
		//freopen("out.txt","w",stdout);
	#endif
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	s[1] = a[1];
	for(int i = 3;i <= n;i+=2){
		s[i] = s[i-2] + a[i];
	}
	for(int i = 2;i <= n;i++){
		if(i&1)dp[i] = max(dp[i-1],dp[i-2]+a[i]);
		else dp[i] = max(s[i-1],dp[i-2]+a[i]);
	}
	cout << dp[n] << endl;
	return 0;
}