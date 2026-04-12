
#include <iostream>

using namespace std;

int main(void)
{
    
    
    int array[3];
    int num = 0;
    
    for (int i = 0; i < 3; i++) {
        
        cin >> array[i];
        
    }
    
    for (int i = 0, j = 100; i < 3; i++, j /= 10) {
        
        num += array[i] * j;
        
    }
    
    if (num % 4 == 0) {
        
        cout << "YES" << endl;
        
    }
    else {
        
        cout << "NO" << endl;
        
    }
    
    
    
    
    return 0;
    
}