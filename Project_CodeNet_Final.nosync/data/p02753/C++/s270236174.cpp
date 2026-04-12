#include <iostream>
using namespace std;
int main(){
  string A;
  cin >> A;
  if(A != "AAA"){
       if(A != "BBB"){
          cout << "Yes" << endl;
      }else{
          cout << "No" << endl;
      }
  }else{
      cout << "No" << endl;
  }
}
