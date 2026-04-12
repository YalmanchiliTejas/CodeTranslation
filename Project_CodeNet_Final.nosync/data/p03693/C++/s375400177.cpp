#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int r, g, b;
    cin >> r >> g >> b;
    
    int ans = r*100 + g*10 + b;
    
    cout << (ans % 4 ? "NO" : "YES") << endl;
    
    return 0;
    
    
}
