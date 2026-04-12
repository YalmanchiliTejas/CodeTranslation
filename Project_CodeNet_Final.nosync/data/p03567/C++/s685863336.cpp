#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <functional>

using namespace std;

int main() {
    string n;
    
    cin >> n;

    if(n.find("AC") != string::npos){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    
  return 0;
  
}
