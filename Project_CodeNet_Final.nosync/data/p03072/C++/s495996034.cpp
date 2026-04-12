#include <iostream>
using namespace std;

int main() {
    int n, h, h_max, r;
    cin >> n;
    for(auto i = 0; i != n; ++i) {
        cin >> h;
        if(i == 0)
        {
            h_max = h;
            r = 1;
        }
        else {
            if(h >= h_max) {
                ++r;
                h_max = h;
            }
        }
    }
    cout << r << endl;

    return 0;
}
