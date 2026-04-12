#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]){

  string S;
  cin >> S;
  int length = S.length();
  for(int i = 0; i < length-1; i++){
    if(S[i] == 'A'){
      if(S[i+1] == 'C'){
        // success
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
