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
  int n;
  cin>>n;
  vector<int> h(n,0);
  for(int i=0;i<n;i++) cin>>h[i];

  int ma=0;
  int ans=0;
  for(int i=0;i<n;i++){
    if(ma<=h[i]) ans++;
    ma=max(ma,h[i]);
  }
  cout<<ans<<endl;

  return 0;
}
