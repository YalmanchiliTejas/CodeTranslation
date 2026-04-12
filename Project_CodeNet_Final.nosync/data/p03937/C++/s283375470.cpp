#include <iostream>
using namespace std;
int main(){
  int h,w;cin>>h>>w;
  char mp[h][w];
  int kazu = 0;
  for(int i = 0; h > i; i++){
    for(int j = 0; w > j; j++){
      cin>>mp[i][j];
      if(mp[i][j]=='#')kazu++;
    }
  }
  if(kazu != h+w-1){
    cout << "Impossible" << endl;
    return 0;
  }
  int nwx = 0;
  int nwy = 0;
  while(true){
    if(mp[nwx+1][nwy]=='#')nwx++;
    else if(mp[nwx][nwy+1]=='#')nwy++;
    else{
      cout << "Impossible" << endl;
      return 0;
    }
    if(nwx+nwy==kazu-1)break;
  }
  cout << "Possible" << endl;
}
    