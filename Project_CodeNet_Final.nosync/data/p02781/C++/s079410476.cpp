#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define LOCAL 1

#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define dbg(...) cout<<#__VA_ARGS__ ": ["; for(auto e: __VA_ARGS__){cout<<e<<", ";} cout<<"]\n"
#define dbg1(...) cout<<#__VA_ARGS__ " "<< __VA_ARGS__ 
#else
#define dbg(...) 1;
#define dbg1(...) 1;
#endif

typedef long long ll;
typedef unsigned long long ull;
constexpr int R=5e2+69, INF=2e9+6969;

int qq;
int dp[R][4];
set <string> ss;

void gen(string A, int l, int p)
{
	if(l==0){
		ss.insert(A); 
		return;
	}
	for(int i=p+1;i<A.size();++i)
	{
		string cur=A;
		for(int j=1;j<=9;++j)
		{
			cur[i]=(char)(j+'0');
			gen(cur,l-1,i);
		}
	}
}

int main()
{
	string s;
	int k,n,ans=0;
	cin >> s;
	scanf("%d", &k);
	n = (int)s.size();
	
	for(int i=0;i<=n;++i) dp[i][0]=1;
	for(int j=1;j<=3;++j)
	{
		for(int i=1;i<n;++i)
		{
			dp[i][j]=dp[i-1][j] + dp[i-1][j-1]*9;
		}
	}
	//  printf("%d\n", n);
	string wyn="";
	for(int i=0;i<n;++i) wyn = wyn+"0";
	for(int i=1;i<=9;++i)
	{
		wyn[0]=(char)(i+'0');
		gen(wyn,k-1,0);
	}
	//  gen("1000",2,0);
	for(auto e: ss) {
		if(e>s) break;
		ans++;
	}
	ans+= dp[n-1][k];
	printf("%d\n", ans);
	return 0;
}
