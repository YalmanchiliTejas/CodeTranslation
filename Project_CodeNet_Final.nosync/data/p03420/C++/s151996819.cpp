#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll sum=0;
    ll n,k;
    cin >> n >> k;
    if(k==0)
    {
        sum=n*n;
        cout << sum << endl;
        return 0;
    }
    for(int i=k+1;i<=n;i++)
    {
        int p=n/i;
        int res=n%i;
        if(res>=k)
            res=res-k+1;
        else
            res=0;
        sum+=(p*(i-k)+res);
    }
    cout << sum << endl;
    return 0;
}
