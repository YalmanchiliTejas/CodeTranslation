#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl "\n"
const int MAX= 100005 ;
const long long mod = 998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,i;
    cin>>n;
    ll arr[n+1];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    multiset<ll> ms;
    for(i=0;i<n;i++)
    {
        auto it= ms.lower_bound(arr[i]);
        if(it==ms.begin())
        {
            ms.insert(arr[i]);
        }
        else
        {
            it--;
            ms.erase(it);
            ms.insert(arr[i]);
        }
    }
    cout<<ms.size()<<endl;
    return 0;
}