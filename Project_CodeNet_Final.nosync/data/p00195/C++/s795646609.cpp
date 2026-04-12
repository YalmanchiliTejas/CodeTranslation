#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

typedef pair<int, char> P;

int main()
{
    int s1, s2;
    vector<P> shop(5);
    while(cin >> s1 >> s2 && s1 && s2) {
        shop[0] = P(s1 + s2, 'A');
        for(int i = 1; i < 5; i ++) {
            cin >> s1 >> s2;
            shop[i] = P(s1 + s2, 'A' + i);
        }

        sort(shop.begin(), shop.end());
        cout << shop[4].second << " " << shop[4].first << endl;
    }
    return 0;
}