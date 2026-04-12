#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin>>n;
  int ans = 1;
  int first;
  cin>>first;
  int max_of = first;
  for(int i=0;i<n-1;i++){
    int x;
    cin>>x;
    max_of=max(max_of,x);
    if(x>=max_of){
        ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
