#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int N=2e5+5;
const int MOD=1e9+7;
ll a[N];
int b[N];
int n,k,m;
int cmp(int a,int b)
{
    return a>b;
}

map <int,int> mp;
string s;
string t;

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll sum=a[1];
    ll ans=0;
    for(int i=2;i<=n;i++){
        ans=(ans+(sum*a[i])%MOD)%MOD;
        sum+=a[i];
        sum=sum%MOD;

    }
    cout<<ans<<endl;
}




