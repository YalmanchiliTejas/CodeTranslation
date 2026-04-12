#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>


using namespace std;


int main(void){
  
  string s,ans="No";

  cin >> s;
  
    if(s[0]!=s[1]){
      ans ="Yes";
    }
    if(s[2]!=s[1]){
      ans ="Yes";
    }

 
  cout << ans << endl;

  return 0;
}

