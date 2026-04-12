#include<iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using lint=long long;

int main() {
  int n,ans=1,maxm;
  cin >> n;
  std::vector<int> v(n);
  for(int i=0;i<n;i++) {
    cin>>v[i];
  }
  maxm=v[0];
  for(int i=1;i<n;i++){
    if(v[i]>=v[i-1]&&v[i]>=maxm) {
      ans++;
      maxm=v[i];
    }
  }
  cout << ans << endl;
  return 0;
}
