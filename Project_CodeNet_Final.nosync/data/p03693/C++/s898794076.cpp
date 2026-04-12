#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define pb(x) push_back(x)
#define MP(x,y) make_pair(x,y)
using namespace std;
ll pow(ll a, ll b, ll m)
{
	if(b==0)
		return(1);
	ll sol=pow(a,b/2,m);
	sol=(sol*sol)%m;
	if(b%2==1)
		sol=(sol*a)%m;
	return(sol);
}
string s;
void solve()
{
	int a,b,c,sol=0;
	cin>>a>>b>>c;
	sol=a*100+b*10+c;
	if(sol%4==0)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
}

int main()
{
    int t=1,num=1;
    //cin>>t;
    while(t--)
    {	
        solve();
        //printf("Case #%d: %s\n",num,s);
		//num++;
    }
    return 0;
}
