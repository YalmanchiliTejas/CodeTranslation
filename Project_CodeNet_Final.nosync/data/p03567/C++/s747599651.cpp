#include<bits/stdc++.h>
#define I64 "%I64d"
#define RAN(v)v.begin(),v.end()
#define pb push_back
#define lb lower_bound
#define ub upper_bound
using namespace std;
typedef long long ll;
template<class T>
inline void upd1(T&a,T b){a>b?a=b:0;}
template<class T>
inline void upd2(T&a,T b){a<b?a=b:0;}
struct ano{
	operator ll(){
		ll x=0,y=0,c=getchar();
		while(c<48)
			y=c==45,c=getchar();
		while(c>47)
			x=x*10+c-48,c=getchar();
		return y?-x:x;
	}
}buf;
char s[100005];
int main(){
	scanf("%s",s);
	puts(strstr(s,"AC")?"Yes":"No");
}