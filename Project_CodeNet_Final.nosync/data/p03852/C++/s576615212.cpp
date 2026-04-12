#include<bits/stdc++.h>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
  string c; cin >> c;
  if(c == "a" || c == "i" || c == "u" || c == "e" || c == "o"){
    cout << "vowel" << endl;
  } else {
    cout << "consonant" << endl;
  }
}