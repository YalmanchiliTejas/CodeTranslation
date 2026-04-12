#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int R, G, B;
    cin >> R >> G >> B;
    
    int gb_Sum = 10*G + B;
    
    if(gb_Sum%4) cout << "NO" << endl;
    else cout << "YES" << endl;
}