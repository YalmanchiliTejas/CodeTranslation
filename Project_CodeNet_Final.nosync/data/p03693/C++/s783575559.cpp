//If you are reading this then you are at wrong place.
#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int
using namespace std;
bool prime [1000001];
void debug(lli a){cout<<a<<endl;}
lli sieve(lli a){memset(prime,true,sizeof(prime));lli p,i;for(p=2;p*p<=a;p++){if(prime[p]==true){for(i=p*2;i<=a;i+=p)prime[i]=false;}}return 0;}
lli powermod(lli _a,lli _b,lli _m){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
lli find_max(lli __a,lli __b){return __a^((__a^__b) & -(__a<__b));}
lli add(lli __a,lli __b,lli MOD){lli x = (__a+__b)%MOD; return x; }
lli mul(lli a,lli b,lli MOD){lli x = (a*b)%MOD; return x; }
lli sub(lli a,lli b,lli MOD){lli x = (a-b+MOD)%MOD; return x; }
lli div(lli a,lli b,lli MOD){lli x = a;lli y = powermod(b,MOD-2,MOD);lli res = (x*y)%MOD;return res;}
int main()
{
	//ifstream cin("testcase.txt");
	//ofstream cout("output.txt");	
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);	
	cout.precision(20);
	lli t,i,j;
	//cin>>t;
	//memset(dp, -1, sizeof dp);
	t=1;
	lli counter1=0;
	while(t--)
	{
		counter1++;
		int a,b,c;
		cin>>a>>b>>c;
		int q=a*100+b*10+c;
		if(q%4==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		
		//cout<<"Case #"<<counter1<<" ";
		//cout<<endl;	
	}	
}
