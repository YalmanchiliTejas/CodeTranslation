#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;

int main(){
    ll a[200005],b[200005];
    ll x=1000000007;
    ll n;
    cin>>n;
    cin>>a[0];
    b[0]=a[0];
    ll ans=0;
    for(ll i=1;i<n;i++){
        cin>>a[i];
        b[i]=a[i]+b[i-1];
        b[i]%=x;
        ans+=(a[i]%x)*(b[i-1]%x);
        ans%=x;
    }
    cout<<ans%x<<endl;
}