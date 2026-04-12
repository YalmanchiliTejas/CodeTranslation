#include <iostream>
 
int main(void){
  std::string s;
  std::cin >> s;
  int flag = 0;
  for(int i = 0; i < 3 && flag == 0; i++){
  	for(int j = i + 1; j < 3 && flag == 0; j++){
      if(s[i] != s[j])
        flag = 1;
    }
  }
  if(flag == 1){
    std::cout << "Yes";
  }else{
    std::cout << "No";
  }
  return 0;
}