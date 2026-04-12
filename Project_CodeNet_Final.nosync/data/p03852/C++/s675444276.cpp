#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#define div 1000000000+7
using namespace std;
typedef long long ll;

int main(){
    string s ;
    cin >> s;
    if(s == "a" || s == "i" || s == "u" || s == "e" || s == "o"){
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
    return 0;
}
