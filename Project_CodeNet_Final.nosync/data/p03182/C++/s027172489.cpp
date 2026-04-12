#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
#define x first
#define y second
#define pb push_back
using namespace std;
const int DN=2e5+5;
long long n,m,f,g,k,dp[DN],ma,ls,ld,val;
long long arb[2][4*DN];
vector<pair<int,int> >v[DN];
void update(int type,int nod,int st,int dr)
{
	if(dr<ls)
		return;
	if(st>ld)
		return;
	if(ls<=st&&dr<=ld)
	{
		if(type==0)
		{
			arb[0][nod]=arb[1][nod]+val;
			return;
		}
		arb[0][nod]+=val;
		arb[1][nod]+=val;
		return;
	}
	int mij=(st+dr)/2;
	update(type,2*nod,st,mij);
	update(type,2*nod+1,mij+1,dr);
	arb[0][nod]=arb[1][nod]+max(arb[0][2*nod],arb[0][2*nod+1]);
}
int main()
{
	cin>>n>>m;
	while(m--)
	{
		cin>>f>>g>>k;
		if(f>g)
			swap(f,g);
		v[g].pb({f,k});
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=max(dp[i],arb[0][1]);
		ls=ld=i;
		val=dp[i];
		update(0,1,1,n);
		for(auto j:v[i])
		{
			ls=j.x;
			ld=i;
			val=j.y;
			update(1,1,1,n);
		}
	}
	if(arb[0][1]<0)
		arb[0][1]=0;
	cout<<arb[0][1];
}