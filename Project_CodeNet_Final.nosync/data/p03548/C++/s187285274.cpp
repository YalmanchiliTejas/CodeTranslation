#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{

    int x, y, z;
    cin >> x >> y >> z;
    int ans = 0;
    x -= z;

    cout << x / (y + z) << endl;
    return 0;
}
