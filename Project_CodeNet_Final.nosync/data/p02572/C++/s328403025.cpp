#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back 

ll const mod=1e9+7;





int main()
{

int n;
cin>>n;
ll a[n],p[n+1];
int i=1;
p[0]=0;
for(auto &x:a)
{
	cin>>x;
	p[i]=(p[i-1]+x+mod)%mod;
	i++;
}
ll ans=0;
for(int j=0;j<n;j++)
{
	ans+=(p[j]*a[j]+mod)%mod;
	ans=(ans+mod)%mod;
}

cout<<(ans+mod)%mod;

}