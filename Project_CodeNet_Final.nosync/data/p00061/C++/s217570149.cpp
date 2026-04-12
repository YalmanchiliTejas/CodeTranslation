#include <iostream>
#include <map>

int main(int argc,char* argv[]){
  int num,score;
  char c;

  std::multimap<int,int> map;

  while(std::cin >> num >> c >> score){
    if(num == 0 && score == 0){break;} 
    map.insert(std::multimap<int,int>::value_type(score,num));
  }

  while(std::cin >> num){
    std::multimap<int,int>::reverse_iterator it = map.rbegin();
    int pre_s = -1,count = 0;
    bool end = false;
    while(it != map.rend()){
      if((*it).first != pre_s){
	pre_s = (*it).first;
	count++;
      }
      
      if((*it).second == num){
	end = true;
	break;
      }
      
      if(end){
	break;
      }

      ++it;
    }
    
    std::cout << count << std::endl;
  }
  
  
  return 0;
  
}