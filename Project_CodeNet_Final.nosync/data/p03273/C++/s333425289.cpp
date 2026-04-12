#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  int h,w; cin>>h>>w;
  vector<string> a(h);
  for(int i=0; i<h; i++)cin>>a[i];

  vector<bool> hi(h,false);
  vector<bool> wi(w,false);

  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      if(a[i][j] == '#'){
        hi[i] = true;
        wi[j] = true;
      }
    }
  }

  for(int i=0; i<h; i++){
    if(hi[i]){
      for(int j=0; j<w; j++){
        if(wi[j]){
          cout<<a[i][j];
        }
      }
      cout<<endl;
  }
}

return 0;
}