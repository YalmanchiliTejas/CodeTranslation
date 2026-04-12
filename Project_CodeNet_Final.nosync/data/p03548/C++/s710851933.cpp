#include <iostream>
using namespace std;

int main(){
    int x, y, z, i; cin >> x >> y >> z;
    for(i = 1; x >= y*i + z*(i+1); i++);
    cout << i-1 << endl;
    return 0;
}
