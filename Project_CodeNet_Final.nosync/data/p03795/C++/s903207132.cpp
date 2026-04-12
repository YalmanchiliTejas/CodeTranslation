#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<queue>

using namespace std;

int main(){
  int n;cin>>n;
  int ans = 0;
  for(int i=0;i<n;i++){
    ans += 800;
    if(i%15 == 14) ans -= 200;
  }
  cout<<ans<<endl;
  return 0;
}
