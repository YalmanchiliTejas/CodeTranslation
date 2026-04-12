#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int x;
    int y;
    x = N * 800;
    N = N - N % 15;
    N = N / 15;
    y = N * 200;
    cout << x - y << endl;
	return 0;
}