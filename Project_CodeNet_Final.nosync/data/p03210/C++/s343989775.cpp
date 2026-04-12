
#include <iostream>

using namespace std;

int main() {
    int X ;
    cin >> X;
    if (X <= 9 && X >= 1 && X%2 == 1 && X !=9 && X != 1) {
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    
    return 0;
}

