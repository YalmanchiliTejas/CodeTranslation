#include <iostream>

enum Station{A,B};

int main(){
  std::string s;
  std::cin >> s;

  Station station;
  if(s[0] == 'A'){
    station = A;
  }else{
    station = B;
  }

  for(int i = 1; i < 3; i++){
    switch(s[i]){
    case 'A':
      if(station == A){
        continue;
      }else{
        std::cout << "Yes" << std::endl;
        return 0;
      }
    case 'B':
      if(station == A){
        std::cout << "Yes" << std::endl;
        return 0;
      }else{
        continue;
      }
    }
  }

  std::cout << "No" << std::endl;

  return 0;
}
