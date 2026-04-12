#include <iostream>

using namespace std;

int main(){

    int x, y, z;
    cin >> x >> y >> z;

    x -= z;



    int res = x / (y + z);

    cout << res << endl;



    return 0;
}