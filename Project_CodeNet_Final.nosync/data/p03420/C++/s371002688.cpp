#include<bits/stdc++.h>
#define N 100010
typedef long long ll;
using namespace std;
int main(){
  ll n,k,sum=0;
  scanf("%lld%lld",&n,&k);
  if (!k)  sum=n*n;
  else {
      for (int i=k+1;i<=n;i++)
         sum+=(n/i)*(i-k)+max(0LL,n%i-k+1);
  }
  cout << sum << endl;
  return 0;
}
