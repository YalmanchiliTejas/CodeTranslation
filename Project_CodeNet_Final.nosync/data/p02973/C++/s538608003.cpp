#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int main()
{
    ll n,ans=0;
    cin>>n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    multiset<ll> ms;
    for (int i = 0; i < n; i++)
    {
        auto it = ms.lower_bound(a[i]);
        if(it==ms.begin())
        {
            ms.insert(a[i]);
        }
        else
        {
            it--;
            ms.erase(it);
            ms.insert(a[i]);
        }
    }
    cout<<ms.size()<<endl;
    
    return 0;
}