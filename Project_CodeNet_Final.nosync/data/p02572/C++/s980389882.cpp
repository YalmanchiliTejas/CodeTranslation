#include<bits/stdc++.h>
#define mods 1000000007
#define fint register int
#define int long long
using namespace std;
int s,ans;
int a[200003];
signed main()
{
	int n;
    cin>>n;
    for(int i=1;i<=n;i++) 
	cin>>a[i];
    sort(a+1,a+1+n);
    for(fint i=2;i<=n;i++)
    s=(s+a[i-1])%mods,ans=(ans+s*a[i])%mods;
    cout<<ans;
    return 0;
}