#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define filein freopen("input.txt","r",stdin)
#define fileout freopen("output.txt","w",stdout)
using namespace std;
int n;
int  main()
{
    scanf("%d",&n);
    int ans=0;
    ll a=0;
    while(n--)
    {
        int x;
        scanf("%d",&x);
        if(x>=a)
        {
            ans++;
            a=x;
        }
    }
    cout<<ans<<endl;
}
