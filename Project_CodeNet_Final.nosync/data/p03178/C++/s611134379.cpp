#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
void dbg_out(){
	cerr<<endl;
}
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){
	cerr<<' '<< H; 
	dbg_out(T...);
}
string s;
int const MAXN=10010, MAXD=110, MOD=1e9+7;
int d, memo[MAXN][MAXD][2], n;
int dp(int digit, int rem, int change){
	int &x=memo[digit][rem][change];
	if(x!=-1)
		return x;
	if(digit==n)
		return rem==0;
	if(change){
		x=0;
		for(int i=0;i<=9;i++)
			x=(x+dp(digit+1,(rem+i)%d,change))%MOD;
		return x;
	}
	x=0;
	for(int i=s[digit]-'0';i>=0;i--)
		x=(x+dp(digit+1,(rem+i)%d,i!=s[digit]-'0'))%MOD;
	return x;
}
int main(){
	cin>>s>>d;
	n=(int)s.length();
	memset(memo,-1,sizeof(memo));
	int ans=dp(0,0,0);
	if(ans)
		cout<<ans-1;
	else cout<<MOD-1;
}
