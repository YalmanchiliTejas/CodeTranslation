#include <bits/stdc++.h> 
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define sz(x) (int)(x).size()
typedef vector<int> vi;
// #define ll long long 
#define int long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
const int MOD = 1e9+7;
int mpow(int a,int b,int p=MOD){a=a%p;int res=1;while(b>0){if(b&1)res=(res*a)%p;a=(a*a)%p;b=b>>1;}return res%p;}
const int N=2*1e5+2;
string n;
int k;
int dp[102][2][5];
bool vis[102][2][5];
int fun(int pos,bool same,int oof)
{
	if(pos>=(int)n.size()){
	 if(oof==0) return 1;
	 else return 0;
	}
	if(vis[pos][same][oof])
	{
		return dp[pos][same][oof];
	}
	int ans=0;
	for(int i=0;i<=9;i++)
	{
		if(same&&((i+'0')>n[pos])) continue;
		if((oof-(i!=0?1:0))<0)
		{
			continue;
		}
		ans+=fun(pos+1,same&&((i+'0')==(n[pos])),(oof-(i!=0?1:0)));
	}
	vis[pos][same][oof]=true;
	return dp[pos][same][oof]=ans;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>k;
	cout<<fun(0,true,k);
} 
// I never lose. I either win or I learn