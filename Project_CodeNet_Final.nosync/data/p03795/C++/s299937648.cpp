#include <iostream>
#include <string>
#include <vector>
typedef unsigned int UINT;
using namespace std;
int main(void) {
    int N;
    cin >> N;
    int ans = N * 800 - (N / 15 * 200);

    cout << ans << endl;

}