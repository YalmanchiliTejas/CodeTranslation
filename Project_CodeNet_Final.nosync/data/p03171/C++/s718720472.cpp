#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll ans[3000][3000];

ll max(ll a, ll b)
{
    if(a>=b) return a; else return b;
}

ll f(ll a[], ll i, ll j)
{
    if(i>j) return 0;
    if(ans[i][j]!=-1) return ans[i][j];
    if(i==j) {ans[i][j]=a[i]; return ans[i][j];}
    ans[i][j]=max(a[i]-f(a,i+1,j),a[j]-f(a,i,j-1));
    return ans[i][j];
}

int main() {
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++) cin>>a[i];
	//ll ans[n][n];
	for(ll i=0;i<3000;i++)
	{
	    for(ll j=0;j<3000;j++)
	    {
	        ans[i][j]=-1;
	    }
	}
	cout<<f(a,0,n-1);
	return 0;
}
