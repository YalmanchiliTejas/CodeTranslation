#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    int n,i,mh,h,ans=1;
    cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>h;
        if (i==0)
            mh=h;
        else if (h>=mh)
            ans++;
        mh=max(mh,h);
    }
    cout<<ans<<endl;
}