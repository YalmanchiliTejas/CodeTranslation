#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    ll n, k, ans=0;
    cin >> n >> k;
    for(ll b=k+1; b<=n; ++b)
    {
        ans+=(n/b)*(b-k);
        ans+=max(0LL, n%b-k+(k!=0));
    }
    cout << ans << endl;
    return 0;
}
