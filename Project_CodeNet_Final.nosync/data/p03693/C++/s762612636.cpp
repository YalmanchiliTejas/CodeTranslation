#include <iostream>
using namespace std;

int main(void) {
    
    int r,g,b,a;
    cin >> r >> g >> b;
    a = (r*100) + (g*10) + (b);
    if(a % 4 == 0){cout << "YES" << "\n";}
    if(a % 4 != 0){cout << "NO" << "\n";}
    
    return 0;
}
