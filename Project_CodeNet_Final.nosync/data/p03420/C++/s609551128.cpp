#include<iostream>
using namespace std;
typedef long long LL;
int main()
{
    LL n, k; cin >> n >> k;
    LL ans = 0;
    for(LL b = k+1; b <= n; b++)
    {
        LL t = (n+1)/b;
        ans += t*(b-k);
        if(k==0)
            ans--;
        //next segment is [k+tb, (t+1)b-1] intersection [1,n]
        if(n < k+t*b)
            ans += 0;
        else
            ans += n-(k+t*b)+1;
    }
    cout<<ans<<endl;
    return 0;
}