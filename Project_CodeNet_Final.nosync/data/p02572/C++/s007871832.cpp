#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
const ll MOD=1000000007;
const long double PI=3.14159265358979;
const ll MAX=0;

int main() {
  ll N;
  cin>>N;
  ll a[N],sum=0;
  rep(i,N){
    cin>>a[i];
    sum+=a[i];
    sum%=MOD;
  }
  sum*=sum;
  rep(i,N){
    ll A=a[i];
    A*=A;
    A%=MOD;
    sum-=A;
    if(sum<0){
      sum+=MOD;
    }
    sum%=MOD;
  }
  if(sum%2==1){
    sum+=MOD;
  }
  sum/=2;
  cout<<sum;
}
