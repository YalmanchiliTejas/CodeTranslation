#include <iostream>  
#include <string.h> 
using namespace std;
int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int w = x * 100 + y * 10 + z;
    if (w % 4 == 0)
        cout << "YES";
    else
        cout << "NO";

    
    return 0;
}

