#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<int,int> pii;
#define endl '\n'
#define F first
#define S second
const int MAX_N=1e4+4;
const int MAX_D=1e2+2;
const int MOD=1000000007;

string K;
int D;
ll dp[MAX_N][MAX_D];
ll ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>K>>D;
	reverse(K.begin(),K.end());
	K[0]++;
	for(int i=0;i<(int)K.size()-1;i++) if(K[i]-'0'>9) K[i]-=10, K[i+1]++;
	if(K.back()-'0'>9) K.back()-=10, K.push_back('1');
	dp[0][0]=1;
	for(int i=0;i<(int)K.size();i++) for(int j=0;j<D;j++) for(int d=0;d<=9;d++)
		dp[i+1][(j+d)%D]=(dp[i+1][(j+d)%D]+dp[i][j])%MOD;
	for(int i=K.size()-1,d=0;i>=0;i--) for(int j=0;j<K[i]-'0';j++,d++)
		ans=(ans+dp[i][(D-(d%D))%D])%MOD;
	cout<<(ans-1+MOD)%MOD<<'\n';
	return 0;
}

