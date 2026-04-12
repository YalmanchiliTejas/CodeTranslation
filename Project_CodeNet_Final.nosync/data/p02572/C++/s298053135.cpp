#include <iostream>
#include<map>
#include<vector>
#include<string>
#include <climits>
#include<set>
#include<cmath>
#include<bitset>
using namespace std;
#define ll long long
#define M 1000000007
int main() {
    ll n;cin>>n;
    vector<ll> a(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<ll> b(n,0);
     b[n-1]=(a[n-1])%M;
    for(int i=n-2;i>=0;i--)
    {
        b[i]=((b[i+1]%M)+(a[i]%M))%M;
    }
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        ll k=((b[i]%M)-(a[i]%M)+M)%M;
        sum=((sum%M)+((a[i]%M)*(k%M))%M)%M;
   }
   cout<<sum<<endl;
    return 0;
}
