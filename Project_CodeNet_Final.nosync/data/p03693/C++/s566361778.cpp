#include<bits/stdc++.h>
using namespace std;
#define opt ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
#define mod		1000000007
#define inf     1000000000000000000
#define MX1		100005
#define MX2		10000004
#define pi		acos(-1)
#define pb      push_back
#define vlli    vector<lli>
#define plli    vector<pair<lli,lli> >
#define mp      make_pair
#define all(v)  v.begin(),v.end()
#define test    int t;cin>>t;
lli gcd(lli a, lli b){return b?gcd(b,a%b):a;}
lli power(lli a,lli b){lli ans=1;while(b){if(b&1){ans=(ans*a)%mod;}a=(a*a)%mod;b>>=1;}return ans;}
int main()
{
	opt;
	lli r,g,b;
cin>>r>>g>>b;
lli ans;
ans=(r*100)+(g*10)+b;
if(ans%4==0)
cout<<"YES\n";
else
cout<<"NO\n";

	return 0;
}
