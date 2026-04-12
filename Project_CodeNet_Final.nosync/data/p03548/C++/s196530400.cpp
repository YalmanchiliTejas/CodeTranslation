#include <iostream>
#include <string>
using namespace std;
int main()
{
    long x, y, z;
    cin >> x >> y >> z;
    int answer;
    answer = (x - z) / (y + z);
    cout << answer << endl;
    return 0;
}
