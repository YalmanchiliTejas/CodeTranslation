// --------------------<optimizations>--------------------
#pragma GCC optimize("O3")

//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)\
#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN TRYING TO BRUTEFORCE WITH A LOT OF LOOPS)\
#pragma GCC optimize("unroll-loops")
// -------------------</optimizations>--------------------
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define d long double
#define pii pair<int,int>
#define pb push_back
#define pf push_front
#define cases int t;cin>>t;while(t--)
#define N 100003
#define M 103
#define inf LLONG_MAX
//int mod=1e9+7;
//int mod=998244353;

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    cin>>n;
    int ans=0,ma=0,i,x;
    for(i=1;i<=n;++i)
    {
        cin>>x;
        if(x>=ma)
            ++ans;
        ma=max(ma,x);
    }
    cout<<ans;



    return 0;
}
