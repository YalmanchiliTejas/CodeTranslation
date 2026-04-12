    #include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;

int main() {
    int h, w;
    cin >> h >> w;

    char s[1010][1010];
    vector<pair<int, int> > b;
    for (int i = 0; i < h; i++) {
        cin >> s[i];
        for (int j = 0; j < w; j++) {
            if (s[i][j] == 'B') b.emplace_back(i, j);
        }
    }

    int far = 0, far_i, far_j;
    for (int i = 0; i < b.size(); i++) {
        if (abs(h / 2 - b[i].first) + abs(w / 2 - b[i].second) > far) {
            far = abs(h / 2 - b[i].first) + abs(w / 2 - b[i].second);
            far_i = b[i].first;
            far_j = b[i].second;
        }
    }

    //cout << far_i << " " << far_j << endl;

    int ans = 0;
    for (int i = 0; i < b.size(); i++) {
        ans = max(ans, abs(far_i - b[i].first) + abs(far_j - b[i].second));
    }

    cout << ans << endl;

}
