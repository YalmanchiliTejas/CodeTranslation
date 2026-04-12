#include "bits/stdc++.h"
using namespace std ;
#define ll            long long
#define nl            "\n"
#define PB            push_back
#define fi            first
#define se            second
#define _SAD()        ios::sync_with_stdio(0),cin.tie(0), cout.tie(0);
#define SZ(s)         s.size()
#define SRT(x,y)      sort(x,x+y)
#define REV(a,b)      reverse(a,a+b)
#define VSRT(x)       sort(x.begin(),x.end())
#define VREV(x)       reverse(x.begin(),x.end())
int main()
{
    _SAD()
    int n,cnt=1,fl=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    fl=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>=fl)
        {
            fl=a[i];
            cnt++;
        }
    }
    cout<<cnt<<nl;
    return 0;
}
