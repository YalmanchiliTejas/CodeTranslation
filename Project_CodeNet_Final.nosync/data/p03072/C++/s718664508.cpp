#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    int n, ans = 0, m = -1;
    cin >> n;
    int h[1000] = {0};
    for(int i = 0; i < n; ++i) {
        cin >> h[i];
        if (h[i] >= m){

        m = h[i];
        ans += 1;}
    }
    cout << ans << endl;
    return 0;
}