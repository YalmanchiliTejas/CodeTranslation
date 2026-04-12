#include <iostream>
#include <string>
using namespace std;

string a = "aiueo";

int main() {
    char b;
    cin >> b;
    bool flag = false;
    for(int i=0; i<5; i++){
      if(b == a[i]) flag = true;
    }
    
    if(flag) cout << "vowel" <<endl;
    else cout << "consonant" <<endl;
}