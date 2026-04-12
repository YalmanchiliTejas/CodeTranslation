#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MOD=1e9+7;
ll dp[100][10005],d,ans,x;
string s;

int main()
{jizz
	dp[0][0]=1;
	cin >> s >> d;
	for(int i=1;i<s.size();++i)
		for(int k=0;k<10;++k)
			for(int j=0;j<d;++j)
				dp[(j+k)%d][i]=(dp[j][i-1]+dp[(j+k)%d][i])%MOD;
	for(int i=0;i<s.size();x=(x+s[i]-'0')%d,++i)
		for(int j=0;j+'0'<s[i];++j)
			ans=(ans+dp[(d-(x+j)%d)%d][s.size()-i-1])%MOD;
	cout << (ans+(x==0)-1+MOD)%MOD << "\n";
}