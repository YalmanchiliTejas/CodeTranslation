#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
int main(){
  int a = 0, b = 0;
  std::string sta;
  cin >> sta;
  for(int i = 0; i < sta.size(); i++){
    if(sta.at(i) == 'A'){
      a++;
    }
    else if(sta.at(i) == 'B'){
      b++;
    }
  }
  if(a != 0  && b != 0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}