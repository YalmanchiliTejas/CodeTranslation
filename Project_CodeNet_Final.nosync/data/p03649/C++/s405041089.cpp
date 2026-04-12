#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 55;
const int inf = 1000000007;

int n;
ll a[maxn];

int main() {
  //freopen("in.cpp","r",stdin);
  cin>>n;
  for(int i=0; i<n; i++)cin>>a[i];
  ll ret=0,sum2=0;
  while(1) {
    sum2=0;
    for(int i=0; i<n; i++) {
      sum2+=a[i]/n;
    }
    //cout<<sum2<<endl;
    if(sum2==0)break;
    ret+=sum2;
    for(int i=0; i<n; i++) {
      a[i]=a[i]%n+sum2-a[i]/n;
      //cout<<i<<" "<<a[i]<<endl;
    }
  }
  cout<<ret<<endl;
  return 0;
}
