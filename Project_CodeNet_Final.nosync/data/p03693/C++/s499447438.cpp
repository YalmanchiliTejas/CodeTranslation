#include <iostream>
using namespace std;
int main(void){
    
    int R, G, B, num;
    
    cin >> R >> G >> B;
    
    num = 10 * G + B;
    
    if (num % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
    
}