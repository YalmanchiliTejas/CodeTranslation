#include <iostream>
using namespace std;
int main(void){

    int r , g , b , n;
    cin >> r >> g >> b;
    
    n = 100 * r + 10 * g + b;
    
    if(n % 4 != 0){
        cout << "NO";
    }
    
    else
        cout << " YES";

}
