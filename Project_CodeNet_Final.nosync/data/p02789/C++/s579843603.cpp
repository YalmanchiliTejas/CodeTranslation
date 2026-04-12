#include<bits/stdc++.h>
using namespace std;
#define M ((ll)(1e9)+7)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
typedef long long ll;

bool comp(pair<ll,ll> a,pair<ll,ll> b)
{
    if(a.S<b.S)
    return true;
    return false;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    if(n==m)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
}
int main()
{
    solve();
    return 0;
}
