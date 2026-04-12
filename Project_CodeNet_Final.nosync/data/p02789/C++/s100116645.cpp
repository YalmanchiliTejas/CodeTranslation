#include <iostream>
using namespace std;
int main() {
    int n, m;
    string ans = "Yes";
    cin >> n >> m;
    if(n > m) ans = "No";
    cout << ans << endl;
}