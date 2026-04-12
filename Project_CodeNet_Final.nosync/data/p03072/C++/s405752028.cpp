#include <iostream>
using namespace std;

int main()
{
    int n, hi, h_max = 0, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> hi;
        if(hi >= h_max){
            h_max = hi;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}