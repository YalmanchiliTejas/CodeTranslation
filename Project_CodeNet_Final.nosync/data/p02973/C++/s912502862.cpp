#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=100000+5;

int a[N];
int b[N];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",a+i),a[i]=-a[i];

    memset(b,0x3f,sizeof(b));
    int ans=0;
    for(int i=0;i<n;++i)
    {
        int pos=upper_bound(b,b+N,a[i])-b;
        b[pos]=a[i];
        ans=max(ans,pos);
    }
    cout<<ans+1;
    return 0;
}
/*

*/
