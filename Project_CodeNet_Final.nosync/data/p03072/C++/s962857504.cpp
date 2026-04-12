#include <iostream>
#include <vector>
using namespace std;
int main(){
  int N;cin>>N;
  vector<int> H(N);  
  for (int i=0;i<N;++i) cin>>H[i];
  int tmp=0;
  int ans=0;
  for (int i=0;i<N;++i){
    if (H[i]>=tmp){
      tmp=H[i];
      ans++;
    }
  }
  cout<<ans<<endl;
}
        
        
      