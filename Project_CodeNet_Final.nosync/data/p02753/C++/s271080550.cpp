#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cctype>

using namespace std;

int main()
{
    string str;
    cin >> str;

    if(str[0] == str[1] && str[1] == str[2]){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    return 0;
}