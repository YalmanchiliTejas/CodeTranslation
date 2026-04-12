#include<bits/stdc++.h>
using namespace std;
#define md 1000000007
#define ll long long 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fastmap mp.reserve(1024);mp.max_load_factor(0.25);
#define fastset st.reserve(1024);st.max_load_factor(0.25);
ll int mpw(ll int a,ll int b,ll int m)
{
	ll int ans=1;
	if(a==0)return 0;
	if(a==1 || b==0)return 1;
	while(b)
	{
		if(b&1)
		{
			ans=(ans*a)%m;
		}
		a=(a*a)%m;
		b>>=1;
	}
	return ans;
}
 
ll int pw(ll int a,ll int b)
{
	ll int ans=1;
	if(a==0)return 0;
	if(a==1 || b==0)return 1;
	while(b)
	{
		if(b&1)
		{
			ans*=a;
		}
		a*=a;
		b>>=1;
	}
	return ans;
}
 
ll int mn(ll int a,ll int b)
{
	if(a<=b)
	{
		return a;
	}
	return b;
}
 
ll int mx(ll int a,ll int b)
{
	if(a>=b)
	{
		return a;
	}
	return b;
}

int main()
{
	fio
	string s;
	cin>>s;
	int d;
	cin>>d;
	int n=s.size();
	vector<vector<ll int>>D(n,vector<ll int>(d,0));
	for(int i=0;i<int(s[0])-48;++i)
	{
		D[0][(i)%d]+=1;
	}
	int cr=(int(s[0])-48)%d;
	for(int i=0;i<n-1;++i)
	{
		for(int j=0;j<d;++j)
		{
			for(int x=0;x<10;++x)
			{
				D[i+1][(x+j)%d]=(D[i+1][(x+j)%d]+D[i][j])%md;
			}
		}
		for(int j=0;j<int(s[i+1])-48;++j)
		{
			D[i+1][(cr+j)%d]=(D[i+1][(cr+j)%d]+1)%md;
		}
		cr=(cr+int(s[i+1])-48)%d;
	}
	D[n-1][cr%d]=(D[n-1][cr%d]+1)%md;
	cout<<((D[n-1][0]-1)%md +md)%md<<"\n";
	return 0;
}