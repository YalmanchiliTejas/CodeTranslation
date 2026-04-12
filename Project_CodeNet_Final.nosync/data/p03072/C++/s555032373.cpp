#include <iostream>
using namespace std;
int main()
{
    int n, h, h_max = 0, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> h;
        if(h_max <= h){
            h_max = h;
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}