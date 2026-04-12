#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long int 
#define MAX 3005
const int M=1e9+7;
const ll INF = 1LL << 60;
typedef pair<int,int> pii;
typedef double ld;
bool visited[MAX];
vector<int>adj[MAX];
ll n;
ll dp[MAX][MAX],a[MAX];
ll d(int i ,int j)
{
	if(dp[i][j])
		return dp[i][j];
	ll ret;
	if((n-(i-j))%2==0)
	{
		if(j-i==1)
			return a[i];
		ret=-INF;
		ret=max(d(i+1,j)+a[i],d(i,j-1)+a[j-1]);
	}
	else
	{
		if(j-i==1)
			return 0;
		ret=INF;
		ret=min(d(i+1,j),d(i,j-1));
	}
	return dp[i][j]=ret;
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	cin>>n;
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	ll x = d(0,n);
	ll y = sum-x;
	cout<<x-y<<endl;
	return 0;	
}
