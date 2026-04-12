#include <iostream>
using namespace std;

int main()
{
    int x,y,z;
    cin >> x >> y >> z;

    int w = z + y,ans = 0;
    for(int i = 0; x > w; i++){
        if(w + z > x) break;
        w += z + y;
        ans++;
    }

    cout << ans << endl;

    return 0;
}