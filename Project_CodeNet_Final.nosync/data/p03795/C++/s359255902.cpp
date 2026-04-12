#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n, ans;
    
    cin >> n;
    ans = n*800-(n/15)*200;
    cout << ans << endl;
    
    return 0;
}
