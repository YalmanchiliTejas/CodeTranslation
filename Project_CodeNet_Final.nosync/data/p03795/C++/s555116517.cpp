#include <iostream>
#include <vector>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
using ll = long long;
using namespace std;

int main() {
    int x;
    cin >> x;

    int y = 0;
    int c = x;


    while(c >= 15) {
            y += 200;
            c -= 15;
    }

    cout << x*800 - y << endl;

    

    return 0;
}