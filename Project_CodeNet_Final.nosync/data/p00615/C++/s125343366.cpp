#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  
  int n,m;
  while(cin >> n >> m,n != 0 || m != 0){
    vector<int> vec(n+m,0);
    for(int i = 0;i < n+m;i++){
      cin >> vec[i];
    }
    sort(vec.begin(),vec.end());
    int ans = vec[0] - 0;
    for(int i = 0;i < n+m-1;i++){
      ans = max(vec[i+1] - vec[i],ans);
    }
    cout << ans << endl;
    
  }
    
  return 0;
}