#include <iostream>
using namespace std;
 
int main() {
    int N, x, y, sum;
    cin >> N;
    x = 800 * N;
    y = 200 *(N / 15);
    sum = x -y;
    cout << sum << endl;
}

