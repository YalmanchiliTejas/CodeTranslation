#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;

int main(void) {
    int a, b;
    
    cin >> a >> b;
    
    if(a > b)
        cout << "a > b" << endl;
    else if(a == b)
        cout << "a == b" << endl;
    else
        cout << "a < b" << endl;
    
    return (0);
}