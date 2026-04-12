#include <iostream>
#include <algorithm>
#define MAX 200010
#define x first
#define y second

using namespace std;

int n,v1,v2;
int ans[MAX];
pair<int,int> a[MAX];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].x,a[i].y=i;
    sort(a+1,a+n+1);
    v1=a[n/2].x,v2=a[n/2+1].x;
    for(int i=1;i<=n/2;i++) ans[a[i].y]=v2;
    for(int i=n/2+1;i<=n;i++) ans[a[i].y]=v1;
    for(int i=1;i<=n;i++)cout<<ans[i]<<'\n';
    return 0;
}
