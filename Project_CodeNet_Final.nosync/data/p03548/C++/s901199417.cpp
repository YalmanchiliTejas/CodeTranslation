#include <iostream>
using namespace std;
int main()
{
    int x, y, z, qaq, ans;
    cin >> x >> y >> z;
    qaq = z;
    while(qaq + y + z <= x){
        qaq += y + z;
        ans ++;
    }
    cout << ans;
    return 0;
}