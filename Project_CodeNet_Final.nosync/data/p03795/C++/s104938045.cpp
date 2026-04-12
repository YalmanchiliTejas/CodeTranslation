#include <iostream>
using namespace std;
int main (void) {
    int N;

    cin >> N;

    int x = N * 800;
    int y = N / 15 * 200;

    cout << x - y << endl;
    
    return 0;
}