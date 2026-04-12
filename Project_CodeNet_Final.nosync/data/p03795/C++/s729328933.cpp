#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n;
    cin >> n;
    int ans = n * 800;
    ans -= n / 15 * 200;
    cout << ans << endl;
}
