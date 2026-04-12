#include <bits/stdc++.h>
#include <fstream>
#define ll long long
#define ld long double
#define int long long
#define MOD 1000000007
#define mod 1000000007
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define vvi vector<vi>
#define mp make_pair
#define endl "\n"
using namespace std;
const int f=100000;
int solvevec(vi vec);
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
    int n;cin>>n;
    int arr[n],brr[n];int c=0,ans=0;
    cin>>arr[0];brr[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        cin>>arr[i];
        brr[i]=brr[i-1]+arr[i];brr[i]%=MOD;
    }
    for(int i=1;i<n;i++)
    {
        ans+=arr[i]*brr[i-1];ans%=MOD;
    }
    cout<<ans<<endl;
}


