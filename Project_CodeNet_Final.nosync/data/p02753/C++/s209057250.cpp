#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    string info;
    cin >> info;
    if(info == "AAA" or info == "BBB"){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}