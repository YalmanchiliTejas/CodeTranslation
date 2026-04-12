#include<iostream>
#include<cstring>
#include<vector>
#include<cstdlib>
using namespace std;

int main(int argc, char *argv[]){
  string s;
  int n;
  cin >> s >> n;
  int LtoR = atoi(&s[0]), correct = 0;
  for (int i = 1; i < s.length(); i+=2) {
    if(s[i] == '+'){
      LtoR += atoi(&s[i + 1]);
    }else{
      LtoR *= atoi(&s[i + 1]);
    }
  }
  vector<int> remove_mal;
  remove_mal.push_back(atoi(&s[0]));
  for (int i = 1; i < s.length(); i+=2) {
    if(s[i] == '*'){
      remove_mal[remove_mal.size() - 1] *= atoi(&s[i + 1]);
    }else{
      remove_mal.push_back(atoi(&s[i + 1]));
    }
  }
  for (int i:remove_mal){
    //    std::cout << i << std::endl;
    correct += i;
  }
  if(LtoR == correct && correct == n){
    std::cout << "U" << std::endl;
  }else if(LtoR == n){
    std::cout << "L" << std::endl;
  }else if(correct == n){
    std::cout << "M" << std::endl;
  }else{
    std::cout << "I" << std::endl;
  }
   // std::cout << "LtoR:   " << LtoR    << std::endl;
   // std::cout << "correct:" << correct << std::endl;
  return 0;
}