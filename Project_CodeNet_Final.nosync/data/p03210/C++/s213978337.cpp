#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <utility>
#include <set>
#include <numeric>
#include <queue>
using namespace std;
using LLI = long long int;

#define Rep(i, N) for (int i = 0; i < N; i++)

int main(int argc, char *argv[])
{
    int X;
    cin >> X;

    switch (X)
    {
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