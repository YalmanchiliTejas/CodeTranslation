#include <iostream>
#include <string>
using namespace std;

int main() {
  string str ;
  cin >> str ;
  int AC = str.find("AC");
  if (AC >= 0){
    cout << "Yes" << endl;
  }
else
{
  cout << "No" << endl;
}

}
