#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int back = 0;
    back = N/15;
    
    cout << N*800-back*200 << endl;
}
