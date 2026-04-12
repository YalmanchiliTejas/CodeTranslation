#include <iostream>

using namespace std;

int main(void)
{
    long long x, y, z, ans=1;

    cin >> x >> y >> z;

    while(ans*y+(ans+1)*z <= x){
        ans++;
    }
    
    ans--;

    cout << ans << endl;

    return 0;
}