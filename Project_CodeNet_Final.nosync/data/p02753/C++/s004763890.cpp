#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
string ans;

int main() {
    cin >> ans;
    if (ans[0] == ans[1] && ans[0] == ans[2]){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}