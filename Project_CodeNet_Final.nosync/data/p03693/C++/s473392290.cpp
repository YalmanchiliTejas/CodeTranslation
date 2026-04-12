#include <stdio.h>
#include <iostream>
#include <algorithm>
#define ll longlong
using namespace std;

int main(void){
    int a, b, c;
    cin >> a >> b >> c;
    if ((100*a + 10*b + c) % 4 == 0){
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;

    return 0;
}
