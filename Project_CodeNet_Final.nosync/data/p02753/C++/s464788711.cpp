#include<iostream>
using namespace std;

int main()
{
  string str;
  cin >> str;
  char ch = str[0];
  for(int i=1;i<str.size();i++){
    if(ch != str[i]){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}