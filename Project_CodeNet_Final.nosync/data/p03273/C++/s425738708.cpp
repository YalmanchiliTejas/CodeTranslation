#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin>>h>>w;
  vector<string> v(h);
  for(int i=0; i<h; i++){
    cin>>v[i];
  }
  vector<int> h_flag(h);
  vector<int> w_flag(w);
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      if(v[i][j]=='#'){
        h_flag[i] = 1;
      }
    }
  }

  for(int j=0; j<w; j++){
    for(int i=0; i<h; i++){
      if(v[i][j]=='#'){
        w_flag[j] = 1;
        break;
      }
    }
  }
  
  for(int i=0; i<h; i++){
	int flag = 0;
    for(int j=0; j<w; j++){
      if(h_flag[i] == 1 && w_flag[j] == 1){
        cout<<v[i][j];
        flag = 1;
      }
    }
    if(flag == 1)cout<<endl;
  }

  
}