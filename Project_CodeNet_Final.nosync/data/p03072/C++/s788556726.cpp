#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    int n;

    cin >> n;

    int max_num = 0;
    int h = 0;
    int cnt = 0;
    for ( int i = 0; i < n; i++ ) {
        cin >> h;
        if ( max_num <= h ) {
            cnt++;
        }
        max_num = max(h, max_num);
    }

    cout << cnt << endl;

    return 0;
}