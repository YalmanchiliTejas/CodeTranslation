#include <bits/stdc++.h>
#define ll long long
#define int long long
#define MOD 1000000007
#define mod 998244353
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define vvi vector<vi>
#define endl "\n"
using namespace std;
void solve1();
void solve()
{
    int T;cin>>T;
    for(int z=1;z<=T;z++)
    {
        solve1();
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve1();
    return 0;
}
void solve1()
{
    int x;cin>>x;
    if(x>=30)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
