#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(){
  int H, W;
  std::cin>>H>>W;
  std::vector<std::string> a(H);

  for(auto i = a.begin();i != a.end();i++){
    std::cin>>*i;
  }

  std::vector<bool> row(H, false);
  std::vector<bool> col(W, false);
  for(int i = 0;i < H;i++){
    for(int j = 0; j < W;j++){
      if(a[i][j] == '#'){
        row[i] = true;
        col[j] = true;
      }
    }
  }
  for(int i = 0;i < H;i++){
    if(row[i]){
      for(int j = 0;j < W;j++){
        if(col[j]){
          std::cout<<a[i][j];
        }
      }
      std::cout<<std::endl;
    }
  }
  return 0;
}