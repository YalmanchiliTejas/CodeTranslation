#include <iostream>
using namespace std;

int main(void) {
    int X,Y,Z; cin >> X >> Y >> Z;
    int i = 1;
    int result;
    while (Y * i + Z * (i + 1) <= X) {
        result = i;
        i++;
    }
    cout << result << endl;
    return 0;
}