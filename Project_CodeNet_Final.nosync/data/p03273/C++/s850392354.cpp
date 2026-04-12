#include <iostream>
using namespace std;
int main(void){
  int h,w;
  int kesu_width_kazu = 0;
  int kesu_height_kazu = 0;

  cin >> h >> w;
  int kesu_height[h];
  int kesu_width[w];
  string str[h];
  for(int i = 0; h > i; i++){
    cin >> str[i];
  }
  //横から
  for(int i = 0; h > i; i++){
    bool kesu = true;
    for(int j = 0; w > j; j++){
      if(str[i].at(j) == '#'){
        kesu = false;
        break;
      }
    }
    if(kesu){
      kesu_height[kesu_height_kazu] = i;
      kesu_height_kazu++;
    }
  }
  //縦から
  for(int i = 0; w > i; i++){
    bool kesu = true;
    for(int j = 0; h > j; j++){
      if(str[j].at(i) == '#'){
        kesu = false;
        break;
      }
    }
    if(kesu){
      kesu_width[kesu_width_kazu] = i;
      kesu_width_kazu++;
    }
  }
  for(int i = 0; h > i; i++){
    bool continu = false;
    for(int j = 0; kesu_height_kazu > j; j++){
      if(kesu_height[j] == i){
        continu = true;
      }
    }
    if(continu) continue;
    for(int j = 0; w > j; j++){
      continu = false;
      for(int k = 0; kesu_width_kazu > k; k++){
        if(kesu_width[k] == j) continu = true;
      }
      if(continu) continue;
      cout << str[i].at(j);
    }
    cout << endl;
  }
  return 0;
}