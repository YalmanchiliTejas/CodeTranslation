#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  int n,q;
  cin>>n>>q;
  int a[q+1]={},b[q+1]={};
  for(int i=0;i<q;i++){
      cin>>a[i]>>b[i];
  }

  int ball[n+1]={};
  ball[1]=2;
  ball[2]=1;
  int it=1;

  for(int i=0;i<q;i++){
      if(a[i]==it) it=b[i];
      else if(b[i]==it) it=a[i];

      swap(ball[a[i]],ball[b[i]]);
      if(it>1) ball[it-1]=1;
      if(it<n) ball[it+1]=1;
  }

  int ans=0;
  for(int i=1;i<=n;i++){
      if(ball[i]>0) ans++;
  }
  cout<<ans<<endl;

  return 0;
}
