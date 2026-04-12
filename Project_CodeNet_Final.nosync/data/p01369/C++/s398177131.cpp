#include <iostream>
#include <set>
using namespace std;

int main(void){
  set<char> right;
  const string right_hand = "yuiophjklnm";
  for(size_t i = 0; i < right_hand.length(); i++)
    right.insert(right_hand[i]);

  while(true){
    string input;
    cin >> input;
    if(input == "#"){ break; }

    int count = 0;
    bool flag = true;
    for(size_t i = 0; i < input.length(); i++){
      bool now = right.count(input[i]);
      if(i != 0 && flag != now){ ++count; }
      flag = now;
    }
    cout << count << endl;
  }
  
  return 0;
}