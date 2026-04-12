#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    ans += n*800;
    int m = n/15;
    ans -= m*200;
    cout << ans << "\n";

    return 0;
}
