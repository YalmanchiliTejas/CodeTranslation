#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<string.h>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
  int H, W;
  int h=0;
  int w=0;
  string tmp;
  int m =0;

  cin >> H >> W;

  vector<string> s(H);
  vector<string> ans(H);
  vector<int> a(W);
  for(int i = 0; i < H; i++){
    cin >> tmp;
    // cout << "tmp length = " <<tmp.length() << endl;
    int k = 0;
    for(int j = 0; j < tmp.length(); j++){
      if(tmp[j] == '.'){
        k++;
      }
    }
    // cout << "k = " << k << endl;
    if(k != tmp.length()){
      s[i-m] = tmp;
      h++;
    }else{
      m++;       
      // cout << "all ." << endl;
    }
  }
  // cout << "------------" << endl;  
  // for(int i = 0; i < h; i++){
  //   cout << s[i]<< endl;
  // }
  // cout << "------------" << endl;  

  for(int i = 0; i < W; i++){
    int flg = 0;
    for(int j = 0; j < h; j++){
      if(s[j][i] == '.'){
        flg++;
//        cout << "flg++ in i=" << i << ", j= " << j << endl;
      }
    }
    if(flg != h){
      for(int j = 0; j < h; j++){
        ans[j] += s[j][i]; 
      }    
    }else{
  //    cout << "all . !!" << endl;
    }
  }
  for(int i = 0; i < h; i++){
    cout << ans[i] << endl;
  }

}
