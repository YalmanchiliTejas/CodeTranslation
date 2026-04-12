#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repa(i,arr,n) for(int i=arr;i<=n;i++)
#define repd(i,arr,n) for(int i=arr;i>=n;i--)
#define trav(arr,x) for(auto& arr:x)
#define all(c) c.begin(), c.end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(arr) arr.size()
#define pi 3.14159265358979323846
#define MAX (1000*1000*1000+7)
#define vi vector<int>
#define pii pair<int,int>
#define pqueue priority_queue<int>
#define pdqueue priority_queue<int,vi,greater<int> >

const int mod = 1e9+7;
const int inf=1e17+9;

int power(int a,int b,int p)
{
    int ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*a)%p;
        }
        a=(a*a)%p;
        b>>=1;
    }
    return ans;
}
int32_t main()
{
    fast;
    int n,k;
    string str;
    cin>>n>>str>>k;
    rep(i,n)
    {
        if(str[i]!=str[k-1])
            str[i]='*';
    }
    cout<<str;
    return 0;
}