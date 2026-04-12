#include<bits/stdc++.h>
using namespace std;
#define fr(x,i,n) for(int x = i; x < n; ++x)
#define fb(x,i,n) for(int x = i; x >= n; --x)
#define pr pair<int,int>
#define ll long long int
const int mod=1e9+7;
int n;
ll a[200001];
ll dp1[200001];
void ev(){

    ll ans=max(dp1[0],dp1[1]);
    ll sum=0;
    for(int i=0;i<n;i+=2){
        sum+=a[i];
        ans=max(ans,sum+dp1[i+3]);
    }
    cout<<ans;
}
void od(){
    ll ans=max({dp1[0],dp1[1],dp1[2]}); // case 4,6
    ll sum=0;
    for(int i=0;i<n;i+=2){ // case 1
        sum+=a[i];
        ans=max(ans,sum+dp1[i+4]);
    }
    sum=0;
    for(int i=0;i<n;i+=2){ // case 3
        sum+=a[i];
        ans=max(ans,sum+dp1[i+3]);
    }
    sum=0;
    for(int i=1;i<n;i+=2){ // case 5
        sum+=a[i];
        ans=max(ans,sum+dp1[i+3]);
    }
    if(n<7)
    {
        cout<<ans;
        return;
    }
    //case 2
    ll dp2p[n][2],dp2s[n][2];
    //dp2p[i][0]... prefix...no 2 steps taken
    //dp2p[i][1]... prefix...one 2 steps taken
    dp2p[2][0]=a[0]+a[2];
    dp2p[3][0]=a[1]+a[3];
    dp2p[3][1]=a[0]+a[3];
    dp2p[4][0]=a[0]+a[2]+a[4];
    dp2p[4][1]=INT_MIN;
    fr(i,5,n-3){
        dp2p[i][0]=dp2p[i-2][0]+a[i];
        if(i%2==0)
        dp2p[i][1]=INT_MIN;
        else
        dp2p[i][1]=max(a[i]+dp2p[i-3][0],a[i]+dp2p[i-2][1]);
    }
    dp2s[n-1-2][0]=a[n-1]+a[n-3];
    dp2s[n-1-3][0]=a[n-1-1]+a[n-1-3];
    dp2s[n-1-3][1]=a[n-1-0]+a[n-1-3];
    dp2s[n-1-4][0]=a[n-1-0]+a[n-1-2]+a[n-1-4];
    dp2s[n-1-4][1]=INT_MIN;
    fb(i,n-1-5,2){
        dp2s[i][0]=dp2s[i+2][0]+a[i];
        if(i%2==0)
        dp2s[i][1]=INT_MIN;
        else
        dp2s[i][1]=max(a[i]+dp2s[i+3][0],a[i]+dp2s[i+2][1]);
    }
    fr(i,3,n-3)
    if(i%2==1)
    ans=max(ans,dp2p[i][1]+dp2s[i][1]-a[i]);
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    fr(i,0,n)
    cin>>a[i];
    dp1[n-1]=a[n-1];
    dp1[n-2]=a[n-2];
    fb(i,n-3,0)
    dp1[i]=a[i]+dp1[i+2];
    if(n%2==0)
    ev();
    else
    od();
}
