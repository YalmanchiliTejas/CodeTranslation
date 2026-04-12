#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long li;

int main() {
    li a, b;
    cin >> a >> b;
    vector<vector<li>> ds(a, vector<li>(b));
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            cin >> ds[i][j];
        }
    }

    const li size = 102;
    vector<vector<li>> offset(size, vector<li>(size, -1114));
    for (int a_ = 0; a_ < a; ++a_) {
        int xc = a_ + 1;
        for (int b_ = 0; b_ < b; ++b_) {
            int yc = b_ + 1;
            int dist = ds[a_][b_];

            for (int xuse = 0; xuse < size; ++xuse) {
                for (int yuse = 0; yuse < size; ++yuse) {
                    offset[xuse][yuse] = max<li>(offset[xuse][yuse], dist - xc * xuse - yc * yuse);
                }
            }

        }
    }

    vector<vector<li>> exists(a, vector<li>(b));
    for (int xuse = 0; xuse < size; ++xuse) {
        for (int yuse = 0; yuse < size; ++yuse) {
            if (offset[xuse][yuse] < 0) {
                continue;
            }
            for (int a_ = 0; a_ < a; ++a_) {
                int xc = a_ + 1;
                for (int b_ = 0; b_ < b; ++b_) {
                    int yc = b_ + 1;
                    if (offset[xuse][yuse] + xc * xuse + yc * yuse == ds[a_][b_]) {
                        exists[a_][b_] = 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            if (not exists[i][j]) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }

    int edge_count = 220;
    for (int xuse = 0; xuse < size; ++xuse) {
        for (int yuse = 0; yuse < size; ++yuse) {
            if (offset[xuse][yuse] < 0) {
                continue;
            }
            edge_count += 1;
        }
    }

    cout << "Possible" << endl;
    cout << 221 << " " << edge_count << endl;
    for (int i = 0; i < 110; ++i) {
        cout << i + 1 << " " << i + 2 << " X" << endl;
        cout << i + 111 << " " << i + 112 << " Y" << endl;
    }
    for (int xuse = 0; xuse < size; ++xuse) {
        for (int yuse = 0; yuse < size; ++yuse) {
            if (offset[xuse][yuse] < 0) {
                continue;
            }
            cout << xuse + 1 << " " << 221 - yuse << " " << offset[xuse][yuse] << endl;
        }
    }

    cout << "1 221" << endl;
    return 0;
}