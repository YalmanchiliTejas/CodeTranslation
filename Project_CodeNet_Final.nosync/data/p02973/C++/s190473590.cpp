#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e6+7;
const int inf=INT_MAX;
const ll inff=1e18;
const ll mod=1e9+7;
#define pii pair<int,int>
#define mkp make_pair
#define F first
#define S second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int ll
//#define endl '\n'

int n;
int a[maxn];
multiset<int> m;

int32_t main()
{
    IOS
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (m.lower_bound(a[i])==m.begin()) m.insert(a[i]);
        else
        {
            m.erase(prev(m.lower_bound(a[i])));
            m.insert(a[i]);
        }}
    cout<<sz(m)<<endl;
}

