#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ACC ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mod 1000000007
#define MAXN 10000001
//string alpha="abcdefghijklmnopqrstuvwxyz";
//int dx[]={1,-1,0,0};
//int dy[]={0,0,1,-1};
//int dx8[]={1,-1,0,0,1,1,-1,-1};
//int dy8[]={0,0,1,-1,1,-1,1,-1};
/*int spf[MAXN];
void sieve()
{
	int i,j;
	for(i=0;i<MAXN;i++)
	spf[i]=i;
	for(i=4;i<MAXN;i+=2)
	spf[i]=2;
	for(i=3;i*i<MAXN;i++)
	{
		if(spf[i]==i)
		{
			for(j=i*i;j<MAXN;j+=i)
			{
				if(spf[j]==j)spf[j]=i;
			}
		}
	}
}*/
/*bool isvowel(char c)
{
    switch(c)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':return true;
        default : return false;
    }
}*/
/*bool isValid(int x,int y,int n,int m)
{
    if(x<0||x>n-1||y<0||y>m-1)return false;
    return true;
}*/
/*
bool comp(pair<int,int> x,pair<int,int> y)
{
    if(x.first==y.first)
        return x.second<y.second;
    return x.first>y.first;
}*/

int32_t main()
{
    ACC
    int T;
    T=1;
    //cin>>T;
    //sieve();
    while(T--)
    {
        int n,i;
        cin>>n;
        int a[n],b[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
        }
        for(i=n-2;i>=0;i--)
        {
            b[i]+=b[i+1];
        }
        int ans=0;
        for(i=0;i<n-1;i++)
        {
            ans+=((a[i]%mod)*(b[i+1]%mod))%mod;
        }
        cout<<ans%mod<<"\n";
    }
    return 0;
}
