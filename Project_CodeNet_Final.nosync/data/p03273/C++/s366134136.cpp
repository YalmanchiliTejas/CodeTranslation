#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector< vector<char> > a(h, vector<char>(w));
    vector<int> mh(h, 0);
    vector<int> mw(w, 0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
            if (a[i][j] == '#') {
                mh[i] = 1;
                mw[j] = 1;
            }
        }
    }

    for (int i = 0; i < h; ++i) {
        if (mh[i] == 0) continue;
        for (int j = 0; j < w; ++j) {
            if (mw[j] == 0) continue;
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}
