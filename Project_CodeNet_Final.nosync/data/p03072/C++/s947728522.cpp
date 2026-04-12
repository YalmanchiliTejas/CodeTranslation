#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int m = 0;
    int ans = 0;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        if(t >= m) ans++;
        m = max(m, t);
    }
    cout << ans << endl;
    return 0;
}