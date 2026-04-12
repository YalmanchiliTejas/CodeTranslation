#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int r, g, b;
    int num;
    
    
    
    cin >> r >> g >> b;
    
    num = (100*r + 10*g + 1*b);
    
    if(num % 4 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    
    return 0;
}
