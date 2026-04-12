#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define mod 1000000007
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lld n,i;
    cin>>n;
    lld a[n+1];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<lld>v;
    lld s=0,k=0;
    for(i=n-1;i>0;i--)
    {
        s=(s%mod+a[i])%mod;
        v.push_back(s);
    }
    lld j=0;
    for(i=n-2;i>=0;i--)
    {
        k=(k%mod+(v[j]*a[i])%mod)%mod;
        j++;
    }
    cout<<k;
	return 0;
}
