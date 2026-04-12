#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long LL;

const int maxn=1e5+5;
int a[maxn],f[maxn],n,len;

int main()
{
    //freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",&a[n-i-1]);
    fill(f,f+n+2,1e9+5);
    for(int i=0;i<n;i++) *upper_bound(f,f+n,a[i])=a[i];
    cout<<lower_bound(f,f+n,1e9+5)-f;

	return 0;
}
