#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int a[N],b[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],b[i]=a[i];
    sort(a+1,a+1+n);
    int x=a[n/2],y=a[n/2+1];
    for(int i=1;i<=n;i++)
    {
        if(b[i]<=x)cout<<y;
        else cout<<x;
        cout<<"\n";
    }
    return 0 ;
}
