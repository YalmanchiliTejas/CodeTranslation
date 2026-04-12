#include<bits/stdc++.h>
using namespace  std;
const int N=1e9+7;
const int M=2e5+100;
typedef long long ll;
ll qian[M];
ll multi(ll a, ll b, ll m){

    // a * b % m

    ll ret = 0;

    while(b > 0){

        if(b & 1){

            ret = (ret + a) % m;

        }

        b >>= 1;

        a = (a << 1) % m;

    }

    return ret%m;

}


int main()
{
     ll n;
     cin>>n;
     ll a[n];
     for(ll i=0;i<n;i++)
        {cin>>a[i];
         qian[i+1]=a[i]+qian[i];
        }
    ll sum=0;
    for(ll i=1;i<n;i++)
    {
        sum+=multi(a[i],qian[i],N);

    }
    cout<<sum%N<<endl;

}
