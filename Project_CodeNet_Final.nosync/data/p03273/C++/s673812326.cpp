/*
  author: ruruvuvu
  GitHub account: colon-ku

  created at: 2020-01-04 13:03:41
*/

#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define rep(x, y) for (int x = 0; x < y; x++)
#define MOD 1000000007

typedef long long LL;
typedef long double LD;

bool compare_by_b(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

ostringstream oss_global;
string s_global = oss_global.str();

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i = 0; i < h; i++)
        cin >> a[i];

    vector<int> row(h, 0), col(w, 0);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] == '#') {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        if (row[i]) {
            for (int j = 0; j < w; j++) {
                if (col[j]) {
                    cout << a[i][j];
                }
            }

            cout << endl;
        }
    }

    return 0;
}
