#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define forx(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)



int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    sort(a.begin(),a.end());
    int k=n/2,mx=n-1,mn=0;
    ll ans=0;

    rep(i,n-1){
        if(i%2==1){
            ans+=abs(a[k]-a[mx]);
            k=mx;
            mx--;
        }
        else{
            ans+=abs(a[k]-a[mn]);
            k=mn;
            mn++;
        }
    }

    if(n%2==1){
        ll ans2=0;
        int k=n/2,mx=n-1,mn=0;
        rep(i,n-1){
        if(i%2==0){
            ans2+=abs(a[k]-a[mx]);
            k=mx;
            mx--;
        }
        else{
            ans2+=abs(a[k]-a[mn]);
            k=mn;
            mn++;
        }
    }
    ans=max(ans,ans2);
    }
    cout<<ans<<endl;
    return 0;
}
