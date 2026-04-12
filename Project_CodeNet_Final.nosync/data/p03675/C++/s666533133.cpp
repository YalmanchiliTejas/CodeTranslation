#include <iostream>

using namespace std;
int n,a[200001],i;
int main()
{
    cin>>n; for(i=1;i<=n;i++) cin>>a[i];
    for(i=n;i>=1;i=i-2) cout<<a[i]<<' ';
    for(i=1+n%2;i<=n;i=i+2) cout<<a[i]<<' ';
    return 0;
}
