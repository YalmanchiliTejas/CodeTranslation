#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
int mod1=998244353,mod2=(int)1e9+7;
int power(int n,int k,int mod){int ans=1; n=n%mod;while(k>0){if(k&1)ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return (ans+mod)%mod;}//negative nos & 0^0
struct triplet{int a,b,c;};bool operator < (const triplet &t1,const triplet &t2){if(t1.a<t2.a)return true;if(t1.a==t2.a && t1.b <t2.b)return true;if(t1.a==t2.a && t1.b ==t2.b && t1.c<t2.c)return true;return false;}

int32_t main()
{

	fio;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	 int t=1; 
	 // cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	int sumsq=0,sum=0;
    	for(int i=0;i<n;i++)
    	{
    		cin>>a[i];
    		sumsq=(sumsq+a[i]*a[i])%mod2;
    		sum=(sum+a[i])%mod2;
    	}	
    	int x=((sum*sum)%mod2-sumsq%mod2+mod2)%mod2;
    	int inv2=power(2,mod2-2,mod2);
    	cout<<(x*inv2)%mod2;

    }
}
