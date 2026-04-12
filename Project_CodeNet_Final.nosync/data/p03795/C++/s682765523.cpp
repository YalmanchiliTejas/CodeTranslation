#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    int ans = 800 * N - 200 * (N / 15);
    cout << ans << endl;
    return 0;
}