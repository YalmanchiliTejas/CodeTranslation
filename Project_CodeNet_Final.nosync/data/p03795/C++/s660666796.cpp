#include <iostream>
#include <vector>
#include <algorithm>
// #include <string>
// #include <map>
// #include <set>
// #include <cmath>


using namespace std;

int main(int argc, char const *argv[]) {
    int N;
    cin >> N;
    int x = N * 800;
    int y = (N / 15) * 200;
    cout << x - y << endl;
    return 0;
}
