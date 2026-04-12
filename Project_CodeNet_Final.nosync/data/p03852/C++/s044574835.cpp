#include<iostream>
#include<set>
using namespace std;

int main(){
  set<char> s{'a', 'i', 'u', 'e', 'o'};
  char ch;
  cin >> ch;
  
  set<char>::iterator it = s.find(ch);
  if (it == s.end())
    cout << "consonant" << endl;
  else 
    cout << "vowel" << endl;
  
  return 0;
}
