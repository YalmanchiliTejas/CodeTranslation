#include <iostream>
using namespace std;
int main(void){
    int x, y, z;
    int i;
    int cnt = 0;
    
    cin >> x >> y >> z;
    
    i = z;
    while(x >= i){
        i += y + z;
        if(i <= x)   cnt++;
    }
    
    cout << cnt << endl;
    
    return 0;
}
