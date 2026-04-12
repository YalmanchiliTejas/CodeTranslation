//agrawal117
//chahatagrawal117
#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
typedef long long int ll;
using namespace std;
#define MAX 100005
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,x,m; cin>>n>>x>>m;
    if(n==1)  { cout<<x<<endl; return 0; }
    ll arr[m+4];
    ll sum=0;
    sum+=x;
    map<ll,ll> mp;
    arr[1]=x;
    mp[x]=1;
    for(int i=2;i<=n;i++)
    {
        ll val=arr[i-1]*arr[i-1];
        val%=m;
        if(mp.count(val))
        {
            ll j=mp[val];
            ll no=i-j;
            ll fck=0;
            for(int k=j;k<=i-1;k++){
                fck+=arr[k];
            }
            ll left=n-i+1;
            ll f=left/no;
            f=(f*fck);
            sum+=f;
            left=left%no;
            int cnt=0;
            for(int k=j;k<=i-1;k++){
                if(cnt==left) break;
                sum+=arr[k];
                cnt++;
            }
            cout<<sum<<endl;
            return 0;
        }
        else {
            
            mp[val]=i;
            arr[i]=val;
        }
        // cout<<arr[i]<<endl;
        sum+=arr[i];
        if(i==n) { cout<<sum<<endl; return 0;  } 
    }
}