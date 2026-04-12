#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> shop(5);
    int am, pm;
    while (cin >> am >> pm) {
        if (am == 0 && pm == 0) break;
        shop.clear();
        shop[0] = am + pm;
        for (int i = 1; i < 5; i++) {
            cin >> am >> pm;
            shop[i] = am + pm;
        }
        int max_sum = 0;
        char max_shop = 'A';
        for (int i = 0; i < 5; i++) {
            if (max_sum < shop[i]) {
                max_sum = shop[i];
                max_shop = 'A' + i;
            }
        }
        cout << max_shop << ' ' << max_sum << endl;
        //cout << (char)(shop_i - shop.begin() + 'A') << *shop_i << endl;
    }
    return 0;
}