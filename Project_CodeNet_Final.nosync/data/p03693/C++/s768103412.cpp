#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int _, a, b;
    cin >> _ >> a >> b;
    if ((a * 10 + b) % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}