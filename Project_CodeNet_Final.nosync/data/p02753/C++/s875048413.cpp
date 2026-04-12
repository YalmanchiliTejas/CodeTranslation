#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;


int main()
{
    string S;
    cin >> S;
    
    bool flag = false;
    if (S != "AAA" && S != "BBB") {
        flag = true;
    }

    if (flag) {
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}