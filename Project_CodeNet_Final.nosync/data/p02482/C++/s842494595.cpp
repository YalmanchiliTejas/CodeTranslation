#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[])
{
    int a, b;
    cin >> a >> b;
    if (a < b) {
        cout << "a < b" << endl;
    }
    else if (a > b){
        cout << "a > b" << endl;
    }
    else{
        cout << "a == b" << endl;
    }
    return 0;
}