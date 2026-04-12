#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void){
    int X;
    cin >> X;
    if(X == 7 || X == 5 || X == 3){
        cout << "YES";
    } else {
        cout << "NO";
    }
    return EXIT_SUCCESS;
}