#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >

const int N=500000;
ll a[N];
int md=1e9+7;
    ll sum,ans;
int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }

    for(int i=0;i<n;i++){
            sum-=a[i];
        ans+=((sum%md) * (a[i]%md))%md;
        ans%=md;
    }
    cout<<ans;

}
