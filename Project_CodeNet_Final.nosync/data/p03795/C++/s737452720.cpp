#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <string>
#include <algorithm>
#include <cmath>

typedef long long ll;

using namespace std;

int main()
{
    int n; cin >> n;

    if (n >= 15){
        cout << 800 * n - 200 * (n / 15) << endl;
    }
    else
    {
        cout << 800 * n << endl;
    }
    return 0;
}