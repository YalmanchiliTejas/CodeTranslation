#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
 
using namespace std;
 
int main(){
    char c;
    
    cin >> c;

    bool flag = false;
    if(c == 'a') flag = true;
    else if(c == 'i') flag = true;
    else if(c == 'u') flag = true;
    else if(c == 'e') flag = true;
    else if(c == 'o') flag = true;

    if(flag) cout << "vowel" << endl;
    else cout << "consonant" << endl;

    return 0;
}