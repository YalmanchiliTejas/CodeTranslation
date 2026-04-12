#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define maxn 200005
#define vi vector<int>
#define vl vector<ll>
#define mii map<int,int>
#define mli map<ll,int>
#define forit(it,v) for(auto it=v.begin();it!=v.end();++it)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
void solve()
{
    int n;
    cin>>n;
    if (n>=30)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;
    // sieve();
    int t=1;
    // int t;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}