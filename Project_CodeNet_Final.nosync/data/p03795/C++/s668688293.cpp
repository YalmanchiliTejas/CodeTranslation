#include <iostream>
using namespace std;

int main()
{
    int n;
    int answer;
    cin >> n;
    if (n < 15) {
        answer = n * 800;
    } else if (n >= 15) {
        int temp = n / 15;
        answer = n * 800 - temp * 200;
    }
    cout << answer << endl;
    return 0;
}
