#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define pii pair<int,int>

using namespace std;

const int mod = 1e9 + 7;
const int nax = 2e5+5;
ll a[nax];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll sum = 0;
    int n; cin>>n;
    ll ans =0 ;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum += a[i];
    }
    sum %= mod;
    sum -= a[1];
    if(sum < 0) sum += mod;
    for(int i=1;i<n;i++)
    {
        ans += sum * a[i];
        ans %= mod;
        sum -= a[i + 1];
        if(sum < 0) sum += mod;
    }
    cout<<ans;

    return 0;
}
