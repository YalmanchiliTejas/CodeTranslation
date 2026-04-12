#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n, k; cin>>n>>k;
    if (k==0) {
        cout<<n*n<<endl;
        return 0;
    }
    long res=0;
    for(long d=k+1; d<=n; ++d) {
        auto x=(n+d-1)/d;
        res+=x*(d-k);
        auto L=(x-1)*d+k;
        auto R=L+d-k-1;
        if (L>n) res-=R-L+1;
        else if (R>n) res-=R-n;
    }
    cout<<res<<endl;
}
