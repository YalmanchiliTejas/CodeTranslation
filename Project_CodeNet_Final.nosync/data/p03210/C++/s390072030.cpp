#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int x;
    cin >> x;
    
    if(x == 7 or x == 5 or x == 3) {
        cout << "YES";
    }else{
        cout << "NO";
    }
    cout << endl;
    return 0;
}