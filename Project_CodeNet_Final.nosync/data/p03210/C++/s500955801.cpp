#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>  // min, max
#include <fstream>  // ifstream
#include <iomanip>  // setprecision
using namespace std;
typedef long long ll;

int main(void)
{
#ifdef FILE_DEBUG
    ifstream inputFile("data/input.txt");
    cin.rdbuf(inputFile.rdbuf());
#endif
    // これより下にコードを書く

    int D;
    cin >> D;

    switch (D) {
        case 7:
        case 5:
        case 3:
            cout << "YES" << endl;
            break;
        default:
            cout << "NO" << endl;
            break;
    }

    return 0;
}
