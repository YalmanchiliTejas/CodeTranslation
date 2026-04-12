#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mkp make_pair
#define rep(i,s,f) for(i=s;i<f;i++)
#define db cout<<'h'<<'i'<<endl 
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define vi vector<int>
#define vii vector<pair<int,int>>
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define PI 3.14159265
#define mod 1000000007
#define mod2 998244353
#define space 100005
#define lg 18
//<<fixed << setprecision(9)

int main()
{
    int n,i,j,t;
    boost;

    cin>>n;
    int arr[n];
    rep(i,0,n)cin>>arr[i];

    multimap<int,int> mp;

    mp.insert({arr[n-1],1});

    for(i=n-2;i>=0;i--)
    {
        auto it=mp.upper_bound(arr[i]);
        if(it==mp.end())
        {
            mp.insert({arr[i],1});
        }
        else
        {
            mp.erase(it);
            mp.insert({arr[i],1});
        }
    }
    cout<<mp.size();

    return 0;
}

