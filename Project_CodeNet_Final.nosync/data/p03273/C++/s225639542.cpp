#include<bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>> a(h,vector<char> (w));

  for(int i = 0;i < h;i++){
    for(int j = 0;j < w;j++){
      cin >> a.at(i).at(j);
    }   
  }

  
  vector<int> cntH(h),cntW(w);
  int k = 0;
  for(int i = 0;i < h;i++){
    for(int j = 0;j < w;j++){
      if(a.at(i).at(j) == '#'){
        cntH.at(k) = i;
        k++;
        break;
      }   
    }   
  }
  
  int m = 0;
  for(int i = 0;i < w;i++){
    for(int j = 0;j < h;j++){
      if(a.at(j).at(i) == '#'){
        cntW.at(m) = i;
        m++;
        break;
      }   
    }   
  }

  for(int i = 0;i < k;i++){
    for(int j = 0;j < m;j++){
      cout << a.at(cntH.at(i)).at(cntW.at(j));
    }   
    cout << endl;
  }
  return 0;
 }