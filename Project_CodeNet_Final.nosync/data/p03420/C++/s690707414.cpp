#include <bits/stdc++.h>

using namespace std;

#define int long long
#define N 100005
#define MOD 1000000007

int ans[N];

int32_t main()
{
    int n, k;
    cin>>n>>k;

    int ans = 0;
    if( k == 0)
    {
        ans = n*n;
        cout<<ans<<endl;
        return 0;
    }
    for(int i=k+1;i<=n;i++)
    {
        int temp = n/i;
        ans+= (i-k)*temp;
        temp = n%i;
        if( temp>=k && temp)
            ans+= (temp - k + 1);
    }
    cout<<ans<<endl;

    return 0;
}