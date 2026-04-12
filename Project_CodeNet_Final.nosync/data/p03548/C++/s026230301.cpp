#include <iostream>
using namespace std;


int main()
{ 
    int x,y,z;
    cin >> x >> y >> z;
    x -= z;
    int count = 0;
    while(true) {
        int tmp = y + z;
        if (x - tmp >= 0) {
            x -= tmp;
            count++;
            continue;
        }
        break;
    }
    cout << count << endl;
    return 0;
}