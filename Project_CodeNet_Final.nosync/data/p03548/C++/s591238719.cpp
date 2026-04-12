#include <iostream>
using namespace std;

int main(void){
    int x, y, z;
    cin >> x >> y >> z;
    
    x -= z;
    int cnt = 0;
    
    while(x >= y + z){
        x -= y + z;
        cnt++;
    }
    
    cout << cnt << endl;
    
    return 0;
}
