#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define N 300005
#define M 1000000007
#define pii pair<ll,ll>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

map<ll,ll>lst;

ll pref[N];

main()
{
    //cout<< (9999999212)/786;
    ll n,x,m;
    cin>>n>>x>>m;

    pref[1]=x;
    lst[x]=1;

    for(ll i=2;i<=n;i++)
    {
        x=(x*x)%m;

        if(lst[x]!=0)
        {
//            cout<<endl;
//            cout<<"in"<<endl;
            ll len=i-lst[x];
            ll cycsum=pref[i-1]-pref[lst[x]-1];
            ll baki=n-i+1;

            ll cyc=baki/len,ex=baki%len;
            ll ans=pref[i-1]+cyc*cycsum;
            //cout<<cyc<<' '<<ex<<' '<<cycsum<<' '<<len<<' '<<baki<<endl;
            if(ex)
            {
                ans+=pref[lst[x]+ex-1]-pref[lst[x]-1];
            }
            cout<<ans;
            return 0;
        }
        lst[x]=i;
        pref[i]=pref[i-1]+x;
    }
    cout<<pref[n];
}
/*
786 9999999212
*/
