#include <iostream>
using namespace std ;

int main(){
  int N; cin>>N;

  int H[21];
  for(int i=0;i<N;i++) cin>>H[i];

  int ans=1;
  for(int i=1;i<N;i++){
    int singi=1;
    for(int j=0;j<i;j++){
      if(H[i]<H[j]){
        singi=0;
        break ;
      }
    }
    if(singi==1) ans++;
  }

  cout<<ans;
}
