#include <iostream>
#include <vector>

using namespace std;

int main(){
  int N; cin>>N;
  vector<int> H(N,0);
  for(int i=0;i<N;i++) cin>>H[i];

  int ans=0;

  for(int i=0;i<N;i++){
    bool check=true;
    for(int j=0;j<i;j++){
      if(H[i]<H[j]){
        check=false;
        break;
      }
    }
    if(check) ans++;
  }

  cout<<ans<<endl;

  return 0;
}
