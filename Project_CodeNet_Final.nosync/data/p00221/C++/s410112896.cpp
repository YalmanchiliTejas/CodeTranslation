#include <iostream>
#include <cstdio>

static const int P_MAX = 1000;
bool outed[P_MAX];
char buf[100];

int main(int argc, char* argv[]){
  while(true){
    int n, m;
    
    std::cin >> n >> m;
    
    if(n == 0 && m == 0){
      break;
    }
    
    for(int i = 0; i < n; i++){
      outed[i] = false;
    }
    
    int player = 0;
    int outed_count = 0;
    for(int i = 1; i < (m + 1); i++){
      if(outed_count < (n - 1) && outed[player]){
        while(outed[player]){
          player = (player + 1) % n;
        }
      }
      
      
      std::string str;
      std::cin >> str;
      
      if(outed_count >= (n - 1)){
        continue;
      }
      
      std::sprintf(buf,"%d", i);
      std::string fizzbuzz(i % 15 == 0 ? "FizzBuzz"
                                       : i % 5 == 0 ? "Buzz"
                                                    : i % 3 == 0 ? "Fizz"
                                                                 : buf);
      if(str != fizzbuzz){
        //std::cout << str << " " << player << std::endl;
        outed[player] = true;
        outed_count++;
      }
      
      player = (player + 1) % n;
    }
    
    bool first = true;
    for(int i = 0; i < n; i++){
      if(outed[i]){
        continue;
      }
      std::sprintf(buf,first ? "%d" : " %d", i + 1);
      std::cout << buf;
      if(first){first = false;}
    }
    std::cout << std::endl;
    
  }
  
  return 0;
}