#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int ans = 800*N - 200*(N/15);
    cout << ans << endl;
    return 0;
}