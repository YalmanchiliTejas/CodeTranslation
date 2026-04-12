#include<bits/stdc++.h>
using namespace std;


int n,k;
long long ans;

int main()
{
    cin >> n >> k;

    for(int i=k+1;i<=n;i++)
    {
        int q = (n+1)/i-1;
        ans += (q+1) * (i-k);
        int a = (q+1) * i+k;
        if(a <= n) ans+= min(n-a+1, i-k);
    }
    if(k == 0) ans -= n;
    cout << ans << endl;


    return 0;
}
