#include <iostream>
using namespace std;
int main(void){
    
    int r, g, b;
    cin >> r >> g >> b;
    
    int N = (r * 100) + (g * 10) + b;
    
    if(N % 4 == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    
}
