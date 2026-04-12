#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"

int power(int a,int b,int m=mod)
{
	if(b==0)	return 1;
	if(b==1)	return a;
	int res=power(a,b/2,m);
	res=(res*res)%m;
	if(b&1)	res=(res*a)%m;
	return res;
}
int modinv(int a,int m=mod){ return power(a,m-2,m);}
int add(int a,int b,int m=mod){	int c=(a+b);	if(c>=m)	c-=m;	return c;}
int sub(int a,int b,int m=mod){	int c=(a-b);	if(c<0)		c+=m;	return c;}
int mul(int a,int b,int m=mod){	return (a*b)%m;}
//	x<<1 => x*2		x>>1 => x/2;	cout<<flush;
//	cout<<fixed<<setprecision(10)<<ans<<endl;


void solve()
{
	int n,x,m;
	cin>>n>>x>>m;
	map<int,int> mp;
	int pre[m];
	memset(pre,0,sizeof(pre));
	pre[0]=0;
	int T=2;
	pre[1]=x;
	mp[x]=1;
	n--;
	//cout<<"x is "<<x<<endl;
	while(n--)
	{
		x=(x*x)%m;
		if(mp[x])
			break;
		pre[T]=pre[T-1]+x;
		mp[x]=T++;
		//cout<<"x is "<<x<<" "<<pre[T-1]<<endl;
	}
	if(n<1)
	{
		cout<<pre[T-1]<<endl;
		return;
	}
	int period=T-mp[x];
	int val=pre[T-1]-pre[mp[x]-1];
	
	//cout<<"T is "<<T<<" "<<pre[T-1]<<endl;
	//cout<<"period is "<<period<<endl;
	
	int ans=pre[T-1];
	int left=n+1;
	
	//cout<<"left is "<<left <<endl;
	ans+=(left/period)*val;
	
	left=left%period;
	int start=mp[x];
	while(left--)
	{
		ans+=pre[start]-pre[start-1];
		start++;
	}
	cout<<ans<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	for(int i=1;i<=t;i++){	solve();}
	return 0;
}