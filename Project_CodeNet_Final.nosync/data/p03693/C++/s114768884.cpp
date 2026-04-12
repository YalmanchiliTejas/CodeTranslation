#include <sstream>
#include <string>
#include <iostream>
using namespace std;

int main () {
    int a, b, c;
    cin >> a >> b >> c;
    bool s = (a * 100 + b * 10 + c) % 4 == 0;
    if (s==true){
        cout << "YES" << endl;
    }
    else if (s==false){
        cout << "NO" << endl;
    }
}