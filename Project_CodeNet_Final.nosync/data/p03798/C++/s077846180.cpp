#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool check(bool, bool, bool, char);

int main(){
  /*
  ifstream fin("07.txt");
  if(!fin){
    cout << "file not found" << endl;
    return 0;
  }
  */

  int n; cin >> n;
  string s; cin >> s;

  bool animals[n]; //true:S, false:W

  bool flag = false;
  for(int i=0; i<4; i++){
    animals[0] = (i>>1)&1;
    animals[1] = i&1;

    for(int j=2; j<n; j++){
      if(s[j-1]=='o'){
        if(animals[j-1]){
          animals[j] = animals[j-2];
        }
        else{
          animals[j] = !animals[j-2];
        }
      }
      else if(s[j-1]=='x'){
        if(animals[j-1]){
          animals[j] = !animals[j-2];
        }
        else{
          animals[j] = animals[j-2];
        }
      }
    }

    //チェック
    bool ch=check(animals[n-2], animals[n-1], animals[0], s[n-1])
              && check(animals[n-1], animals[0], animals[1], s[0]);

    if(ch){
      flag = true;
      break;
    }
  }

  if(flag){
    for(int i=0; i<n; i++){
      if(animals[i]) cout << "S";
      else if(!animals[i]) cout << "W";
    }
    cout << endl;
  }
  else{
    cout << -1 << endl;
  }

  return 0;
}

bool check(bool before, bool now, bool next, char c){
  if(c=='o'){
    if(now) return before==next;
    else return before!=next;
  }
  else{
    if(now) return before!=next;
    else return before==next;
  }
}
