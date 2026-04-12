#include <iostream>
#include <vector>

using namespace std;

void print_vec2(vector<string>& vec){
  std::cout << vec.size() << '\n';
  std::cout << vec[0].size() << '\n';
  for(int i=0; i<vec.size(); i++){
    for(int j=0; j<vec[0].size(); j++){
      std::cout << vec[i][j];
    }
    std::cout << '\n';
  }
}

int main(){
  int h, w;
  std::cin >> h >> w;
  vector<string> a;
  for(int i=0; i<h; i++){
    string col_elm;
    std::cin >> col_elm;
    a.push_back(col_elm);
  }

  vector<string> middle_ans;
  for(int i=0; i<h; i++){
    bool addflag = false;
    for(int j=0; j<w; j++){
      if( a[i][j] == '#' ) addflag = true;
    }
    if( addflag ) middle_ans.push_back(a[i]);
  }

  vector<bool> show_flags(middle_ans[0].size(), false);
  for(int i=0; i<middle_ans[0].size(); i++){
    for (int j=0; j<middle_ans.size(); j++) {
      if( middle_ans[j][i] == '#' ){
        show_flags[i] = true;
        break;
      }
    }
  }

  for(int i=0; i<middle_ans.size(); i++){
    for (int j=0; j<middle_ans[0].size(); j++) {
      if(show_flags[j]) std::cout << middle_ans[i][j];
    }
    std::cout << '\n';
  }

  return 0;
}
