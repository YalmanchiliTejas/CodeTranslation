#include <iostream>
using namespace std;

int main(){
    int x, y, z; cin >> x >> y >> z;

    int i = 0;
    while(x >= y * i + (i + 1) * z){
        i++;
    }
    cout << i - 1 << endl;
    return 0;
}
