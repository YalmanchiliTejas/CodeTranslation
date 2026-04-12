#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>

typedef long long ll;
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 3 || n == 5 || n == 7) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
