#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int mod=1e9+7;
ll f[10010][101],d,ans,cnt;
string k;
int main()
{
	cin>>k>>d;
	f[0][0]=1;
	for(int i=1;i<=k.size();i++)
	{
		for(int j=0;j<=9;j++)
		{
		//	if(i!=1 || j)
			{
			//	if(j || i!=k.size()) 
			//	{
					for(int l=0;l<d;l++)
					{
						if(l>=j)
							f[i][l]=(f[i][l]+f[i-1][l-j])%mod;
						else
						{
							f[i][l]=(f[i][l]+f[i-1][d+(l-j)%d])%mod;
							if(d+(l-j)%d==d)
								f[i][l]=(f[i][l]+f[i-1][0])%mod;
						}
							
					}
			//	}
			}
			
			
		}
//		for(int l=0;l<d;l++)
//			cout<<i<<' '<<l<<' '<<f[i][l]<<endl;
	}
	for(int i=0;i<k.size();i++)
	{
		
		for(int j=0;j<k[i]-'0';j++)
		{
		//	if(j<k[i]-'0')
			{
				ans=(ans+f[k.size()-i-1][d-(cnt+j)%d])%mod;
				if(d-(cnt+j)%d==d)
					ans=(ans+f[k.size()-i-1][0])%mod; 
		//		cout<<d-(cnt+j)%d<<endl;
			}
		}
		cnt+=k[i]-'0';
	}
	int cnt1=0;
	for(int i=0;i<k.size();i++)
		cnt1+=k[i]-'0';
	if(cnt1%d==0)
		ans++;
	cout<<(ans+mod-1)%mod<<endl;
	return 0;
}
