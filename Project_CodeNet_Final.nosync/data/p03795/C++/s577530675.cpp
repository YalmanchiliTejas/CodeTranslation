#include <algorithm>
#include <bitset>
#include <iomanip>
#include <ios>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    cout << 800 * N - 200 * (N / 15) << "\n";
}