#include<bits/stdc++.h>
using namespace std;
static const int N=100000;

int n,a[N+5];
int t,k;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>k;
        cout<<lower_bound(a, a+n, k)-a<<endl;
    }
    return 0;
}


