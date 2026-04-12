#include <iostream>
using namespace std;


int main(){
  string ch;
  cin >> ch;

  for(int i=0; ch[i+1]; i++){
    if(ch[i] == 'A' && ch[i+1] == 'C'){
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}
