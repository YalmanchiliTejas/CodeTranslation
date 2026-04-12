#include<iostream>
using namespace std;
int x, y, z, qaq, ans;
int main()
{
    cin >> x >> y >> z;
qaq = z;
    while(qaq + y + z <= x){
        qaq += y + z; 
        ans ++;
    }
    cout << ans <<endl;
    return 0;
}