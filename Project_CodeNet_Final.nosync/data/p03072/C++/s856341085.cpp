#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define int long long
#define PB push_back
#define N 500001
#define LG 22
#define MXQ 200001
#define M 1000000007
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define LD double
#define F first
#define S second
#define ll long long
#define inf LLONG_MAX
#define endl "\n"

int32_t main()
{
    LL i,j,lt,d,z,v,c,r,l,q,x,y,m,n,x1,y1,t1,k;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    LL a[n];
    k=0;
    x=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>=x)
            k++;
        x=max(x,a[i]);
    }
    cout<<k;
}       