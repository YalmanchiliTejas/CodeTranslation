#include <iostream>
using namespace std;
 
int main() {
    int r,g,b;
    int res;
    cin >> r >> g >> b;
    
    res = 100*r + 10*g + b;
    
    if(res % 4 ==0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    
    return 0;
}