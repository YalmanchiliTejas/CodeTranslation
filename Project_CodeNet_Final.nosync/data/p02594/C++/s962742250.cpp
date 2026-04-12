#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define pb push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=a;i>b;i--)
#define mkp(a,b) make_pair(a,b)
#define all(v) v.begin(),v.end()
using namespace std;
bool compare(pair<int,int>& p1,pair<int,int>& p2)
{
    return p1.second<p2.second;
}
int main()
{
    fastio
    ll x;
    cin>>x;
    if(x>=30)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}