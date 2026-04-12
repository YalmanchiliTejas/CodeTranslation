#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define PI acos(-1)
#define bp __builtin_popcountll
#define all(x) x.begin(),x.end()
#define sp fixed<<setprecision
#define pii pair<long long,long long>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int MOD = (1e9)+7;
const int N = (1e6)+5;

signed main()
{
    FAST
    int tc=1;
    //cin>>tc;
    for(int ti=1;ti<=tc;ti++)
    {
        int n;
        cin>>n;
        int a[n],s[2] = {};
        for(int i=0;i<n;i++)cin>>a[i],s[i%2]+=a[i];
        int pre[n];
        for(int i=0;i<n;i++)pre[i] = a[i];
        for(int i=2;i<n;i++)pre[i]+=pre[i-2];
        int suf[n];
        for(int i=0;i<n;i++)suf[i] = a[i];
        for(int i=n-3;i>=0;i--)suf[i]+=suf[i+2];

        int ans = s[1];
        for(int i=0;i<n;i++)
        {
            int chk = pre[i];
            int fcnt = (i+2)/2;
            if(fcnt == n/2)ans = max(ans,pre[i]);
            for(int j=i+2;j<n;j++)
            {
                int ind = n-1-j;
                int bcnt = (ind+2)/2;
                if(bcnt+fcnt < n/2)break;
                else if(bcnt+fcnt == n/2)ans = max(ans,pre[i]+suf[j]);
            }
        }
        if(!(n%2))return cout<<ans,0;
        ans = max(s[0]-a[0],ans);
        ans = max(s[0]-a[n-1],ans);
        int suf1[n];
        for(int i=0;i<n;i++)suf1[i] = suf[i];
        for(int i=n-2;i>=0;i-=2)
        {
            if(i == n-2)suf1[i] = max(suf1[i],suf1[i+1]);
            else
            {
                suf1[i] = max(suf1[i],a[i]+suf1[i+2]);
                suf1[i] = max(suf1[i],suf1[i+1]);
            }
        }
        for(int i=0;i<n;i++)
        {
            int chk = pre[i];
            int fcnt = (i+2)/2;
            if(fcnt == n/2)ans = max(ans,pre[i]);
            for(int j=i+2;j<n;j++)
            {
                int ind = n-1-j;
                int bcnt = (ind+2)/2;
                if(bcnt+fcnt < n/2)break;
                else if(bcnt+fcnt == n/2)ans = max(ans,pre[i]+suf1[j]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
Test Case
*/
