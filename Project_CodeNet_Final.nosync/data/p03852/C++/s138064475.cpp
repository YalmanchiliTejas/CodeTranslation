#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
int main()
{
  string c;
  cin >> c;
  string target_list = "aiueo";
  if(target_list.find(c) != string::npos){
    cout << "vowel" << endl;
  }else{
    cout << "consonant" << endl;
  }

  return 0;
}
