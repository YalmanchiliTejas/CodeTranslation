#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>

using namespace std;

#define ll long long

int main(void){
    string s;
    cin >> s;

    if(s[0] == s[1] && s[1] == s[2]){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }

    return 0;
}