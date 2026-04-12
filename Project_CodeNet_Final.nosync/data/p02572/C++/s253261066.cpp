#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
typedef  pair<int,int> P;

int n;
ll a[200005];
ll mod=1000000007;

int main()
{
cin>>n;
rep(i,n){cin>>a[i];}
ll ans=0;
ll sum=0;
rep(i,n)
{
sum+=a[i];

}
for(int i=0;i<n;i++)
{
sum-=a[i];
ans +=((a[i]%mod)*(sum%mod))%mod;
ans=ans%mod;


}

ans=ans%mod;
cout <<ans;
}

