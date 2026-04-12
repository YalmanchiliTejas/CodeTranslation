#include <iostream>
using namespace std;
int main() {
    int n, h, max=0, cnt=0;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> h;
        if(max<=h) {
            max = h;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}